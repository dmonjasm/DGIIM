#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char * argv[]){
    if(argc < 4){
        printf("Modo de ejecución: <programa> \"<\" ó \">\" <nombre_archivo>\n");
        exit(EXIT_FAILURE);
    }

    int fd;
    char * programa = argv[1];
    char * direccion= argv[2];
    char * archivo=argv[3];

    if(strcmp(direccion, "<")== 0){
        close(STDIN_FILENO);

        if((fd=open(archivo, O_CREAT|O_RDONLY, S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)) < 0){
        perror("Error en el open\n");
        exit(EXIT_FAILURE);
        }

        if(fcntl(fd, F_DUPFD, STDIN_FILENO) == -1 ){
            perror("Fallo en fcntl");
            exit(EXIT_FAILURE);
        }

        if(execlp(programa, "", NULL) < 0){
            perror("Error exec");
            exit(EXIT_FAILURE);
        }
    }

    else{

        if(strcmp(direccion,">") == 0){
            close(STDOUT_FILENO);

            if((fd=open(archivo, O_CREAT|O_WRONLY, S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)) < 0){
                perror("Error en el open\n");
                exit(EXIT_FAILURE);
            }

            if(fcntl(fd, F_DUPFD, STDOUT_FILENO) == -1){
                perror("Fallo en fcntl");
                exit(EXIT_FAILURE);
            }

            if(execlp(programa, "", NULL) < 0){
                perror("Error exec");
                exit(EXIT_FAILURE);
            }
        }

        else{
            printf("Modo de ejecución: <programa> \"<\" ó \">\" <nombre_archivo>\n");
            exit(EXIT_FAILURE);
        }
        
    }

    return 0;

    
}