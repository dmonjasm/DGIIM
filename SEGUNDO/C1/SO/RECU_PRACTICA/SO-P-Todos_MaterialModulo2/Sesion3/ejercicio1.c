#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

void mensaje_error(){
	printf("Modo de uso:<programa> <numero_entero>\n");
	exit(EXIT_FAILURE);
}


int main(int argc, char * argv[]){

if(argc < 2)
	mensaje_error();

pid_t childpid;
int entero=strtol(argv[1],NULL,10);

if((childpid=fork()) < 0){
	perror("Error en fork");
	exit(EXIT_FAILURE);
}



if(childpid==0){
	if(entero % 2 == 0)	
		printf("El numero introducido es par\n");
		
	else
		printf("El numero introducido es impar\n");
}

if(childpid!=0){
	if(entero % 4 == 0)
		printf("El numero es múltiplo de 4\n");
		
	else
		printf("El número no es múltiplo de 4\n");
}

return 0;
}


