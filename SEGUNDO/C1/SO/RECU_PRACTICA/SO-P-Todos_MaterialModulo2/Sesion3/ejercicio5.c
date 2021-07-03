#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void mensaje_error(){
	printf("Modo de ejecución: <programa> <n_hijos>\n");
	exit(EXIT_FAILURE);
}

int main (int argc, char *argv[]){

if(argc < 2)
	mensaje_error();
	
int nhijos=strtol(argv[1],NULL,10);
int copia=nhijos;
pid_t pids[nhijos];
pid_t childpid;
int wstatus;

printf("%d %d\n", nhijos, copia);

for(int i=0; i < nhijos; i++){
	if((childpid=fork()) < 0){
		perror("Error en el fork");
		exit(EXIT_FAILURE);
	}
	
	if(childpid == 0){
		printf("Soy el hijo <%d>\n", getpid());
		exit(EXIT_SUCCESS);
	}
	else{
		pids[i]=childpid;
	}
}

for(int i =0; i < copia; i++){
	printf("%d\n", pids[i]);
}


for(int i=0; i < copia; 2*i){
	childpid=waitpid(pids[i],wstatus,0);
	printf("Acaba de terminar mi hijo <%d>\n", childpid);
	nhijos--;
	printf("Solo me quedan %d hijos\n", nhijos);
}

for(int i=1; i < copia; (2*i+1)){
	childpid=waitpid(pids[i], wstatus, 0);
	printf("Acaba de terminar mi hijos <%d>\n", childpid);
	nhijos--;
	printf("Solo me quedan %d hijos\n", nhijos);
}

return 0;
}

