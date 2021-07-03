#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <omp.h>

int main(int argc, char * argv[]){
    if(argc < 2){
        printf("Modo ejecución: <programa> <dimensión>\n");
        exit(-1);
    }

    srand((unsigned int) getpid());

    int dimension = atoi(argv[1]);
    int ** matriz_1;
    int ** matriz_2;
    int ** resultado;
    int acumulador=0;
    int i=0, j=0, k=0;
    double tantes,tdespues,ncgt;

    matriz_1 = (int **) malloc(sizeof(int *)*dimension);
    matriz_2 = (int **) malloc(sizeof(int *)*dimension);
    resultado = (int **) malloc(sizeof(int *)*dimension);

    for(i=0; i < dimension; i++){
        matriz_1[i]=(int *) malloc(sizeof(int)*dimension);
        matriz_2[i]=(int *) malloc(sizeof(int)*dimension);
        resultado[i]=(int *) malloc(sizeof(int)*dimension);
    }

    tantes = omp_get_wtime();

    #pragma omp parallel for private(i,j)
        for(i=0; i < dimension; i++){
            for(int j=0; j < dimension; j++){
                matriz_1[i][j]=rand()%10;
                matriz_2[i][j]=rand()%10;
            }
        }

    #pragma omp parallel for private(i,j,acumulador)
        for(i=0; i < dimension; i++){
	    if(i==0)
	    	printf("Nº hebras: %d\n",omp_get_num_threads());
            for(j=0; j < dimension; j++){
                for(k=0; k < dimension; k++){
                    acumulador += matriz_1[i][k] * matriz_2[k][j];
                }

                resultado[i][j]=acumulador;

                acumulador = 0;
            }
        }
    
    tdespues = omp_get_wtime();

    ncgt = tdespues - tantes;
    
    printf("Tiempo = %f \n",ncgt);

    //Prueba de impresión
    if(dimension <= 3){
        for(i=0; i < dimension; i++){
            for(int j=0; j < dimension; j++){
                printf("a[%d][%d]=%d ",i,j,matriz_1[i][j]);
            }
            printf("\n");
        }

        printf("\n");

        for(i=0; i < dimension; i++){
            for(int j=0; j < dimension; j++){
                printf("b[%d][%d]=%d ",i,j,matriz_2[i][j]);
            }
            printf("\n");
        }

        printf("\n");

        for(i=0; i < dimension; i++){
            for(int j=0; j < dimension; j++){
                printf("m[%d][%d]=%d ",i,j,resultado[i][j]);
            }
            printf("\n");
        }

        printf("\n");
    }

    else{
        printf("m[0][0]=%d --- m[%d][%d]=%d \n", resultado[0][0], dimension-1, dimension-1, resultado[dimension-1][dimension-1]);
    }

    for(i=0; i < dimension; i++){
        free(matriz_1[i]);
        free(matriz_2[i]);
        free(resultado[i]);
    }

    free(matriz_1);
    free(matriz_2);
    free(resultado);

    return 0;
}
