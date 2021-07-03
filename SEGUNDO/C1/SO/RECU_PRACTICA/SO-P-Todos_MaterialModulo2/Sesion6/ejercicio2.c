#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void mensaje_error(){
	printf("Modo ejecución: <programa> <orden> \"|\" <orden>\n");
	exit(EXIT_FAILURE);
}

int main(int argc , char * argv[]){

if(argc < 4){
	mensaje_error();
}


if(strcmp("|",argv[2]) != 0){
	mensaje_error();
}

pid_t childpid;
int fd[2];
int estado;
pipe(fd);

if((childpid=fork()) < 0){
	perror("error en el fork");
	exit(EXIT_FAILURE);
}

if(childpid==0){
	close(fd[0]);
	dup2(fd[1],STDOUT_FILENO);

	if(execlp(argv[1],argv[1],NULL) < 0){
		perror("Error en el exec");
		exit(EXIT_FAILURE);
	}
	close(fd[1]);
	exit(EXIT_SUCCESS);
}

close(fd[1]);
dup2(fd[0],STDIN_FILENO);

if(execlp(argv[1],argv[1],NULL) < 0){	
	perror("Error en el exec");
	exit(EXIT_FAILURE);
}

close(fd[0]);

return 0;
}



	

