#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>


void error(){
    printf("Modo de ejecución: <programa> <archivo a copiar> <directorio_destino>\n");
    exit(EXIT_FAILURE);
}
int main(int argc, char * argv[]){

    if(argc < 3){
        error();
    }

    int fd, fd_copia;
    char* memoria1, * memoria2;
    struct stat atributos;
    size_t tamano;

    umask(0);

    if((fd=open(argv[1],O_RDONLY, S_IRWXU)) < 0){
        perror("open");
        exit(EXIT_FAILURE);
    }

    stat(argv[1],&atributos);
    tamano=atributos.st_size;

    if((fd_copia=open(argv[2],O_RDWR|O_CREAT, S_IRWXU)) < 0){
        perror("open2");
        exit(EXIT_FAILURE);
    }

    memoria1=(char*)mmap(0,tamano,PROT_READ,MAP_SHARED,fd,0);

    if(memoria1==MAP_FAILED){
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    printf ("Ajustando el tamano archivo %s a %ld \n",argv[2],tamano);
    ftruncate(fd_copia,tamano);

    memoria2=(char*)mmap(0,tamano,PROT_WRITE,MAP_SHARED, fd_copia, 0);

    if(memoria2==MAP_FAILED){
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    memcpy(memoria2,memoria1, tamano);

    if(munmap(memoria1,tamano) < 0){
        perror("munmap");
        exit(EXIT_FAILURE);
    }

    if(munmap(memoria2,tamano) < 0){
        perror("munmap");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;

}