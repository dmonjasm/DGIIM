#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int narg, char * argv[])
{
   if(narg != 2){
       perror("Parámetros equivocados");
       exit(EXIT_FAILURE);
   }

   int fd_entrada;
   if((fd_entrada=open(argv[1],O_RDONLY,S_IRUSR|S_IWUSR)) < 0){
       perror("Error al abrir el archvio de entrada");
       exit(EXIT_FAILURE);
   }

   int fd_salida;

   if((fd_salida=open("salida.txt",O_CREAT|O_TRUNC|O_WRONLY, S_IRUSR|S_IWUSR))< 0){
       perror("Error al abrir el archivo de salida");
       exit(EXIT_FAILURE);
   }

   setvbuf(stdout, NULL, _IONBF, 0);

   char buffer[80];
   char mensaje[10];
   char numero_bloques[30];
   int contador=1;

   for(int i=1; read(fd_entrada, buffer, 80) == 80; i++){
       sprintf(mensaje, "\n\n\nBloque %d\n", i);
       write(fd_salida, mensaje, sizeof(mensaje));
       write(fd_salida, buffer, 80);
       contador=i;
   }

   lseek(fd_salida,0,SEEK_SET);
   sprintf(numero_bloques, "Numero de bloques es %d", contador);
   write(fd_salida, numero_bloques, 23);

   close(fd_entrada);
   close(fd_salida);

   return 0;
}
