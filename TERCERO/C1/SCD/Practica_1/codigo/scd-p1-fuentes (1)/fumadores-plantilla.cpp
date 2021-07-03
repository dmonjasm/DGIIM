#include <iostream>
#include <cassert>
#include <thread>
#include <mutex>
#include <random> // dispositivos, generadores y distribuciones aleatorias
#include <chrono> // duraciones (duration), unidades de tiempo
#include "Semaphore.h"

using namespace std ;
using namespace SEM ;

const int num_fumadores = 3;                             //Numero de fumadores que participan en el programa
Semaphore mostrador_vacio=1;                             //Semaforo que controla la ocupación del mostrador (1 ingrediente máximo)
Semaphore ingrediente_puesto[num_fumadores] = {0,0,0};   //Semaforos para controlar la espera de los fumadores hasta que su ingrediente esta dispuesto

//**********************************************************************
// plantilla de función para generar un entero aleatorio uniformemente
// distribuido entre dos valores enteros, ambos incluidos
// (ambos tienen que ser dos constantes, conocidas en tiempo de compilación)
//----------------------------------------------------------------------

template< int min, int max > int aleatorio()
{
  static default_random_engine generador( (random_device())() );
  static uniform_int_distribution<int> distribucion_uniforme( min, max ) ;
  return distribucion_uniforme( generador );
}

//-------------------------------------------------------------------------
// Función que simula la acción de producir un ingrediente, como un retardo
// aleatorio de la hebra (devuelve número de ingrediente producido)

int producir_ingrediente()
{
   // calcular milisegundos aleatorios de duración de la acción de fumar)
   chrono::milliseconds duracion_produ( aleatorio<10,100>() );

   // informa de que comienza a producir
   cout << "Estanquero : empieza a producir ingrediente (" << duracion_produ.count() << " milisegundos)" << endl;

   // espera bloqueada un tiempo igual a ''duracion_produ' milisegundos
   this_thread::sleep_for( duracion_produ );

   const int num_ingrediente = aleatorio<0,num_fumadores-1>() ;

   // informa de que ha terminado de producir
   cout << "Estanquero : termina de producir ingrediente " << num_ingrediente << endl;

   return num_ingrediente ;
}

//----------------------------------------------------------------------
// función que ejecuta la hebra del estanquero

void funcion_hebra_estanquero(  )
{
   int tabaco;

   while (true){
      tabaco = producir_ingrediente();

      sem_wait(mostrador_vacio);
      cout << "Puesto ingrediente " << tabaco << endl;
      sem_signal(ingrediente_puesto[tabaco]);
   }
}

//-------------------------------------------------------------------------
// Función que simula la acción de fumar, como un retardo aleatoria de la hebra

void fumar( int num_fumador )
{

   // calcular milisegundos aleatorios de duración de la acción de fumar)
   chrono::milliseconds duracion_fumar( aleatorio<20,200>() );

   // informa de que comienza a fumar

    cout << "Fumador " << num_fumador << "  :"
          << " empieza a fumar (" << duracion_fumar.count() << " milisegundos)" << endl;

   // espera bloqueada un tiempo igual a ''duracion_fumar' milisegundos
   this_thread::sleep_for( duracion_fumar );

   // informa de que ha terminado de fumar

    cout << "Fumador " << num_fumador << "  : termina de fumar, comienza espera de ingrediente." << endl;

}

//----------------------------------------------------------------------
// función que ejecuta la hebra del fumador
void  funcion_hebra_fumador( int num_fumador )
{
   while( true )
   {
      sem_wait(ingrediente_puesto[num_fumador]);
      cout << "Retirado ingrediente: " << num_fumador << endl;
      sem_signal(mostrador_vacio);

      fumar(num_fumador);
   }
}

//----------------------------------------------------------------------

int main()
{
   thread estanquero, fumador[num_fumadores];

   estanquero = thread(funcion_hebra_estanquero);

   for(int i=0; i < num_fumadores; i++){
      fumador[i] = thread (funcion_hebra_fumador, i);
   }

   estanquero.join();

   for(int i = 0; i < num_fumadores; i++){
      fumador[i].join();
   }


   cout << "***** FIN *****" << endl;
   return 0;
}
