#include <sys/types.h>
#include <signal.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>


static int contador[22];

void sig_hanler(int signum){
	contador[signum]++;
	printf("La señal %d se ha recibido %d veces\n", signum, contador[signum]);
}

int main(int argc ,char * argv[]){

struct sigaction manejador;

manejador.sa_handler=sig_hanler;
sigfillset(&manejador.sa_mask);
manejador.sa_flags=SA_RESTART;

printf("No puedo manejar la señal %d\n", SIGKILL);
printf("No puedo manejar la señal %d\n", SIGSTOP);
printf("Esperando el envío de señales ... \n");



for(int i=0; i < 22; i++){
	contador[i]=0;
}

for(int i=0; i < 22; i++){
	if(i!=SIGKILL && i!=SIGSTOP){
		sigaction(i,&manejador,NULL);
	}
}

while(1){
}

return 0;
}


