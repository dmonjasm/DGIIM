#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void mensaje_error(){
	printf("Modo ejecución: <esclavo> <inferior> <superior>\n");
	exit(EXIT_FAILURE);
}

int es_primo(int numero){
	int primo=1;
	int limite=sqrt(numero);
	
	for(int i=2; i <= limite && primo; i++){
		if(numero % i==0)
			primo=0;
	}
	
	return primo;
}

int main(int argc, char * argv[]){

if(argc < 3){
	mensaje_error();
}

int inferior=strtol(argv[1],NULL,10);
int superior=strtol(argv[2],NULL,10);
int primo=0;
	
for(int i=inferior; i <= superior; i++){
	primo=es_primo(i);

	if(primo){
		if(write(STDOUT_FILENO,&i,sizeof(int)) != sizeof(int)){
			perror("Error al escribir en el cauce");
			exit(EXIT_FAILURE);
		}
	}
}

return 0;
}
	
