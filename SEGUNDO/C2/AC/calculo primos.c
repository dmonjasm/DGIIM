#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void resize(int * np, int tamanio){
    int *auxiliar=NULL;

    auxiliar = (int *)malloc((tamanio+1)*sizeof(int));

    for(int i=0; i < tamanio; i++)
        auxiliar[i]=np[i];

    if(np != NULL)
        free(np);

    np = auxiliar;
}

int main (int argc, char *argv[])
{
    int * NP=NULL;

    if(argc < 2){
        printf("Ejecución: <programa> <maximo>\n");
        exit(-1);
    }

    int x=atoi(argv[1]);

    if(x < 1){
        printf("Introduzca un numero mayor o igual que 1\n");
        exit(-1);
    }
    int primo = 1;
    int tamanio=0;
    
    for(int i=1; i <= x; i++){        
        if(i == 1 || i == 2 || i == 3){
            resize(NP,tamanio);
            NP[tamanio] = i;
            tamanio++;
        }

        for(int j = 2; j < i && primo != 0 ; j++){
            if(i % 2 == 0 || i % j==0)
                primo = 0; 

        }

        if(primo != 0){
            resize(NP,tamanio);
            NP[tamanio] = i;
            tamanio++;
            printf("%d es primo \n", i);
        }

        primo = 1;
    }

    for(int i=0; i < tamanio; i++)
        printf("primos[%d] = %d\n", i, NP[i]);

    return 0;
}