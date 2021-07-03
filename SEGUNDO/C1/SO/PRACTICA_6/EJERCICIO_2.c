#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <dirent.h>

int main(int argc, char *argv[]){

if(argc != 3){
	printf("ERROR: FORMATO DESCONOCIDO.\nFORMATO ADMITIDO <PROGRAMA> <PATHNAME> <OCTAL_4_DIGITOS>");
	exit(-1);
}

char * endp;
int  octal_numerico=strtol(argv[2],&endp,8);
DIR *directorio;
struct dirent *dp;
struct stat atributos;
mode_t antiguos;

	if((directorio=opendir(argv[1]))== NULL){
		perror ("No se puede abrir el directorio.");
		exit(-1);
	}

	while((dp = readdir(directorio)) != NULL){
		if(strcmp(dp->d_name, ".")== 0 || strcmp(dp->d_name, "..")== 0)
			continue; 
		if(stat(dp->d_name,&atributos) < 0){
			printf("\nError al intentar acceder a los atributos del archivo1");
			perror("\nError en lstat");
		}
		
		antiguos=atributos.st_mode;
		if(chmod(dp->d_name, octal_numerico) < 0 ){
			printf("%s: " , dp->d_name);
			perror("Error en chmod ");
			printf("%o\n", antiguos);
		}
	
		printf("\n%s: %o %o" , dp->d_name, antiguos, atributos.st_mode);
	}
	
	return 0;
}
	
		
		
		

	


