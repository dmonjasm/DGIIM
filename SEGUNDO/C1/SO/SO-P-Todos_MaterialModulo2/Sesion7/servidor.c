#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <signal.h>



void proxy(int fd){
    pid_t chilpid;
    int num_bytes_escritos;
    char escribir[20];
    struct sigaction handler;
    
    if((chilpid=fork()) < 0){
        perror("error en la creación del proceso proxy");
        exit(EXIT_FAILURE);
    }
    
    if(chilpid==0){
        if(execlp("proxy","proxy", NULL) < 0){
            perror("error en la ejecución de proxy");
            exit(EXIT_FAILURE);
        }

        exit(EXIT_SUCCESS);
    }

    else{
        if((num_bytes_escritos=write(fd, &chilpid , sizeof(int))) < 0){
            perror("el escribir el pid del proxy");
            exit(EXIT_FAILURE);
        }
    }
}

static void senal_handler(int signum){
    
    wait(NULL);

}

int main (int argc , char * argv[]){
    char fifo1[100]="FIFO_CONOCIDOe";
    char fifo2[100]="FIFO_CONOCIDOs";

    int error;
    int num_bytes_leidos;
    int fd_entrada;
    int fd_salida;
    int fd_bloqueo;
    char buffer[10];
    struct sigaction handler;

    handler.sa_handler=senal_handler;
    handler.sa_flags=0;

    sigaction(SIGCHLD, &handler , NULL);

    if((error=mkfifo(fifo1,0666)) < 0){
        perror("error al crear el fifo de entrada al servidor");
        exit(EXIT_FAILURE);
    }

    if((error=mkfifo(fifo2,0666)) < 0){
        perror("error al crear el fifo de salida del servidor");
    }

    if((fd_entrada=open(fifo1, O_RDWR, S_IRWXU)) < 0){
        perror("error al abrir el fifo de entrada");
        exit(EXIT_FAILURE);
    }

    if((fd_salida=open(fifo2, O_RDWR, S_IRWXU)) < 0){
        perror("error al abrir el fifo de salida");
        exit(EXIT_FAILURE);
    }

    while ((num_bytes_leidos=read(fd_entrada,buffer, sizeof(char))) != 0){
        proxy(fd_salida);
    }

    if((fd_bloqueo=open("bloqueo", O_WRONLY, S_IRWXU)) < 0){
        perror("error en la creacion del bloqueo");
        exit(EXIT_FAILURE);
    }
    
    return EXIT_SUCCESS;
    
}