#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

void mensaje_error(){
	printf("Modo ejecución: <programa> <archivo_a_copiar> <destino_pathname>\n");
	exit(EXIT_FAILURE);
}

int main (int argc, char *argv[]){

if(argc < 3){
	mensaje_error();
}

struct stat atributos;
int fd_origen, fd_destino;
char *ptr,*ptr_2;

if((fd_origen=open(argv[1],O_RDWR,S_IRWXU)) < 0){
	perror("error en el open fuente");
	exit(EXIT_FAILURE);
}

if((fd_destino=open(argv[2],O_RDWR|O_CREAT|O_APPEND|O_TRUNC,S_IRWXU)) < 0){
	perror("error en el open destino");
	exit(EXIT_FAILURE);
}

fstat(fd_origen,&atributos);

ptr = (char*) mmap(NULL, atributos.st_size, PROT_READ |PROT_WRITE,MAP_SHARED,fd_origen, 0);

if(ptr == MAP_FAILED){
	perror("mmap");
	exit(EXIT_FAILURE);
}

printf("Ajustando tamaño del archivo %s a %ld \n", argv[2], atributos.st_size);
ftruncate(fd_destino,atributos.st_size);

ptr_2 = (char*) mmap(NULL, atributos.st_size, PROT_READ | PROT_WRITE,MAP_SHARED,fd_destino, 0);

if(ptr_2==MAP_FAILED){
	perror("mmap2");
	exit(EXIT_FAILURE);
}

memcpy(ptr_2, ptr, atributos.st_size);

if(munmap(ptr,atributos.st_size) < 0){
	perror("error eliminación del mapa fuente");
	exit(EXIT_FAILURE);
}

if(munmap(ptr_2,atributos.st_size) < 0){
	perror("error eliminación del mapa destino");
	exit(EXIT_FAILURE);
}

close(fd_origen);
close(fd_destino);

return 0;
}





	
