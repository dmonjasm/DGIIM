#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <ftw.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>

#define MODE(mode) (mode & S_IRUSR) == S_IRUSR

void handler(int signum){
    printf("Se ha recibido una señal SIGPIPE del proceso hijo");
}

int main(int argc, char * argv[]){

    pid_t childpid;
    DIR * directorio;
    struct dirent * contenido;
    struct stat atributos;
    int fd[2];
    int archivo;
    char * mapeo;
    char nombre_archivo[256];
    int bytes_leidos;
    struct sigaction sa;
    struct flock cerrojo;


    sa.sa_handler=handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags=SA_RESTART;

    if(sigaction(SIGPIPE,&sa, NULL)<0){
        perror("sigaction");
        exit(EXIT_FAILURE);
    }


    pipe(fd);
    setvbuf(stdout, NULL, _IONBF, 0);
    if((childpid=fork()) < 0){
        perror("error en el fork");
        exit(EXIT_FAILURE);
    }

    if(childpid!=0){
        close(fd[0]);

        if((directorio=opendir(".")) == NULL){
            perror("erro al abrir el directorio");
            exit(EXIT_FAILURE);
        }

        while((contenido=readdir(directorio)) != NULL){
            if(strcmp(".",contenido->d_name)==0|| strcmp("..", contenido->d_name)== 0){
                continue;
            }

            stat(contenido->d_name, &atributos);

            if(S_ISREG(atributos.st_mode)){

                if(!MODE(atributos.st_mode)){
                    if(chmod(contenido->d_name,S_IRUSR) < 0){
                        perror("error al añadir los permisos de lectura");
                        exit(EXIT_FAILURE);
                    }
                }
                printf("El inodo del archivo %s es %ld y el uid es %d\n",contenido->d_name,atributos.st_ino, atributos.st_uid);
                if(write(fd[1],contenido->d_name, 256) < 0){
                    perror("error al escribir en el cauce");
                }
            }
        }

        close(fd[1]);
    }

    else{
        close(fd[1]);
        
        while ((bytes_leidos=read(fd[0],nombre_archivo, 256)) > 0){
            stat(nombre_archivo,&atributos);
            
            if((archivo=open(nombre_archivo,O_RDONLY))< 0){
                perror("error al abrir el archivo");
                exit(EXIT_FAILURE);
            }

            cerrojo.l_type=F_RDLCK;
            cerrojo.l_whence=SEEK_SET;
            cerrojo.l_len=0;
            cerrojo.l_start=0;

            if(fcntl(archivo, F_SETLKW, &cerrojo) < 0){
                perror("error al crear el cerrojo");
                exit(EXIT_FAILURE);
            }

            printf("Se ha creado un cerrojo sobre el archivo\n");
            
            mapeo=(char*)mmap(0, atributos.st_size, PROT_READ, MAP_SHARED, archivo, 0);
            if(mapeo==MAP_FAILED){
                perror("fallo el mapeo");
                exit(EXIT_FAILURE);
            }
            
            printf("%s \n", mapeo);
        }

        close(fd[0]);
        close(archivo);
        exit(EXIT_SUCCESS);
    }

    closedir(directorio);

    waitpid(childpid, NULL, 0);
    return EXIT_SUCCESS;
}