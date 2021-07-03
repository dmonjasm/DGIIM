#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define longnombre 50

void mensaje_error(){
	printf("Modo ejecución: <lanzador> <num_cli> <dir_pathname>\n");
	exit(EXIT_FAILURE);
}

struct mensaje{
	int entrada;
	char metadato;
	pid_t pid;
};

static void SIGCHLD_handler(int signum){
	int pid;
	int estado;
	
	pid=wait(&estado);
	
	printf("Lanzador:Acaba de terminar mi hijo <%d>\n", pid);
}

int generador_aleatorio(int semilla,int minimo,float maximo){
srand((unsigned int) semilla);
int salida;

salida=minimo + (int)(maximo*rand()/(RAND_MAX+1.0));

return salida;
}

int main(int argc, char * argv[]){

if(argc < 3){
	mensaje_error();
}

int num_clientes=strtol(argv[1],NULL,10);
char * pathname=argv[2];
char * fifo_name="FIFOpet";
int fd_fifopet;
pid_t childpid;
struct sigaction manejador;


if(num_clientes <= 0){
	mensaje_error();
}

manejador.sa_handler=SIGCHLD_handler;
sigemptyset(&manejador.sa_mask);
manejador.sa_flags=SA_RESTART;

if(sigaction(SIGCHLD,&manejador,NULL) < 0){
	perror("Lanzador:Error al establecer el manejador de señal");
	exit(EXIT_FAILURE);
}

umask(0);
mkfifo(fifo_name,0666);


if((fd_fifopet=open(fifo_name,O_RDWR,S_IRWXU)) < 0){
	perror("Lanzador:error en la apertura del fifo conocido");
	exit(EXIT_FAILURE);
}

for(int i=0; i < num_clientes; i++){
	if((childpid=fork()) < 0){
		perror("Lanzador:error en la creación del hijo");
		exit(EXIT_FAILURE);
	}

	if(childpid == 0){
		pid_t mi_pid=getpid();
		char mi_fifo[longnombre];
		struct mensaje enviar;
		int dato;
		int resultado;
		int fd_mififo;
		char *prueba="hasta aquí funicona";
		sprintf(mi_fifo,"FIFO.%d",mi_pid);
		mkfifo(mi_fifo,0666);
		

		if((fd_mififo=open(mi_fifo,O_RDWR,S_IRWXU)) < 0){
			perror("Lanzador/cliente:error en la apertura del cauce privado");
			exit(EXIT_FAILURE);
		}

		enviar.entrada=generador_aleatorio(mi_pid,1,4.0);
		dato=generador_aleatorio(mi_pid,1,2.0);
		enviar.pid=getpid();
		printf("Lanzador: el numero de entrada es %d\n", enviar.entrada);
		if(dato==1)
			enviar.metadato='i';
		
		if(dato==2)
			enviar.metadato='s';
		
		if(write(fd_fifopet,&enviar,sizeof(struct mensaje)) < 0){
			perror("Lanzador/Cliente:Error al escribir en el cauce");
		}
		
		if(read(fd_mififo,&resultado,sizeof(int)) < 0){
			perror("Lanzador/Cliente:Error al leer del cauce privado");
			exit(EXIT_FAILURE);
		}
		
		if(resultado==-1){
			printf("Cliente <%d>: FALLO\n",mi_pid);
		}
		
		else{
			if(enviar.metadato='i'){
				printf("Numero de inodo= <%d>\n",resultado);
			}
			
			else{
				printf("Tamaño de Archivo= <%d>\n",resultado);
			}
		}
		
		close(fd_mififo);
		unlink(mi_fifo);
		exit(EXIT_SUCCESS);
	}
}

if((childpid=fork()) < 0){
	perror("Lanzador: Error en la creación del proceso servidor");
	exit(EXIT_FAILURE);
}

if(childpid==0){
	dup2(fd_fifopet,STDIN_FILENO);

	if(execl("servidor","servidor",argv[2],NULL) < 0){
		perror("Lanzador: Error en la ejecución del proceso servidor");
	}

	exit(EXIT_SUCCESS);
}

close(fd_fifopet);
unlink(fifo_name);

return 0;
}
		
	







