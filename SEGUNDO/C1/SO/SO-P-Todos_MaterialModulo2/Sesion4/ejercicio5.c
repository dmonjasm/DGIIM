#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include <string.h>

int main(int argc, char * argv[]){

    if(argc != 3){
        printf("Modo de ejecucion: <programa> <extremo_inferior> <extremo_superior>\n");
        exit(EXIT_FAILURE);
    }

    pid_t childpid1, childpid2;
    int inf=strtol(argv[1],NULL, 10);
    int sup=strtol(argv[2],NULL, 10);
    int fd_esclavo1[2];
    int fd_esclavo2[2];
    int bytes_leidos;
    int media=(sup+inf)/2;
    char ini[100];
    char fin[100];
    int salida;
    int salida2;
    int wstatus;

    pipe(fd_esclavo1);
    pipe(fd_esclavo2);
    
    if((childpid1=fork()) <  0){
        printf("Error fork");
        exit(EXIT_FAILURE);
    }

    if(childpid1 == 0){
        close(fd_esclavo1[0]);
        
        dup2(fd_esclavo1[1],STDOUT_FILENO);
        sprintf(fin,"%d", media);
        if(execl("./esclavo_5", "esclavo5",argv[1], fin, NULL) < 0){
            perror("Error exec\n");
            exit(EXIT_FAILURE);
        }

        exit(EXIT_SUCCESS);

    }

    else{
        close(fd_esclavo1[1]);

        while((bytes_leidos=read(fd_esclavo1[0],&salida, sizeof(int))) > 0){
            printf("Hijo 1 %d\n", salida);
        }

        close(fd_esclavo1[0]);
    }

    if((childpid2=fork()) <  0){
        printf("Error fork");
        exit(EXIT_FAILURE);
    }

    if(childpid2 == 0){
        close(fd_esclavo2[0]);
        media++;
        dup2(fd_esclavo2[1],STDOUT_FILENO);
        sprintf(ini, "%d", media+1);
        if(execl("./esclavo_5", "esclavo5", ini, argv[2], NULL) < 0){
            perror("Error exec\n");
            exit(EXIT_FAILURE);
        }

        exit(EXIT_SUCCESS);

    }

    else{
        close(fd_esclavo2[1]);

        while((bytes_leidos=read(fd_esclavo2[0],&salida2, sizeof(int))) > 0){
            printf("Hijo 2 %d\n", salida2);
        }

        close(fd_esclavo2[0]);
    }

    return 0;
}