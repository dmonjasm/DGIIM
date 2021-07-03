#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <dirent.h>

#define longnombre 50


void mensaje_error(){
	printf("Modo ejecución: <servidor> <dir_pathname>\n");
	exit(EXIT_FAILURE);
}

struct mensaje{
	int entrada;
	char metadato;
	pid_t pid;
};

int entrada_valida(struct mensaje auxiliar,char * pathname){
	DIR * directorio;
	struct dirent *contenido_dir;
	int contador=0;
	int validez=0;

	if((directorio=opendir(pathname)) < 0){
		perror("Servidor:Error al abrir el directorio");
		exit(EXIT_FAILURE);
	}
	
	while(((contenido_dir=readdir(directorio)) != NULL) && contador < auxiliar.entrada){
		contador++;
	}
	
	if(contador < (auxiliar.entrada-1)){
		validez=-1;
	}
	
	else{
		struct stat atributos;
		lstat(contenido_dir->d_name,&atributos);
		
		if(S_ISREG(atributos.st_mode)){
			if(auxiliar.metadato=='i')
				validez=atributos.st_ino;
			
			else
				validez=atributos.st_size;
		
		}

		else
			validez=-1;
	}

return validez;
}

	
	
	

int main(int argc, char * argv[]){

if(argc < 2){
	mensaje_error();
}

int respuesta;
struct mensaje recibido;
int bytes_leidos=0;



while( (bytes_leidos=read(STDIN_FILENO,&recibido,sizeof(struct mensaje)) ) != 0){
	char fifo[longnombre];
	int fd_privado;
	sprintf(fifo,"FIFO.%d",recibido.pid);
	printf("El numero de bytes leidos es %d\n", bytes_leidos);
	printf("El numero de entrada es %d\n", recibido.entrada);

	if(bytes_leidos==0)
		exit(EXIT_SUCCESS);

	if((fd_privado=open(fifo,O_WRONLY,S_IRWXU)) < 0){
		perror("Servidor:Error en la apertura del fifo privado");
		exit(EXIT_FAILURE);
	}
	
	respuesta=entrada_valida(recibido,argv[1]);
	
	if(write(fd_privado,&respuesta,sizeof(int)) < 0){
		perror("Servidor:error en la escritura en el cauce privado");
		exit(EXIT_FAILURE);
	}

	close(fd_privado);
}

return 0;
}
	
	



