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

int main(int argc , int * argv[]){
    
    if(argc != 2){
        printf("Modo de ejecucion -> <programa> <numero_entero>\n");
        exit(EXIT_FAILURE);
    }
    int numero=strtol(argv[1], NULL, 10);
    int pid=0;
    pid=fork();

    if(pid==0){
        if(numero % 2 ==0){
            printf("El numero es par\n");
        }

        else
        {
            printf("El numero es impar\n");
        }
        
    }

    else
    {
        if(numero % 4 == 0){
            printf("El numero es múltiplo de 4\n");
        }

        else
        {
            printf("El numero no es multiplo de 4\n");
        }
        
    }
    
    return 0;
}