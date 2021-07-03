#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>

static int contador[22];
static void sig_handler(int signum){
    contador[signum-1]++;

    printf("La señal %d se ha recibido %d veces\n", signum, contador[signum-1]);


}

int main(int argc,char argv[]){

    for(int i=0; i < 22; i++){
        contador[i]=0;
    }

    struct sigaction sig_senal;

    sig_senal.sa_handler=sig_handler;
    sigemptyset(&sig_senal.sa_mask);
    sig_senal.sa_flags=0;

    for(int i=1;  i <= 22; i++){
        if(i!= 9 && i!= 19){
            if(sigaction(i,&sig_senal, NULL) < 0){
                perror("\nError al intentar establecer el manejador de senal");
                exit(EXIT_FAILURE);
            }
        }
    }

    printf("\nNo puedo manejar la señal 9\n");
    printf("\nNo puedo manejar la señal 19\n");
    printf("\nEsperando el envío de señales...\n");

    while(1){
    }

}