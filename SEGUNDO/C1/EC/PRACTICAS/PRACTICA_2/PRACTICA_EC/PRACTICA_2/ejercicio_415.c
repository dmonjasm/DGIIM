#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>

unsigned lista[]={0x80000000,0x00100000, 0x00000800,0x00000001};
int SIZE=sizeof(lista)/sizeof(int);
int resultado=0;

int popcount5(unsigned* array,int len)
{
	int i;
	int val, result=0;
	int SSE_mask[]={0x0f0f0f0f, 0x0f0f0f0f, 0x0f0f0f0f, 0x0f0f0f0f};
	int SSE_LUTb[]={0x02010100, 0x03020201, 0x03020201, 0x04030302};
	
	if(len & 0x3) printf("leyendo 128b pero len no multiplo de 4?\n");
	for(i = 0; i < len; i+=4)
	{
	asm("movdqu	%[x], %%xmm0	\n\t"
	    "movdqa	%%xmm0, %%xmm1	\n\t"
	    "movdqu	%[m], %%xmm6	\n\t"
	    "psrlw	$4, %%xmm1	\n\t"
	    "pand	%%xmm6, %%xmm0	\n\t"
	    "pand 	%%xmm6, %%xmm1	\n\t"

	    "movdqu	%[l], %%xmm2	\n\t"
	    "movdqa	%%xmm2, %%xmm3	\n\t"
	    "pshufb	%%xmm0, %%xmm2	\n\t"
	    "pshufb	%%xmm1, %%xmm3	\n\t"
		
	    "paddb	%%xmm2	, %%xmm3	\n\t"
	    "pxor	%%xmm0	, %%xmm0	\n\t"
	    "psadbw	%%xmm0	, %%xmm3	\n\t"
	    "movhlps	%%xmm3	, %%xmm0	\n\t"
	    "paddd	%%xmm3	, %%xmm0	\n\t"
	    "movd	%%xmm0, %[val] 	\n\t"

	    : [val] "=r" (val)
	    : [x] "m" (array[i]),
	      [m] "m" (SSE_mask[0]),
	      [l] "m" (SSE_LUTb[0])

	    );
	   
      	    result += val;
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

crono(popcount5, "popcount(en lenguaje asm SSE3)");

exit(0);
}
		
