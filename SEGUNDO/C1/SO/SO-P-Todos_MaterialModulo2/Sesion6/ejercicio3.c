#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>


int main(int argc, char *argv[]){
    
    struct flock cerrojo;
    int fd;
    int fd2;
    pid_t childpid;

    if((fd=open("temporal", O_RDWR)) < 0){
        perror("open");
        exit(EXIT_FAILURE);
    }
    if((fd2=open("ejercicio1.c",O_RDWR)) < 0){
        perror("open");
        exit(EXIT_FAILURE);
    }

    cerrojo.l_type=F_WRLCK;
    cerrojo.l_whence=SEEK_SET;
    cerrojo.l_start=0;
    cerrojo.l_len=0;

    if(fcntl(fd,F_SETLK,&cerrojo) < 0){
        perror("fcntl");
        exit(EXIT_FAILURE);
    }

    if((childpid=fork()) < 0){
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if(childpid==0){

        if(fcntl(fd2,F_SETLK, &cerrojo) < 0){
            perror("fcntl123");
            exit(EXIT_FAILURE);
        }

        if(fcntl(fd,F_SETLKW,&cerrojo) < 0){
            perror("fcntl2");
            exit(EXIT_FAILURE);
        }

    }

    else{
        waitpid(-1,NULL, 0);
        if(fcntl(fd2, F_SETLKW, &cerrojo) < 0){
            perror("fcntl3");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}