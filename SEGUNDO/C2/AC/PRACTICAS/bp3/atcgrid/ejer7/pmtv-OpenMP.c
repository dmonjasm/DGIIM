#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <unistd.h>
#include <time.h>

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
    int i=0,j=0;
    struct timespec cgt1,cgt2; double ncgt;
    int modifier;
    omp_sched_t kind;

    omp_get_schedule(&kind, &modifier);

    printf("Schedule: %d,%d\n\n", kind, modifier);

    vector=(int *)malloc(sizeof(int)*filcol);
    resultado=(int *)malloc(sizeof(int)*filcol);
    matriz=(int **)malloc(sizeof(int*)*filcol);

    for(int i=0; i < filcol; i++)
        matriz[i]=(int *)malloc(sizeof(int)*filcol);

    srand((unsigned int) getpid());

    //Inicializo la matriz y el vector que se van a multiplicar
    #pragma omp for private(i,j)
    for(i=0; i < filcol; i++){
        for(j=0; j < filcol; j++){
            if(j <= i)
                matriz[i][j]=rand() % 10;

            else
                matriz[i][j]=0;
            
        }

        vector[i] = rand()%10;
        resultado[i]=0;
    }

    clock_gettime(CLOCK_REALTIME,&cgt1);
    //Realizo el producto
    #pragma omp parallel private(i,j)
    {

    #pragma omp for schedule(runtime) reduction(+:acumulador)
    for( i=0; i < filcol; i ++){
        for( j=0; j <= i; j++){
            acumulador += matriz[i][j]*vector[j];
        }

        resultado[i]=acumulador;
        acumulador=0;
    }
    }

    clock_gettime(CLOCK_REALTIME,&cgt2);

    ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec)+ (double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));

    if(filcol < 5){
    //Muestro matriz, vector y resultado
    for( i=0; i < filcol; i++){
        for( j=0; j < filcol; j++)
            printf("M[%d][%d]=%d ",i,j,matriz[i][j]);

        printf("\n");

    }

    printf("\n");

    for( i=0; i < filcol; i++)
        printf("v[%d]=%d ", i, vector[i]);

    printf("\n\n");

    for( i=0; i < filcol; i++)
        printf("r[%d]=%d ", i, resultado[i]);

    printf("\n");
    }

    else{
        printf("r[0]=%d, r[%d]=%d\n", resultado[0],filcol-1, resultado[filcol-1]);
        printf("Tiempo: %f\n", ncgt);
    }

    free(resultado);
    free(vector);

    for(int i=0; i < filcol; i++)
        free(matriz[i]);

    free(matriz);

    return 0;
}
