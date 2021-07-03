#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

void mensaje_error(){
	printf("Modo de ejecución: <programa> <orden> \"<\" ó \">\" <archivo>\n");
	exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]){

if(argc < 4){
	mensaje_error();
}

if(strcmp("<",argv[2]) != 0 && strcmp(">",argv[2]) != 0){
	mensaje_error();
}

int fd;
		
if((fd=open(argv[3],O_CREAT|O_RDWR,S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)) < 0){
	perror("Error al abrir/crear el archivo temporal");
	exit(EXIT_FAILURE);
}

else{
	if(strcmp("<",argv[2]) == 0){
		close(0);
		if(fcntl(fd,F_DUPFD,0) < 0){
			perror("Error fcntl");
			exit(EXIT_FAILURE);
		}
		
		if(execlp(argv[1],argv[1],NULL) < 0){
			perror("Error execlp");
			exit(EXIT_FAILURE);
		}
	}
	
	else{
		close(1);

		if(fcntl(fd,F_DUPFD,1) < 0){
			perror("Error fcntl");
			exit(EXIT_FAILURE);
		}
		
		if(execlp(argv[1],argv[1],NULL) < 0){
			perror("error execlp");
			exit(EXIT_FAILURE);
		}
	}
}

close(fd);

return 0;
}
		
	
		
