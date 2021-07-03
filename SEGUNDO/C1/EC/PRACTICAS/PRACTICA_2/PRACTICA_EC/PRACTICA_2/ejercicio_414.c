#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>

unsigned lista[]={0x80000000,0x00100000, 0x00000800,0x00000001};
int SIZE=sizeof(lista)/sizeof(int);
int resultado=0;

unsigned popcount(unsigned * lista, int length){

int result=0;

int i,j,x,val;
	for(i=0; i < length; i++){
		x = lista[i];
		val = 0;
		
		for(j=0; j < 8; j++){
			val += x & 0x01010101;
			x >>= 1;
		}

		val += (val >> 16);
		val += (val >> 8);
		result += val & 0xff;
	}

	return result;
} 

void crono(int (*func)(), char* msg){
    struct timeval tv1,tv2;	// gettimeofday() secs-usecs
    long           tv_usecs;	// y sus cuentas

    gettimeofday(&tv1,NULL);
    resultado = func(lista, SIZE);
    gettimeofday(&tv2,NULL);

    tv_usecs=(tv2.tv_sec -tv1.tv_sec )*1E6+
             (tv2.tv_usec-tv1.tv_usec);
    printf("resultado = %d\t", resultado);
    printf("%s:%9ld us\n", msg, tv_usecs);
}

int main(int argc, char* argv[])
{

crono(popcount, "popcount(en lenguaje c mascara)");

exit(0);
}

