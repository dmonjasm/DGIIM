#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

void mensaje_error(){
	printf("Modo ejecución: <programa> <hijos>\n");
	exit(EXIT_FAILURE);
}


int main(int argc, char *argv[]){

if(argc < 2)
	mensaje_error();

pid_t childpid;
int nhijos=strtol(argv[1],NULL,10);
int wstatus;

for(int i=0; i < nhijos; i++){
	if((childpid=fork()) < 0){
		perror("Error en el fork");
		exit(EXIT_FAILURE);
	}

	if(childpid==0){
		printf("Soy el hijo %d\n", getpid());
		exit(EXIT_SUCCESS);
	}
}

while(nhijos != 0){
	childpid=wait(&wstatus);
	printf("Acaba de finalizar mi hijo con %d\n", childpid);
	nhijos--;
	printf("Sólo me quedan %d hijos vivos\n", nhijos);
	
}

return 0;
}
	
	
