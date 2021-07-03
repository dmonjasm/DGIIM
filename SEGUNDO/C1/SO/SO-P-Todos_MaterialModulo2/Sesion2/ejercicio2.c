#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * argv[]){
    char * pathname;
    int permisos=0;
    struct stat atributos;
    int fd;
    DIR * directorio;
    struct dirent * elementos;
    int permisos_antiguos=0;
    char cadena[100];
    int contador=0;
    

    if(argc == 3){
        pathname=argv[1];
        permisos=strtol(argv[2],NULL,8);
    }

    else
    {
        printf("Modo de uso <programa> <pathname> <permisos>\n");
        exit(EXIT_FAILURE);
    }
    

    directorio=opendir(pathname);

    while((elementos=readdir(directorio))!= NULL){
        if(elementos->d_name=="."|| elementos->d_name==".." || elementos->d_name=="ejercicio2")
            continue;

        sprintf(cadena,"%s/%s", pathname, elementos->d_name);

        lstat(cadena, &atributos);

        if(!S_ISREG(atributos.st_mode)){
            continue;
        }

        permisos_antiguos=atributos.st_mode;

        if(chmod(cadena,permisos) < 0){
            printf("%s: %d %d\n", elementos->d_name, errno, permisos_antiguos);
        }

        else{
            lstat(cadena,&atributos);
            printf("%s: %d %d\n", elementos->d_name, permisos_antiguos, atributos.st_mode);
        }

    }

    closedir(directorio);

    return 0;
}