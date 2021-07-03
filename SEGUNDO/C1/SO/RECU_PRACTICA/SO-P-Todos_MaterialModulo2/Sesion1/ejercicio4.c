#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<stdlib.h>
#include<stdio.h>

#define S_ISREG2(mode) (mode & 0170000)?1:0

void mensaje_error(){
	printf("Modo ejecución: <programa> <archivo>\n");
	exit(EXIT_FAILURE);
}

int main(int argc, char * argv[]){


if(argc < 2){
	mensaje_error();
}

struct stat atributos;

stat(argv[1],&atributos);

if(S_ISREG2(atributos.st_mode))
	printf("El archivo es regular\n");

else
	printf("El archivo NO es regular\n");

return 0;
}




