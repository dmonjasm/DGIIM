#include <iostream>
#include <cassert>
#include <thread>
#include <mutex>
#include <random> // dispositivos, generadores y distribuciones aleatorias
#include <chrono> // duraciones (duration), unidades de tiempo
#include "Semaphore.h"
#include "HoareMonitor.h"

using namespace std;
using namespace HM;

//**********************************************************************
// plantilla de función para generar un entero aleatorio uniformemente
// distribuido entre dos valores enteros, ambos incluidos
// (ambos tienen que ser dos constantes, conocidas en tiempo de compilación)
//----------------------------------------------------------------------

const int num_fumadores = 3;
//int producidos = 0, consumidos = 0;

template< int min, int max > int aleatorio()
{
  static default_random_engine generador( (random_device())() );
  static uniform_int_distribution<int> distribucion_uniforme( min, max ) ;
  return distribucion_uniforme( generador );
}

//-------------------------------------------------------------------------
// Función que simula la acción de producir un ingrediente, como un retardo
// aleatorio de la hebra (devuelve número de ingrediente producido)

class Estanquero : public HoareMonitor
{
   private:
      int ingrediente_mostrador;
      CondVar cola_fumador[num_fumadores];
      CondVar cola_estanquero;
   public:
   Estanquero(){

      for(int i=0; i < 3; i++){
         cola_fumador[i] = newCondVar();
      }

      cola_estanquero = newCondVar();

      ingrediente_mostrador = -1;
   }

   void ponerIngrediente(int ingrediente){

      if(ingrediente_mostrador != -1){
         cout << "Me voy a dormir" << endl;
         cola_estanquero.wait();
      }

      cout << "Puesto en mostrador ingrediente " << ingrediente << endl;
      ingrediente_mostrador = ingrediente;
      cola_fumador[ingrediente].signal();

   }

   void obtenerIngrediente(int ingrediente){
      if(ingrediente_mostrador != ingrediente){
         cola_fumador[ingrediente].wait();
      }

      cout << "Fumador " << ingrediente << " : retira ingrediente " << ingrediente << endl << flush;

      ingrediente_mostrador = -1;

      if(!cola_estanquero.empty()){
         cout << "Valor cola " << cola_estanquero.get_nwt() << " despierto estanquero" << endl;
         cola_estanquero.signal();
      }
   }
};

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

void funcion_hebra_estanquero(MRef<Estanquero> Estanco)
{
   int i;

   while (true)
   {
      i = producir_ingrediente();
      Estanco->ponerIngrediente(i);
      //cout << "Se han producido " << producidos << " ingredientes " << endl;
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
void  funcion_hebra_fumador( MRef<Estanquero> Estanco,int num_fumador )
{
   while(true)
   {
      Estanco->obtenerIngrediente(num_fumador);
      //cout << "Se han consumido " << consumidos << " ingredientes" << endl;
      fumar(num_fumador);
   }
}

//----------------------------------------------------------------------

int main()
{
   MRef<Estanquero> monitor = Create<Estanquero>();
   thread estanquero, fumador[3];

   for(int i=0; i < num_fumadores; i++){
      fumador[i] = thread(funcion_hebra_fumador, monitor, i);
   }

   estanquero = thread(funcion_hebra_estanquero, monitor);

   estanquero.join();

   for(int i=0; i < num_fumadores; i++){
      fumador[i].join();
   }

   return 0;
}