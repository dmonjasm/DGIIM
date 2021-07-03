/*
Exmamen de prácticas módulo 2 2018-2019
lanzador.c
Autor: Carlos Romero Cruz
 */


#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <time.h>


void Uso(){

  printf("Uso: lanzador <número de clientes> <dir_pathname>\n");
  exit(EXIT_FAILURE);
}

static void CHLD_HANDLE(){

  int pid = wait(NULL);
  char fifo_cliente[500];

  printf("Hijo %d finalizado", pid);
  sprintf(fifo_cliente, "FIFO.%d", pid);
  unlink(fifo_cliente);
}


int main(int argc, char **argv){

  int n_clientes = 0, i, fd_fifo_server, entrada, metadato, fd_fifo_cliente, info;
  char *directorio, *fifo_server = "FIFOpet", fifo_cliente[50];
  struct stat atrb;
  struct sigaction sign;
  pid_t pid, pid_cliente;

  //Configuración de SIGCHLD.
  sign.sa_handler = CHLD_HANDLE;
  sign.sa_flags = SA_RESTART;
  sigemptyset(&sign.sa_mask);

  if(sigaction(SIGCHLD, &sign, NULL) == -1){

    perror("error configurando señales");
    exit(EXIT_FAILURE);
  }
  
  //Comprobación de argumentos.
  if(argc != 3)
    Uso();

  else{

    n_clientes = strtol(argv[1], NULL, 10);
    directorio = argv[2];

    if(stat(directorio, &atrb) == -1){

      perror("error en la extracción de los atributos");
      exit(EXIT_FAILURE);
    }
    
    if(n_clientes <= 0 || !(S_ISDIR(atrb.st_mode)))
      Uso();
  }

  //Creación del fifo server.
  if(mkfifo(fifo_server, S_IRUSR|S_IWUSR) == -1){

    if(errno == EEXIST){

      unlink(fifo_server);
      mkfifo(fifo_server, S_IRUSR|S_IWUSR);
    }
    
    else{

      perror("error al crear el FIFO server");
      exit(EXIT_FAILURE);
    }
  }

  if( (fd_fifo_server = open(fifo_server, O_RDWR)) == -1){

    perror("error abriendo FIFO server");
    exit(EXIT_FAILURE);
  }

  
  //Creación de los procesos clientes.
  for(i = 0 ; i < n_clientes ; i++){

   
    if( (pid = fork()) == -1){

      perror("error creando proceso hijo");
      exit(EXIT_FAILURE);
    }

    else if(pid == 0){

      printf("Quedan %d\n", n_clientes-i);
      pid_cliente = getpid();
      printf("Creado cliente con pid %d\n", pid_cliente);
      sprintf(fifo_cliente, "FIFO.%d", pid_cliente);

      if(mkfifo(fifo_cliente, S_IRUSR|S_IWUSR) == -1){

	perror("error creando FIFO cliente");
	exit(EXIT_FAILURE);
      } 
      
      if( (fd_fifo_cliente = open(fifo_cliente, O_RDWR)) == -1){

	perror("error al abrir el FIFO cliente");
	exit(EXIT_FAILURE);
      }

      srand(time(NULL));
      entrada = (int) rand() % 21;
      metadato = rand() % 3;

      if(entrada == 0)
	entrada = 1;

      if(metadato == 0)
	metadato = 1;

      write(fd_fifo_server, &entrada, sizeof(entrada));
      write(fd_fifo_server, &metadato, sizeof(metadato));
      write(fd_fifo_server, &pid_cliente, sizeof(pid_cliente));
      
      if(read(fd_fifo_cliente, &info, sizeof(int)) == -1){

	perror("error en la lectura del FIFO cliente");
	exit(EXIT_FAILURE);
      }
      
      close(fd_fifo_cliente);
      unlink(fifo_cliente);

      if(info == -1)
	printf("Cliente %d: FALLO\n", pid_cliente);

      else{

	if(metadato == 1)
	  printf("Cliente %d: Número de inodo = %d\n", pid_cliente, info);

	else
	  printf("Cliente %d: Tamaño de archivo = %d\n", pid_cliente, info);

	exit(EXIT_SUCCESS);
      }
    }
  }

  //Ejecución del servidor
  if( (pid = fork()) == -1){

    perror("error al crear el proceso hijo");
    exit(EXIT_FAILURE);
  }

  else if(pid == 0){

    if(dup2(fd_fifo_server, STDIN_FILENO) == -1){

      perror("error en la duplicación de la entrada estándar");
      exit(EXIT_FAILURE);
    }
    
    if(execl("server", "server", directorio, NULL) == -1){

      perror("error al ejecutar el servidor");
      exit(EXIT_FAILURE);
    }

    close(STDIN_FILENO);
    exit(EXIT_SUCCESS);
  }

  else{

    close(fd_fifo_server);
    unlink(fifo_server);
  }
    
  return EXIT_SUCCESS;
}
