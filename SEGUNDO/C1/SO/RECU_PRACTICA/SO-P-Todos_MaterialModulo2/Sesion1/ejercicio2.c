#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

void mensaje_error(){
	printf("Error:Modo de ejerución $:<programa> <pathname_archivo>\n");
	exit(EXIT_FAILURE);
}

int main(int argc, char * argv[]){

if(argc < 2){
	mensaje_error();
}

int contador_bloque=1;
int fd_entrada;
int fd_salida;
int bytes_leidos=0;
char salida[30];
char buff[80]="\n";


if((fd_entrada=open(argv[1],O_CREAT, S_IRUSR|S_IWUSR|S_IRGRP | S_IROTH)) < 0){
	perror("Error el abrir el archivo de entrada");
	exit(EXIT_FAILURE);
}

if((fd_salida=open("salida.txt",O_CREAT|O_TRUNC|O_WRONLY,S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)) < 0){
	perror("Error al abrir el archivo de salida");
	exit(EXIT_FAILURE);
}

write(fd_salida,buff,strlen(buff));

while((bytes_leidos=read(fd_entrada,buff,80)) == 80){
	sprintf(salida,"Bloque %d\n", contador_bloque);
	contador_bloque++;
	
	if(write(fd_salida,salida,strlen(salida)) == 0){
		perror("Error en la escritura del archivo de salida, este");
		exit(EXIT_FAILURE);
	}

	if(write(fd_salida,buff,80) != 80){
		perror("Error en la escritura del archivo de salida");
		exit(EXIT_FAILURE);
	}

}
sprintf(salida, "El numero de bloques es <%d>\n", contador_bloque);
lseek(fd_salida,0,SEEK_SET);
write(fd_salida,salida,strlen(salida));

close(fd_entrada);
close(fd_salida);

return 0;
}



