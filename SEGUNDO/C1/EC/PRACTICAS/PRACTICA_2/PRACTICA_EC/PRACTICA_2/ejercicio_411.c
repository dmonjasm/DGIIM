#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>

unsigned lista[]={0x8000000,0x00100000, 0x00000800,0x00000000};
//unsigned lista[]={0x7fffffff,0xffefffff,0xfffff7ff, 0xfffffffe, 0x01000024, 0x00356700, 0x8900ac00, 0x00bd00ef};
//unsigned lista[]={0x0, 0x10204080, 0x3590ac06, 0x70b0d0e0, 0xffffffff, 0x12345678, 0x9abcdef0, 0xcafebeef};
int SIZE=sizeof(lista)/sizeof(int);
unsigned resultado=0;



unsigned suma(unsigned * lista, int len){
	unsigned resultado=0;
	
	for(int i=0; i < len; i++){
		for(int j=0; j < 32; j++){
			resultado += lista[i] & 0x1;
			lista[i] >>= 1;
		}
	}

	return resultado;
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

int main(int argc , char * argv[])
{

crono(suma, "suma(en lenguaje C	bulce for)");

exit(0);
} 


