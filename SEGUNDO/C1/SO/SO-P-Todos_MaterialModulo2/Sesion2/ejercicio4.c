#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <ftw.h>

static int acumulador_archivos=0;
int acumulador_bytes=0;

int buscar(const char* path, const struct stat * stat, int flags, struct FTW* ftw){

    DIR * directorio;
    struct dirent * direct;
    struct stat atributos;
    char cadena[100];
    int numero_inodo=0;

    if(strcmp(path,".")==0||strcmp(path, "..")){
        lstat(path,&atributos);
        if(S_ISREG(atributos.st_mode)&&(atributos.st_mode&0000010==0000010)&&(atributos.st_mode&0000001==0000001)){
            printf("%s %ld\n", path, atributos.st_ino);
            acumulador_bytes+=atributos.st_size;
            acumulador_archivos+=1;
        }
    }


    return 0;

}

int main(int argc, char * argv[]){
    int acumulador_archivos=0;
    int acumulador_argumnetos=0;
    char * pathname;

    printf("Numero de i-nodo:\n");
    if(nftw(argc==2 ? argv[1] : ".", buscar, 10, 0) != 0){
        perror("nftw");
    }

    printf("Existen %d archivos regulares con permiso x para grupo y otros\n", acumulador_archivos);
    printf("El tamaño total ocupado por dichos archivos es %d bytes\n", acumulador_bytes);

    return 0;
}
