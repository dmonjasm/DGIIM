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
void recurrencia(int * acumulador_archivo,int * acumulador_bytes, char * path);

int main (int argc, char * argv[]){

    char * pathname;
    int contador_archivos=0;
    int contador_bytes=0;

    printf("Los i-nodos son:\n");
    if(argc==2){
        pathname=argv[1];
        recurrencia(&contador_archivos, &contador_bytes, pathname);
    }
    else{
        recurrencia(&contador_archivos, &contador_bytes, ".");
    }

    printf("Existen %d archivos regulares con permiso x para grupo y otros\n", contador_archivos);
    printf("El tamaño total ocupado por dichos archivos es %d bytes\n", contador_bytes);

    return 0;
}

void recurrencia(int * acumulador_archivo, int * acumulador_bytes, char * path){

    DIR * directorio;
    struct dirent * direct;
    struct stat atributos;
    char cadena[100];
    int numero_inodo=0;

    directorio=opendir(path);

    while((direct=readdir(directorio)) != NULL){
        if(strcmp(direct->d_name,"..")==0 || strcmp(direct->d_name, ".")==0){
            continue;
        } 
        sprintf(cadena,"%s/%s", path, direct->d_name);

        lstat(cadena, &atributos);

        if(S_ISREG(atributos.st_mode)&&(atributos.st_mode&0000010==0000010)&&(atributos.st_mode&0000001==0000001)){
            (*acumulador_archivo)++;
            (*acumulador_bytes)+=atributos.st_size;
            numero_inodo=atributos.st_ino;
            printf("%s %d\n", cadena, numero_inodo);
        }

        else{
            if(S_ISDIR(atributos.st_mode))
                recurrencia(acumulador_archivo, acumulador_bytes, cadena);    
        }
    }

    closedir(directorio);

}
