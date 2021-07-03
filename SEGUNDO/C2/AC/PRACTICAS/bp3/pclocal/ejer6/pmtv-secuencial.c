#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    if(argc < 2){
        printf("Modo de ejecución: <programa> <filas/columnas>");
        exit(-1);
    }

    int filcol=atoi(argv[1]);
    int **matriz=NULL;
    int *vector=NULL;
    int *resultado=NULL;
    int acumulador=0;

    vector=(int *)malloc(sizeof(int)*filcol);
    resultado=(int *)malloc(sizeof(int)*filcol);
    matriz=(int **)malloc(sizeof(int*)*filcol);

    for(int i=0; i < filcol; i++)
        matriz[i]=(int *)malloc(sizeof(int)*filcol);

    srand((unsigned int) getpid());

    //Inicializo la matriz y el vector que se van a multiplicar
    for(int i=0; i < filcol; i++){
        for(int j=0; j < filcol; j++){
            if(j <= i)
                matriz[i][j]=rand() % 10;

            else
                matriz[i][j]=0;
            
        }

        vector[i] = rand()%10;
        resultado[i]=0;
    }

    //Realizo el producto
    for(int i=0; i < filcol; i ++){
        for(int j=0; j <= i; j++)
            acumulador += matriz[i][j]*vector[j];

        resultado[i]=acumulador;
        acumulador=0;
    }

    if(filcol < 5){
    //Muestro matriz, vector y resultado
    for(int i=0; i < filcol; i++){
        for(int j=0; j < filcol; j++)
            printf("M[%d][%d]=%d ",i,j,matriz[i][j]);

        printf("\n");

    }

    printf("\n");

    for(int i=0; i < filcol; i++)
        printf("v[%d]=%d ", i, vector[i]);

    printf("\n\n");

    for(int i=0; i < filcol; i++)
        printf("r[%d]=%d ", i, resultado[i]);

    printf("\n");
    }

    else{
        printf("r[0]=%d, r[%d]=%d\n", resultado[0],filcol-1, resultado[filcol-1]);
    }

    free(resultado);
    free(vector);

    for(int i=0; i < filcol; i++)
        free(matriz[i]);

    free(matriz);

    return 0;
}
