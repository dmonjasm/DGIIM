#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

static int PROCESOS_CREADOS=5;

int main(int argc, char * argv[]){
    
    int * wstatus;
    int numero_procesos=5;
    pid_t childpid;
    pid_t finalizado;
    pid_t creados[5];

    setvbuf(stdout, NULL,_IONBF, 0);

    for(int i=0; i < PROCESOS_CREADOS; i++){
        if((childpid=fork()) < 0){
            perror("Error fork");
            exit(EXIT_FAILURE);
        }

        if(childpid != 0){
            creados[i]=childpid;
        }

        else if(childpid==0){
            printf("Soy el hijo %d\n", getpid());
            exit(EXIT_SUCCESS);
        }
    }

    
    for(int i=0; i < PROCESOS_CREADOS; i++){
        printf("pids %d guardado %d\n", i, creados[i]);
    }

    for(int i=0; i < PROCESOS_CREADOS; i++){
        if((i+1)%2 != 0){
            finalizado=waitpid(creados[i],wstatus,0);
            printf("Acaba de finalizar mi hijo con %d\n", finalizado);
            numero_procesos--;
            printf("Sólo me quedan %d hijos vivos\n", numero_procesos);
        }
    }

    for(int i=0; i < PROCESOS_CREADOS; i++){
        if((i+1)%2 == 0){
            finalizado=waitpid(creados[i],wstatus,0);
            printf("Acaba de finalizar mi hijo con %d\n", finalizado);
            numero_procesos--;
            printf("Sólo me quedan %d hijos vivos\n", numero_procesos);
        }
    }

    return 0;   
}