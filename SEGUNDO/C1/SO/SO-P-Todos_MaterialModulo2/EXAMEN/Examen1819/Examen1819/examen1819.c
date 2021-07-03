#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <signal.h>


void error(){
    printf("Modo de ejecución:lanzador <numero_clientes> <dir_pathname>");
    exit(EXIT_FAILURE);
}

void SIGCHLD_handler(int signum, siginfo_t * estructura, void * argumento){
    printf("Acaba de finalizar mi hijo con pid %d\n", estructura->si_pid);
    wait(NULL);
}
int main(int argc, char *argv[]){

    if(argc < 3){
        error();
    }

    pid_t childpid;
    char nombre_fifo[100]="FIFOpet";
    int fd_fifo;
    int numero_clientes=atoi(argv[1]);
    struct sigaction manejador;
    manejador.sa_sigaction=SIGCHLD_handler;
    manejador.sa_flags=SA_SIGINFO;

    setvbuf(stdout, NULL, _IONBF, 0);

    if(sigaction(SIGCHLD,&manejador, NULL) < 0){
        perror("sigaction");
        exit(EXIT_FAILURE);
    }
    printf("numero de clientes %d\n", numero_clientes);
    mkfifo(nombre_fifo,0666);

    if((fd_fifo=open(nombre_fifo, O_RDWR, S_IRWXU)) < 0){
        perror("error en el open");
    }

    for(int i=0; i < numero_clientes; i++){
        if((childpid=fork()) < 0){
            perror("error fork");
            exit(EXIT_FAILURE);
        }

        if(childpid==0){
            char fifo[50];
            int fifo_pid;
            sprintf(fifo, "FIFO.%d", getpid());
            mkfifo(fifo, 0666);

            if((fifo_pid=open(fifo, O_RDWR, S_IRWXU)) < 0){
                perror("error al abrir el fifo");
                exit(EXIT_FAILURE);
            }

            sleep(2);
            unlink(fifo);

            exit(EXIT_SUCCESS);
        }
    }
    
    unlink(nombre_fifo);

    return EXIT_SUCCESS;
}