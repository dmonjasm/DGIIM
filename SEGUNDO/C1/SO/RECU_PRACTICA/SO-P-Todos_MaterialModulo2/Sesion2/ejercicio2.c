#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>

void mensaje_error(){
	printf("Modo ejecución:<programa> <pathname> <octal> \n");
	exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]){

if(argc < 3){
	mensaje_error();
}

int octal=strtol(argv[2],NULL,8);
DIR * directorio;
struct dirent * contenido_dir;
struct stat atributos;
int permisos_antiguos;
char pathname[256];

if((directorio=opendir(argv[1])) < 0){
	perror("Error al abrir el directorio");
	exit(EXIT_FAILURE);
}

while((contenido_dir=readdir(directorio)) > 0){
	if(strcmp(".",contenido_dir->d_name)==0 | strcmp("..",contenido_dir->d_name)==0){
		continue;
	}
	
	sprintf(pathname, "%s/%s", argv[1], contenido_dir->d_name);
	stat(pathname,&atributos);
	permisos_antiguos=atributos.st_mode;

	if(chmod(pathname, octal) == 0){
		printf("<%s>:<%o> <%o>\n", contenido_dir->d_name,permisos_antiguos,octal);
	}

	else{
		printf("<%s>:<%d> <%o>\n", contenido_dir->d_name,errno, permisos_antiguos);
	}
}

closedir(directorio);

return 0;
}
	
