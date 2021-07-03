//#include "stdafx.h"
#include <iostream>
#include <random>
#include <chrono>
#include <cstring>
#include <cstdio>
#include <mpi.h>

#include <thread> // this_thread::sleep_for


using namespace std;
using namespace std::this_thread ;
using namespace std::chrono ;

//---------------------------
template<int min, int max> int aleatorio()
{
  static default_random_engine generador((random_device())());
  static uniform_int_distribution<int> distribucion_uniforme(min,max);
  return distribucion_uniforme(generador);
}
//------------------------------------------
int main (int argc, char*argv[])
{
  static int contador=0;
  int rank, size, 
      flag= 0, primo,
      origen, valor;
  MPI_Request peticion;
  MPI_Status estado;
  int x= 0;
  int num= 0;
  int fin= -1;
  int num_secs;
//-------------------------------------
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  if (rank == 0){
  // el proceso con id== 0 comienza enviando el primer primo (x = 2) al proceso impresor, 
  // con id== size-1, y continua enviado los numeros impares: 3, 5, 7, 9... al pipeline de 
  // procesos hasta que recibe el mensaje de fin del proceso impresor y entonces termina
    x= 2;
    num= 1;
    MPI_Send(&x, 1, MPI_INT, size-1, 0, MPI_COMM_WORLD);
    while(fin<=0){
      num += 2;
      x= num;
      MPI_Send(&x, 1, MPI_INT, rank+1, 0, MPI_COMM_WORLD);
      num_secs= aleatorio<20,200>();
      sleep_for(milliseconds(num_secs));
      MPI_Irecv(&x, 1, MPI_INT, size-1,0, MPI_COMM_WORLD, &peticion);
      MPI_Test(&peticion, &fin, &estado); 
      if (fin>0)
         cout<<"El proceso "<<rank<<" recibe señal de acabar"<<endl;  
    }
    cout <<" El proceso inicial acaba"<<endl;
  }
  else if(rank == size - 1){
    //este proceso ha de recibir un numero de valores primos igual al de procesos que forman el pipeline
    //(desde id=0 hasta id=size-1) y mostrarlos en pantalla; cuando reciba el ultimo numero primo, ha de
    //enviar un mensaje de fin al resto de procesos para que terminen, lo cual se puede hacer con comodidad
    //utilizando la orden de envio colectivo: MPI_Bcast(&(mensaje_fin=i), 1, MPI_INT, size-1, MPI_COM_WORLD)
    int i= 0;
    int mensaje_fin;
    while (i<size - 1){
      MPI_Probe(MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, &estado);
      origen= estado.MPI_SOURCE;
      MPI_Recv(&primo, 1, MPI_INT, origen, 0, MPI_COMM_WORLD, &estado);
      cout<<"Número primo "<<primo<<" Recibido del proceso "<<origen<<endl;
      i++;
    }
    mensaje_fin=i;
    MPI_Bcast(&mensaje_fin, 1, MPI_INT, size-1, MPI_COMM_WORLD);
    for (i=size-2; i>=0; i--){
      MPI_Send(&mensaje_fin, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
      cout <<" El proceso impresor envia "<<mensaje_fin<<" al proceso "<<i<<endl;
     }
     cout <<" El proceso impresor acaba con valor de i= "<<i<<endl;
  }
  else{
  //se trata de un proceso del pipeline con id=1 hasta id= size-2
  //el primer valor que se recibe en cada filtro es un numero primo y se guarda en la variable 'valor'
  MPI_Recv(&valor, 1, MPI_INT, rank-1, 0, MPI_COMM_WORLD, &estado);
  //Y se lo tiene que enviar al proceso impresor para que lo imprima
  MPI_Send(&valor, 1, MPI_INT, size-1, 0, MPI_COMM_WORLD);
  //Mientras no reciba el mensaje de fin del proceso impresor, continua recibiendo
  //un numero del proceso anterior en el pipeline, comprueba que no es divisible por 'valor'
  //y lo envia al proceso que le sigue en el pipeline; si el numero recibido fuera divisible
  //por 'valor', entonces no lo envia
  while(fin<=0){
    MPI_Recv(&x, 1, MPI_INT, rank-1, 0, MPI_COMM_WORLD, &estado);
    if (rank<(size-2))
     if (x%valor != 0)
       MPI_Send(&x, 1, MPI_INT, rank+1, 0, MPI_COMM_WORLD);
    num_secs= aleatorio<20,200>();
    sleep_for(milliseconds(num_secs));
    MPI_Irecv(&x, 1, MPI_INT, size-1, 0, MPI_COMM_WORLD, &peticion);
    MPI_Test(&peticion, &fin, &estado);
    if (fin>0)
      cout<<"El proceso "<<rank<<" recibe señal de terminar"<<endl; 
    } 
  cout <<" El proceso "<<rank<<" acaba"<<endl;
  }
contador++;
MPI_Finalize();
}
