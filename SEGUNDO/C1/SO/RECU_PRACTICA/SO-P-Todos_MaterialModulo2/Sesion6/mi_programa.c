#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

void mensaje_error(){
	printf("Modo ejecución:<programa> <orden> \"<>\" <archivo_temporal>\n");
	exit(EXIT_FAILURE);
}

int main(int argc, char * argv[]){

if(argc < 4){
	mensaje_error();
}

int fd_temporal;


if((fd_temporal=open(argv[3],O_CREAT|O_RDWR|O_TRUNC, S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)) < 0){
	perror("Error al abrir/crear el archivo temporal");
}

if(strcmp(argv[2],"<") != 0 && strcmp(argv[2],">") != 0){
	mensaje_error();
}

else{
	if(strcmp(">",argv[2]) == 0){
		if(dup2(fd_temporal, STDOUT_FILENO) < 0){
			perror("dup2");
			exit(EXIT_FAILURE);
		}

		if(execlp(argv[1], argv[1],NULL) < 0){
			perror("error execl");
			exit(EXIT_FAILURE);
		}
	}
	
	else{
		if(dup2(fd_temporal,STDIN_FILENO) < 0){
			perror("dup2");
			exit(EXIT_FAILURE);
		}
		
		if(execlp(argv[1], argv[1],NULL) < 0){
			perror("error execl");
		}
	}
}

close(fd_temporal);

return 0;
}
		

