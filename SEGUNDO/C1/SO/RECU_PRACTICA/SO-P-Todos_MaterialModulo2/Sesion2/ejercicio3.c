#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include<dirent.h>
#include<string.h>

void mensaje_error(){
	printf("Modo ejecución: <programa> <pathname>\n");
	exit(EXIT_FAILURE);
}

void recursividad(char pathname[]){
	char new_pathname[256];
	DIR * directorio;
	struct dirent * contenido_dir;
	struct stat atributos;

	if((directorio=opendir(pathname)) < 0){
	perror("Error en la apertura del directorio\n");
	exit(EXIT_FAILURE);
	}

	while((contenido_dir=readdir(directorio)) != NULL){

	if(strcmp(contenido_dir->d_name,".")==0 | strcmp(contenido_dir->d_name, "..") == 0){
		continue;
	}
	
	sprintf(new_pathname, "%s/%s", pathname, contenido_dir->d_name);
	lstat(new_pathname, &atributos);
	
	if(!S_ISDIR(atributos.st_mode)){
		printf("%s %d\n", new_pathname, atributos.st_ino);
	}

	else{
		recursividad(new_pathname);
	}
}
}
	

int main(int argc, char * argv[]){

if(argc < 2)
	mensaje_error();

DIR * directorio;
struct dirent * contenido_dir;
struct stat atributos;
char nombre_archivo[256];
int contador_reg=0;
int acumulador_bytes=0;

if((directorio=opendir(argv[1])) < 0){
	perror("Erro en la apertura del directorio\n");
	exit(EXIT_FAILURE);
}

printf("Los i-nodos son:\n");

while((contenido_dir=readdir(directorio)) != NULL){

	if(strcmp(contenido_dir->d_name,".")==0 | strcmp(contenido_dir->d_name, "..") == 0){
		continue;
	}
	char pathname[256];

	sprintf(pathname, "%s/%s", argv[1], contenido_dir->d_name);
	lstat(pathname, &atributos);
	
	if(!S_ISDIR(atributos.st_mode)){
		printf("%s %d\n", pathname, atributos.st_ino);
	}

	else{
		recursividad(pathname);
	}
}

return 0;

}

	
