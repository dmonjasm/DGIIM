#include <iostream>
#include <cassert>
#include <thread>
#include <mutex>
#include <random> // dispositivos, generadores y distribuciones aleatorias
#include <chrono> // duraciones (duration), unidades de tiempo
#include "Semaphore.h"
#include "HoareMonitor.h"

using namespace std ;
using namespace HM;

const int num_fumadores = 3;                             //Numero de fumadores que participan en el programa

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

class Estanco : public HoareMonitor
{
    private:
        int mostrador;
        CondVar estanquero;                     //Cola en la que espera el estanquero
        CondVar fumadores[num_fumadores];       //Colas en la que esperan los fumadores, cada uno la suya

    public:
        Estanco(){
            mostrador = -1;
            estanquero = newCondVar();
            
            for(int i=0; i < num_fumadores;i++){
                fumadores[i]=newCondVar();
            }
        }

        void ponerIngrediente(int ingre){
            cout << "Estanquero pone ingrediente " << ingre << " en mostrador." << endl;    //El estanquero pone un ingrediente y actualiza el mostrador
            mostrador = ingre;

            fumadores[ingre].signal();  //Avisa al fumador correspondiente para que recoja su tabaco
        }

        void esperarRecogidaIngrediente(){
            if(mostrador != -1){        //Si el mostrador no está vacío espera a que se recoga el ingrediente, sino continua
                estanquero.wait();
            }
        }

        void obtenerIngrediente(int i){
            if(mostrador != i){         //Si su ingrediente no esta en mostrador el fumador espera
                fumadores[i].wait();
            }

            cout << "Fumador recoge ingrediente " << i << " de mostrador." << endl;

            mostrador=-1;               //Si lo está lo recoge y pone el mostrador vacío

            if(!estanquero.empty())     //SI el estanquero está esperando es su cola lo despierta para que produzca más tabaco sino continua
                estanquero.signal();
        }
};

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

void funcion_hebra_estanquero( MRef<Estanco> monitor)
{

   while (true){
       int ingre = producir_ingrediente();

       monitor->ponerIngrediente(ingre);
       monitor->esperarRecogidaIngrediente();
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
void  funcion_hebra_fumador( int num_fumador, MRef<Estanco> monitor )
{
   while( true )
   {
       monitor->obtenerIngrediente(num_fumador);
       fumar(num_fumador);
   }
}

//----------------------------------------------------------------------

int main()
{
   thread estanquero, fumador[num_fumadores];
   MRef<Estanco> estanco = Create<Estanco>();

   estanquero = thread(funcion_hebra_estanquero, estanco);

   for(int i=0; i < num_fumadores; i++){
      fumador[i] = thread (funcion_hebra_fumador, i, estanco);
   }

   estanquero.join();

   for(int i = 0; i < num_fumadores; i++){
      fumador[i].join();
   }


   cout << "***** FIN *****" << endl;
   return 0;
}