#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void error(){
    printf("Modo de ejecución: <programa> <orden> \"|\" <orden> \n");
    exit(EXIT_FAILURE);
}
int main(int argc , char * argv[]){

    if(argc < 4){
        error();
    }

    if(strcmp(argv[2],"|") != 0){
        error();
    }

    int fd_salida;
    int fd_entrada;
    pid_t childpid;
    int fd[2];

    pipe(fd);

    if((childpid=fork()) < 0){
        perror("error fork");
        exit(EXIT_FAILURE);
    }

    if(childpid==0){
        close(fd[0]);

        close(STDOUT_FILENO);

        if(fcntl(fd[1],F_DUPFD, STDOUT_FILENO) < 0){
            perror("error fcntl");
            exit(EXIT_FAILURE);
        }

        if(execlp(argv[1], argv[1], NULL) < 0){
            perror("error exec");
            exit(EXIT_FAILURE);
        }
    }

    else
    {
        wait(NULL);
        close(fd[1]);
        close(STDIN_FILENO);

        if(fcntl(fd[0],F_DUPFD, STDIN_FILENO) < 0){
            perror("error exec");
            exit(EXIT_FAILURE);
        }

        if(execlp(argv[3], argv[3], NULL) < 0){
            perror("error exec");
            exit(EXIT_FAILURE);
        }
    }
    

    

    return 0;
}