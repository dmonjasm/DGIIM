#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned int N;
double *x, *y, a;

int main(int argc, char * argv[]){
    int i;

    if(argc < 3){
        printf("Modo ejecución: <programa> <dimensión> <constante>\n");
        exit(-1);
    }
    struct timespec cgt1,cgt2;
    double ncgt;

    N = atoi(argv[1]);
    a = atof(argv[2]);

    x = (double *) malloc(N*sizeof(double));
    y = (double *) malloc(N*sizeof(double));

    for(i = 0; i < N; i++){
        x[i] = 1;
        y[i] = 4;
    }

    clock_gettime(CLOCK_REALTIME,&cgt1);

    for(i = 0; i < N; i++){
        y[i] = a*x[i] + y[i];
    }
    
    clock_gettime(CLOCK_REALTIME,&cgt2);

    ncgt=(double)(cgt2.tv_sec-cgt1.tv_sec) + (double)((cgt2.tv_nsec - cgt1.tv_nsec)/(1.e+9));

    printf("Tiempo: %f\n",ncgt);

    if(N <= 5){
        for (i = 0; i < N; i++)
        {
            printf("r[%d] = %f ",i,y[i]);
        }

        printf("\n");  
    }

    else{
        printf("r[0]=%f -- r[%d] = %f\n",y[0],N-1,y[N-1]);
    }

    return 0;
}