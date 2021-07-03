/*
Examen de prácticas módulo 2 2018-2019 
server.c
Autor: Carlos Romero Cruz
 */

#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>

void Uso(){

  printf("Uso: server <dir_pathname>\n");
  exit(EXIT_FAILURE);
}

int main(int argc, char **argv){

  char *directorio, file_path[500], fifo_cliente[500];
  struct stat atrb;
  int pid, entrada, metadato, fd_fifo_cliente, leido, i, info;
  struct dirent *file;
  DIR *dir;
  
  //Comprobación de argumentos. Se comprueba que el único argumento es un directorio.
  if(argc != 2)
    Uso();

  else{

    directorio = argv[1];

    if(stat(directorio, &atrb) == -1){

      perror("error leyendo los atributos");
      exit(EXIT_FAILURE);
    }

    if( !(S_ISDIR(atrb.st_mode)))
      Uso();
  }

  //Se abre el directorio.
  if( (dir = opendir(directorio)) == NULL){

    perror("error en la apertura del directorio");
    exit(EXIT_FAILURE);
  }

  /* Primero se lee la entrada de la entrada estándar y se comprueba que dicha
     es correcta y es archivo regular.
   */
  while( (leido = read(STDIN_FILENO, &entrada, sizeof(entrada)) ) != 0){

    if(leido == -1){
      
      perror("error en la lectura  de la entrada");
      exit(EXIT_FAILURE);
    }

    file = readdir(dir);
    for(i = 1 ; i < entrada && file != NULL ; i++)
      file = readdir(dir);

    if(file != NULL && file->d_type == DT_REG){

      if(read(STDIN_FILENO, &metadato, sizeof(metadato)) == -1){

	perror("error en la lectura del metadato");
	exit(EXIT_FAILURE);
      }

      //Si el metadato es 1, se devuelve el inodo.
      if(metadato == 1)
	info = file->d_ino;

      //Si es otrea cosa (2), se devuelve el tamaño de la entrada.
      else{
	
	sprintf(file_path, "%s%s", directorio, file->d_name);
	
	if(stat(file_path, &atrb) == -1){

	  perror("error en la lectura de los atributos");
	  exit(EXIT_FAILURE);
	}

	info = atrb.st_size;
      }
    }

    //Como la entrada no es válida, solo se halla el PID del proceso solicitante.
    else{

      info = -1;
      read(STDIN_FILENO, &metadato, sizeof(metadato));
    }

    //Se abre el FIFO correspondiente al proceso que ha solicitado la petición.
    if(read(STDIN_FILENO, &pid, sizeof(pid)) == -1){

      perror("error en la lectura del pid");
      exit(EXIT_FAILURE);
    }
     
    sprintf(fifo_cliente, "FIFO.%d", pid);
    
    if( (fd_fifo_cliente = open(fifo_cliente, O_WRONLY)) == -1){

      perror("error en la apertura del FIFO cliente");
      exit(EXIT_FAILURE);
    }

    //Se escribe la información en el FIFO del proceso.
    if(write(fd_fifo_cliente, &info, sizeof(info)) != sizeof(info)){

      perror("error en la escritura del FIFO cliente");
      exit(EXIT_FAILURE);
    }

    close(fd_fifo_cliente);
    unlink(fifo_cliente);
  }

  if(closedir(dir) == -1){

    perror("error cerrando directorio");
    exit(EXIT_FAILURE);
  }
  return EXIT_SUCCESS;

}
