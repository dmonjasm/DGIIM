#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char * argv[]){
    pid_t mi_pid;
    char nombre_fifo[50];
    int fd, fd_bloqueo;
    int bytes_leidos;
    int bytes_escritos;
    FILE * archivo_temporal;
    char leido[2000];
    struct flock cerrojo;
    struct stat atributos;

    mi_pid=getpid();
    sprintf(nombre_fifo, "fifo.%d", mi_pid);

    if(mkfifo(nombre_fifo, 0666) < 0){
        perror("error al crear el fifo proxy");
        exit(EXIT_FAILURE);
    }

    if((fd=open(nombre_fifo,O_RDWR,S_IRWXU)) < 0){
        perror("error al abrir el fifo_proxy");
        exit(EXIT_FAILURE);
    }

    archivo_temporal=tmpfile();

    while((bytes_leidos=read(fd, leido, 1024)) != 0){
        if(fwrite(leido,sizeof(char),1024,archivo_temporal) < 0){
            perror("error en la escritura de datos en el archivo temporal");
            exit(EXIT_FAILURE);
        }
    }

    cerrojo.l_type=F_WRLCK;
    cerrojo.l_whence=SEEK_SET;
    cerrojo.l_start=0;
    cerrojo.l_len=0;

    if((fd_bloqueo=open("bloqueo", O_RDWR, S_IRWXU)) < 0){
        perror("al abrir bloqueo");
        exit(EXIT_FAILURE);
    }

    if(fcntl(fd_bloqueo,F_SETLKW, &cerrojo) < 0){
        perror("error fcntl");
        exit(EXIT_FAILURE);
    }

   

        fseek(archivo_temporal, 0, SEEK_SET);

        while(bytes_leidos=fread(leido,sizeof(char),1024,archivo_temporal) != 0){
            if(write(STDOUT_FILENO, leido, bytes_leidos) != bytes_leidos){
                perror("error en la escritura");
                exit(EXIT_FAILURE);
            }
        }

    close(fd);
    close(fd_bloqueo);
    fclose(archivo_temporal);
    unlink(nombre_fifo);

}