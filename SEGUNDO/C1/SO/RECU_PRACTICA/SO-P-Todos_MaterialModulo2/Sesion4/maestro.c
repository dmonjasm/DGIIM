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

void lanzador_esclavos(char limite_inf[], char limite_sup[]){
	if(execl("./esclavo","esclavo",limite_inf,limite_sup,NULL) < 0){
		perror("Error en la ejecución del esclavo");
		exit(EXIT_FAILURE);
	}
}



int main(int argc, char * argv[]){

if(argc < 3){
	mensaje_error();
}

int inferior=strtol(argv[1],NULL,10);
int superior=strtol(argv[2],NULL,10);
int medio=(superior+inferior)/2;
int fd_1[2];
int fd_2[2];
pid_t childpid;
int lectura;
int estado;


pipe(fd_1);
pipe(fd_2);

if((childpid=fork()) < 0){
	perror("Error al crear el hijo 1");
	exit(EXIT_FAILURE);
}

if(childpid==0){
	close(fd_1[0]);
	char media[10];
	sprintf(media, "%d", medio);
	dup2(fd_1[1],STDOUT_FILENO);
	lanzador_esclavos(argv[1],media);
	close(fd_1[1]);
	
	exit(EXIT_SUCCESS);
}
wait(&estado);

close(fd_1[1]);

while(read(fd_1[0],&lectura,sizeof(int)) > 0){
	printf("Primo: %d\n",lectura);
}

close(fd_1[0]);



if((childpid=fork()) < 0){
	perror("Error al crear el hijo 1");
	exit(EXIT_FAILURE);
}

if(childpid==0){
	close(fd_2[0]);
	char media[10];
	sprintf(media, "%d", medio+1);
	dup2(fd_2[1],STDOUT_FILENO);
	lanzador_esclavos(media,argv[2]);
	close(fd_2[1]);
	
	exit(EXIT_SUCCESS);
}

wait(&estado);

close(fd_2[1]);

while(read(fd_2[0],&lectura,sizeof(int)) > 0){
	printf("Primo: %d\n",lectura);
}

close(fd_2[0]);

return 0;
}




	
