//gcc -m32 -O2 bomba_dmm.c -o bomba_dmm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

char password[]="suspensocom\n";
int passcode = 110920;

void boom(){
	printf("********************************\n");
	printf("********************************\n");
	printf("***********BOOM!!!!*************\n");
	printf("********************************\n");
	printf("********************************\n");
	exit(EXIT_FAILURE);
}

void defused(){
	printf("--------------------------------\n");
	printf("--------------------------------\n");
	printf("--------BOMBA-DESACTIVADA-------\n");
	printf("--------------------------------\n");
	printf("--------------------------------\n");
	exit(EXIT_SUCCESS);
}

int main(){
#define SIZE 100
	char pass[SIZE];
	int pasv;
	int tiempo_restante;
#define TLIM 60
	struct timeval tv1,tv2;
	gettimeofday(&tv1, NULL);

	gettimeofday(&tv2, NULL);
	tiempo_restante=60-(tv2.tv_sec - tv1.tv_sec);
	printf("En %d segundos las bomba explotará\n", tiempo_restante);
	printf("Introduzca la contrasena: ");
	fgets(pass,SIZE,stdin);

	if(strncmp(pass,password,strlen(password)))
		boom();

	gettimeofday(&tv2, NULL);
	if(tv2.tv_sec -tv1.tv_sec > TLIM)
		boom();
	
	gettimeofday(&tv2, NULL);
	tiempo_restante=60-(tv2.tv_sec - tv1.tv_sec);
	printf("En %d segundos las bomba explotará\n", tiempo_restante);

	printf("Introduce el codigo: ");
	scanf("%i",&pasv);

	if (pasv != passcode)
		boom();

	gettimeofday(&tv2,NULL);
	if(tv2.tv_sec -tv1.tv_sec > TLIM)
		boom();

	else{
		defused();
	}
	
}
	




