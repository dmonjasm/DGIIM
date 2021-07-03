#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <time.h>

//#define VECTOR_GLOBAL

#define VECTOR_DYNAMIC

#ifdef VECTOR_GLOBAL
#define MAX 15000

double v[MAX], final[MAX], matriz[MAX][MAX];

#endif

int main(int argc, char** argv){

int i,j;
time_t t;
srand((unsigned) time(&t));
struct timespec cgt1,cgt2; double ncgt;

if(argc < 2){
	printf("Funcionamiento: <programa> <N>\n");
	exit(EXIT_FAILURE);
}

unsigned int N = atoi(argv[1]);


#ifdef VECTOR_GLOBAL
if (N>MAX) N=MAX;
#endif

#ifdef VECTOR_DYNAMIC
double **matriz, *v, *final;

v = (double*) malloc(N*sizeof(double));
final = (double*) malloc(N*sizeof(double));
matriz = (double**) malloc(N*sizeof(double*));

for(i=0; i < N; i++)
matriz[i] = (double *) malloc(N*sizeof(double));

if((v==NULL) || (matriz == NULL) || (final == NULL)){
printf("No hay suficiente espacio para los vectores \n");
exit(EXIT_FAILURE);
}

#endif

//Inicializar matriz
#pragma omp for private(i,j)
for(i=0; i < N; i++){
	for(j=0; j < N; j++)
		matriz[i][j]=rand()%20;

final[i]=0;
}


//Inicializar vector
#pragma omp for private(i)
for(i=0; i < N; i++)
	v[i]=rand()%20;

if(N < 11){
//Imprimimos matriz
for(i=0; i < N; i++){
	for(j=0; j < N; j++)
		printf("m[%d%d]=%f\t",i,j,matriz[i][j]);
printf("\n");
}

//Imprimimos vector
for(i=0; i < N; i++)
	printf("v[%d]=%f\n",i,v[i]);
}

else{
printf("m[%d%d]=%f\t",0,0,matriz[0][0]);
printf("m[%d%d]=%f\t",N-1,N-1,matriz[N-1][N-1]);
printf("\nv[%d]=%f\n",0,v[0]);
printf("v[%d]=%f\n",N-1,v[N-1]);
}

clock_gettime(CLOCK_REALTIME,&cgt1);
//Producto matriz*vector
#pragma omp parallel for private(i,j)
for(i=0; i < N; i++){
	for(j=0; j < N; j++){
		final[i]+=matriz[i][j]*v[j];
		//printf("Producto a[%d][%d] hebra:%d\n",i,j,omp_get_thread_num());
		//printf("final[%d]+=%f*%f=%f\n",i,matriz[i][j],v[j],final[i]);
	}
}
clock_gettime(CLOCK_REALTIME,&cgt2);
ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec)+ (double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));

printf("Tiempo: %f\nTamaño: %d\n\n",ncgt, N);

if(N < 11){
//Imprimimos resultado
printf("\n RESULTADO PRODUCTO \n");
for(i=0; i < N; i++)
	printf("final[%d]=%f\n ", i, final[i]);
}

else{	
	printf("\n RESULTADO PRODUCTO \n");
	printf("final[0]=%f\n",final[0]);
	printf("final[N-1]=%f\n",final[N-1]);
}

#ifdef VECTOR_DYNAMIC
free(final);
free(v);

for(i=0; i < N; i++)
	free(matriz[i]);

free(matriz);
#endif

return 0;
} 
	
