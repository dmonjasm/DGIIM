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

void SIGCHLD_handler(int signum, siginfo_t * estructura, void * argumento){
    printf("acaba de finalizar el hijo con pid-> %d", estructura->si_pid);

}
int main(int argc, char *argv[]){
    pid_t childpid;
    struct sigaction manejador;

    manejador.sa_sigaction=SIGCHLD_handler;
    manejador.sa_flags=SA_SIGINFO;
    sigemptyset(&manejador.sa_mask);

    if(sigaction(SIGCHLD,&manejador, NULL) < 0){
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    if((childpid=fork()) < 0){
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if(childpid==0){

        exit(EXIT_SUCCESS);
    }
    else{
        sleep(5);
    }

    return EXIT_SUCCESS;
}
    