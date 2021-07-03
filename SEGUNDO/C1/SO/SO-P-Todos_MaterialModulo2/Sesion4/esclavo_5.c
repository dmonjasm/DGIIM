#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include <string.h>

int main(int argc, char *argv []){

    if(argc < 3){
        printf("Modo de ejecución, esclavo: <programa> <extremo_inferior> <extremo_superior>\n");
        exit(EXIT_FAILURE);
    }

    int inf=strtol(argv[1],NULL, 10);
    int sup=strtol(argv[2],NULL, 10);
    int raiz=0;
    int primo=1;
    char salida[100];

    for(int i= inf; i <= sup; i++){
        raiz=sqrt(i);
        primo=1;
        for(int j=2; j <= raiz && (primo!=0) ; j++){
            if(i%j!=0){
                primo=1;
            }

            else{
                primo=0;
            }
        }

        if(primo != 0){
            write(STDOUT_FILENO, &i, sizeof(int));
        }
    }

    return 0;
}