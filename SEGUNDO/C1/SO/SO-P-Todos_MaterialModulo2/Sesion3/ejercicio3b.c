#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char * argv[]){
    /*
    Jerarquía de procesos tipo 2
    */  
    if(argc != 2){
        printf("Modo de ejecución: <programa> <n_procesos_hijos>\n");
        exit(EXIT_FAILURE);
    }

    int nprocs=strtol(argv[1],NULL, 10);
    int wstatus;
    pid_t childpid;

        for(int i=0; i < nprocs; i++){
            if((childpid=fork()) == -1){
               fprintf(stderr, "Could not create child %d: %s\n", i, strerror(errno));
               exit(EXIT_FAILURE);
            }

            if(!childpid){
                printf("Soy el proceso hijo %d con pid-> %d y ppid-> %d\n", i, getpid(), getppid());
                break;
            }

            else
            {
                if(i==0){
                    printf("Soy el proceso padre con pid-> %d y ppid %d\n", getpid(), getppid());
                }

                waitpid(-1, &wstatus, 0);
            }
            
                
        }

        if(childpid != 0)
            waitpid(-1, &wstatus, 0);
        

   return 0;
}