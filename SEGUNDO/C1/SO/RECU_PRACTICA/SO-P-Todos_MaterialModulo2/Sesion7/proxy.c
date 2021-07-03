#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

#define tamano 1024
#define longnombre 50

int main(int argc, char *argv[]){

int mipid=getpid();
char fifo_proxy[longnombre];
int proxy_entrada;
int bytes_leidos;
int fd_bloqueo;
char buffer[tamano];
FILE * temporal=tmpfile();

//Establecemos el nombre del fifo a crear
sprintf(fifo_proxy,"fifo.%d", mipid);
umask(0);
mkfifo(fifo_proxy,0666);


//Abrimos el fifo solo de lectura
if((proxy_entrada=open(fifo_proxy, O_RDONLY, S_IRWXU)) < 0){
	perror("Proxy: error en la apertura del fifo_proxy de entrada");
	exit(EXIT_FAILURE);
}

//Se establece que la entrada estandar coincide con proxy_entrada
dup2(proxy_entrada,STDIN_FILENO);

while((bytes_leidos=read(STDIN_FILENO,buffer,tamano)) > 0){

	//Escribimos los datos leidos en el archivo temporal
	if(fwrite(buffer,sizeof(char),bytes_leidos,temporal) <= 0){
		perror("Proxy:Error en la escritura de datos en el archivo temporal");
		exit(EXIT_FAILURE);
	}
}

//Creamos las struct flock y establecemos los atributos del cerrojo que impondremos
struct flock cerrojo;
cerrojo.l_type=F_WRLCK;
cerrojo.l_whence=SEEK_SET;
cerrojo.l_start=0;
cerrojo.l_len=0;


//Abrimos el archivo que queremos bloquear
if((fd_bloqueo=open("bloqueo",O_WRONLY,S_IRWXU)) < 0){
	perror("Proxy:Error en la apertura del archivo bloqueo");
	exit(EXIT_FAILURE);
}

//Establecemos un bloqueo de escritura sobre todo el archivo, sino se puede el programa se bloquea hasta que se pueda
if(fcntl(fd_bloqueo,F_SETLKW,&cerrojo) < 0){
	perror("Proxy:Error al intentar establecer el cerrojo");
	exit(EXIT_FAILURE);
}

//Leemos los datos del archivo temporal y escribimos por pantalla
	printf("\nEscribiendo desde PROXY:<%d>\n",getpid());
while(!feof(temporal)){
	
	fread(buffer, sizeof(char),tamano,temporal);
	write(STDOUT_FILENO,buffer,strlen(buffer));

}

//Cambiamos el tipo de cerrorjo
cerrojo.l_type=F_UNLCK;

//Quitamos el cerrojo impuesto anteriormente
if(fcntl(fd_bloqueo,F_SETLK,&cerrojo) < 0){
	perror("Proxy:Error al desbloquear el archivo bloqueo");
	exit(EXIT_FAILURE);
}

//Eliminamos el cauce con nombre y cerramos el archivo bloqueo
unlink(fifo_proxy);
close(fd_bloqueo);

return 0;
}



	
