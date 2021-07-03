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
    
    if(argc != 2){
        printf("Modo de ejecución: <programa> <n_procesos_hijos>\n");
        exit(EXIT_FAILURE);
    }

    int nprocs=strtol(argv[1],NULL, 10);
    int wstatus;
    pid_t childpid;

    /*
    Jerarquía de porcesos tipo 1
    */

   for(int i=0; i < nprocs; i++){
       if((childpid=fork()) == -1){
           fprintf(stderr, "Could not create child %d: %s\n", i, strerror(errno));
           exit(EXIT_FAILURE);
       }

       setvbuf(stdout,NULL,_IONBF,0);

       if(childpid){
           printf("Soy el padre con PID-> %d y PPID-> %d\n", getpid(), getppid());
            break;
       }   

       else{
           printf("Soy el proceso hijo %d padre con PID-> %d y PPID-> %d\n", i, getpid(), getppid());
       }
   }
    
    if(childpid != 0)
        waitpid(-1, &wstatus, 0);

   return 0;
}