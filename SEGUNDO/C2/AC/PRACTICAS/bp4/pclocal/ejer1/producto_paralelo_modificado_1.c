#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define MAX 10000

double a[MAX][MAX],b[MAX][MAX], res[MAX][MAX];

int main(int argc, char * argv[]){

    if(argc < 2){
        printf("Modo ejercución: <programa> <filas/columnas> \n");
        exit(-1);
    }

    int dimension=atoi(argv[1]);
    struct timespec cgt1,cgt2;
    double ncgt;
    double acumulador;
    int i = 0, j=0, k = 0;

    srand((unsigned int) getpid());

    for(i=0; i < dimension; i++){
        for(j=0; j < dimension; j++){
            a[i][j]=rand()%10;
            b[i][j]=rand()%10;
        }
    }

    clock_gettime(CLOCK_REALTIME,&cgt1);
	
    //Se traspone la matriz
    #pragma omp parallel for private(i,j) 
    for(i=0; i < dimension; i++){
        for(j=i; j < dimension; j++){
            if(i!=j){
                acumulador = b[i][j];
                b[i][j] = b[j][i];
                b[j][i] = acumulador;
            }
        }
    }
    //Se realize el producto de las matrices por filas
    #pragma omp parallel for private(i,j,k)
    for(i=0; i < dimension; i++){
        if(i==0)
            printf("Nº hebras: %d\n",omp_get_max_threads());
        for(j=0; j < dimension; j++){
            for(k=0; k < dimension; k++){
                res[i][j] += a[i][k] * b[j][k];
            }
        }
    }
    clock_gettime(CLOCK_REALTIME,&cgt2);

    ncgt=(double)(cgt2.tv_sec-cgt1.tv_sec) + (double)((cgt2.tv_nsec - cgt1.tv_nsec)/(1.e+9));


    //Prueba de funcionamiento
    if(dimension <= 5){
        for(int i=0; i < dimension; i++){
            for(int j=0; j < dimension; j++){
                printf("a[%d][%d]=%f ",i,j,a[i][j]);
            }

            printf("\n");
        }
        //Se vuelve a trasponer para que cuando se muestre entera se muestren los coeficientes correctos
        for(int i=0; i < dimension; i++){
            for(int j=i; j < dimension; j++){
                if(i!=j){
                    acumulador = b[i][j];
                    b[i][j] = b[j][i];
                    b[j][i] = acumulador;
                }
            }
        }

        printf("\n");

        for(int i=0; i < dimension; i++){
            for(int j=0; j < dimension; j++){
                printf("b[%d][%d]=%f ",i,j,b[i][j]);
            }

            printf("\n");
        }

        printf("\n");

        for(int i=0; i < dimension; i++){
            for(int j=0; j < dimension; j++){
                printf("res[%d][%d]=%f ",i,j,res[i][j]);
            }

            printf("\n");
        }

        printf("\n");

        printf("Tiempo: %f\n", ncgt);
    }

    else
    {
        printf("a[0][0]=%f -- a[%d][%d]=%f\n",a[0][0],dimension-1,dimension-1,a[dimension-1][dimension-1]);
        printf("b[0][0]=%f -- b[%d][%d]=%f\n",b[0][0],dimension-1,dimension-1,b[dimension-1][dimension-1]);
        printf("res[0][0]=%f -- res[%d][%d]=%f\n",res[0][0],dimension-1,dimension-1,res[dimension-1][dimension-1]);
        printf("Tiempo: %f\n",ncgt);
    }

    return 0;    
}