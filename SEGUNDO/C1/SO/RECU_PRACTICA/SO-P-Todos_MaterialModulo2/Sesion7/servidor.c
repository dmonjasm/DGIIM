#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>


#define tamano 1024
#define longnombre 50

void mensaje_error(){
	printf("Modo ejecución: <servidor> <nombrefifos>\n");
	exit(EXIT_FAILURE);
}

void sigchld_handler(int signum){
	int estado;
	pid_t pid;
	
	pid=wait(&estado);
	printf("\nAcaba de terminar mi hijo: <%d>\n", pid);
}

int main(int argc, char *argv[]){

if(argc < 2){
	mensaje_error();
}

struct sigaction manejador;
char fifo_entrada[longnombre],fifo_salida[longnombre];
int fd_entrada,fd_salida,fd_bloqueo;
int pid_cliente,bytes_leidos;

manejador.sa_handler=sigchld_handler;
sigemptyset(&manejador.sa_mask);
manejador.sa_flags=SA_RESTART;

//Establecemos un nuevo manejador de señal para SIGCHLD
if(sigaction(SIGCHLD,&manejador,NULL) < 0){
	perror("Servidor:Error al establecer el SIGCHLD_handler");
	exit(EXIT_FAILURE);
}

//Establecemos los nombres de los cauces de entrada y salida conocidos
sprintf(fifo_entrada,"%se", argv[1]);
sprintf(fifo_salida,"%ss", argv[1]);

//Creamos los cauces de entrada y salida conocidos
umask(0);
mkfifo(fifo_entrada, 0666);
mkfifo(fifo_salida, 0666);

//Se abre el cauce de entrada y salida
if((fd_entrada=open(fifo_entrada,O_RDWR,S_IRWXU)) < 0){
	perror("Servidor:Error en la apertura del fifo conocido de entrada");
	exit(EXIT_FAILURE);
}

if((fd_salida=open(fifo_salida,O_RDWR,S_IRWXU)) < 0){
	perror("Servidor:Error en la apertura del fifo conocido de salida");
	exit(EXIT_FAILURE);
}

//Se crea el archivo que se usará para establecer sobre el cerrojos
if((fd_bloqueo=open("bloqueo",O_CREAT|O_TRUNC|O_RDWR,S_IRWXU)) < 0){
	perror("Servidor:Error en la creación/apertura del archivo bloqueo");
	exit(EXIT_FAILURE);
}

//Se leen datos del cauce de entrada conocido
while((bytes_leidos=read(fd_entrada,&pid_cliente,sizeof(int))) != 0){
	printf("Servidor: se ha recibido la peticion del proceso %d\n",pid_cliente);
	
	int childpid;
	
	//Se crea un hijo
	if((childpid=fork()) < 0){
		perror("Servidor:Error en la creación del proceso hijo");
		exit(EXIT_FAILURE);
	}

	if(childpid==0){
		//El hijo ejecuta el proxy
		if(execl("proxy","proxy",NULL) < 0){
			perror("Servidor:Error al iniciar la ejecución del proxy");
			exit(EXIT_FAILURE);
		}
	
		exit(EXIT_SUCCESS);
	}
	//Se escribe en el cauce de salida conocido el pid del proceso hijo para que se comuniquen por un cauce
	
	sleep(1);
	if(write(fd_salida,&childpid,sizeof(int)) < 0){
		perror("Servidor:Error en la escritura en el cauce de salida");
		exit(EXIT_FAILURE);
	}
}

//Se eliminan los cauces y se cierran los archivos
unlink(fifo_entrada);
unlink(fifo_salida);
close(fd_bloqueo);

return 0;
}


