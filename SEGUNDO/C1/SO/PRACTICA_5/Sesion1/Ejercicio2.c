#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char * argv[])
{

int fd_entrada, fd_salida;
char cadena[80];
char cadena_auxiliar[40];
int resultado;
int contador=1;


if(argc == 2){
	if((fd_entrada=open(argv[1],O_RDONLY,0)) < 0){
		printf("Error %d en open", errno);
		perror("Error en open");
		exit(EXIT_FAILURE);
	}
}

else
	fd_entrada=STDIN_FILENO;

if((fd_salida=open("salida.txt",O_CREAT|O_WRONLY,S_IRWXU)) < 0){
	printf("Error %d en open", errno);
	perror("Error en open");
	exit(EXIT_FAILURE);
}

	while((resultado=read(fd_entrada,cadena,80))!=0){
		sprintf(cadena_auxiliar,"\n %s %d\n","Bloque", contador);
		write(fd_salida,cadena_auxiliar,strlen(cadena_auxiliar));
		write(fd_salida,cadena,strlen(cadena));
		contador++;
	}
close(fd_entrada);
close(fd_salida);

return 0;
}		
		



		
		
	
