#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

void mensaje_error(){
	printf("Modo ejecución: <programa> <pathname_programa_ejecutar> <argumentos_programa> <bg_opcional>");
	exit(EXIT_FAILURE);
}

int main(int argc, char * argv[]){

if(argc < 2){
	mensaje_error();
}

pid_t childpid;
int estado;

if(strcmp("bg",argv[argc-1]) != 0){
	if(argc < 3){
		if(execl(argv[1],argv[1],NULL) < 0){
			perror("error execl foreground");
			exit(EXIT_FAILURE);
		}
	}	
	
	else{
		char * argumentos[argc-1];
		for(int i=0; i < argc-1; i++){
			argumentos[i]=argv[i+1];
		}

		if(execv(argv[1],argumentos) < 0){
			perror("error execv foreground");
			exit(EXIT_FAILURE);
		}
	}
}

else{
	if(argc < 4){
		if((childpid=fork()) < 0){
			perror("error en el fork");
			exit(EXIT_FAILURE);
		}
		
		if(childpid==0){
			if(execl(argv[1],argv[1],NULL) < 0){
				perror("Error en el execl background");
				exit(EXIT_FAILURE);
			}
		}
	}
	
	else{
		char *argumentos[argc-2];
			
		for(int i=0; i < argc -2; i++){
			argumentos[i]=argv[i+1];
		}
		
		if((childpid=fork()) < 0){
			perror("error en el fork");
			exit(EXIT_FAILURE);
		}
		
		if(execv(argv[1],argumentos) < 0){
			perror("error en el execv background");
			exit(EXIT_FAILURE);
		}
	}
}

return 0;
}


			
	
		
	
	
	
