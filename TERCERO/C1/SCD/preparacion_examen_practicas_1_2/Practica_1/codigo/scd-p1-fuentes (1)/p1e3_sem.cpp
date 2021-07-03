//Monjas Miguelez Daniel

#include <iostream>
#include <cassert>
#include <thread>
#include <mutex>
#include <random>
#include "Semaphore.h"

using namespace std ;
using namespace SEM ;

//**********************************************************************
// variables compartidas

const int num_items = 40 ,   // número de items
	       tam_vec   = 10,   // tamaño del buffer
           num_consumidores=5;  //numero de consumidores
unsigned  cont_prod[num_items] = {0}, // contadores de verificación: producidos
          cont_cons[num_items] = {0}; // contadores de verificación: consumidos

int vec[tam_vec];                                   //Buffer por el que se intercambian datos entre el productor y el consumidor.
int primera_libre=0;                                //Primera posición del buffer libre
int valor_consumido=0;                              //Variable global que contiene los valores una vez cada valor producido
Semaphore ocupadas=0, libres=tam_vec, exclusion=1;  //El semáforo exclusión asegura que cuando se modifique primera_libre y vec se haga en exclusión mutua
                                                    //Libres permite que la productora empiece a generar datos y que pueda seguir generandolos hasta al menos tam_vec
                                                    //Ocupadas obliga a la hebra consumidora a esperar hasta que se haya producido al menos un dato
Semaphore impresion=1;      //Semáforo para asegurar la exclusión mutua al imprimir mensajes en pantalla
Semaphore consume=0;        //Semáforo que sincorniza la hebra consume todo
Semaphore escribe=1;

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

//**********************************************************************
// funciones comunes a las dos soluciones (fifo y lifo)
//----------------------------------------------------------------------

int producir_dato()
{
   static int contador = 0 ;
   this_thread::sleep_for( chrono::milliseconds( aleatorio<20,100>() ));

   sem_wait(impresion); //Espera en el semaforo si hay alguien escribiendo
   cout << "producido: " << contador << endl << flush ;
   sem_signal(impresion); //Avisa de que ya se puede escribir.

   cont_prod[contador] ++ ;
   return contador++ ;
}
//----------------------------------------------------------------------

void consumir_dato( unsigned dato, int num_hebra )
{
   assert( dato < num_items );
   cont_cons[dato] ++ ;
   this_thread::sleep_for( chrono::milliseconds( aleatorio<20,100>() ));

   sem_wait(impresion);
   cout << "                 Hebra " << num_hebra << " consumido: " << dato << endl ;
   sem_signal(impresion);

}


//----------------------------------------------------------------------

void test_contadores()
{
   bool ok = true ;
   cout << "comprobando contadores ...." ;
   for( unsigned i = 0 ; i < num_items ; i++ )
   {  if ( cont_prod[i] != 1 )
      {  cout << "error: valor " << i << " producido " << cont_prod[i] << " veces." << endl ;
         ok = false ;
      }
      if ( cont_cons[i] != 1 )
      {  cout << "error: valor " << i << " consumido " << cont_cons[i] << " veces" << endl ;
         ok = false ;
      }
   }
   if (ok)
      cout << endl << flush << "solución (aparentemente) correcta." << endl << flush ;
}

//----------------------------------------------------------------------

void  funcion_hebra_productora(  )
{
   for( unsigned i = 0 ; i < num_items ; i++ )
   {
      int dato = producir_dato() ;

      sem_wait(libres);
      sem_wait(exclusion);
      vec[primera_libre] = dato;
      primera_libre++;

      sem_signal(exclusion);
      sem_signal(ocupadas);
   }
}

//----------------------------------------------------------------------

void funcion_hebra_consumidora( int num_hebra )
{

   for( unsigned i = 0 ; i < num_items/num_consumidores ; i++ )
   {
      int dato;
      
      sem_wait(ocupadas);
      sem_wait(exclusion);

      dato=vec[primera_libre-1];
      primera_libre--;

      sem_signal(exclusion);
      sem_signal(libres);

      sem_wait(escribe);
      valor_consumido=dato;
      sem_signal(consume);

      //Ya las hebras consumidoras no consumen el dato, sino que delegan en la que lo consume todo para ello
    }
}

//----------------------------------------------------------------------

void funcion_hebra_consume_todo(){
    int local=0;
    for(int i=0; i < num_items; i++){
        sem_wait(consume);
        local=valor_consumido;
        cout << "Se ha leido la variable compartida" << endl;
        sem_signal(escribe);
        consumir_dato(local,-1);
    }
}
//----------------------------------------------------------------------

int main()
{
   cout << "--------------------------------------------------------" << endl
        << "Problema de los productores-consumidores (solución LIFO)." << endl
        << "--------------------------------------------------------" << endl
        << flush ;

        for(int i=0; i < tam_vec; i++)
            vec[i]=0;

   thread hebra_productora ( funcion_hebra_productora ),
          hebra_consumidora[num_consumidores],
          hebra_consume_todo(funcion_hebra_consume_todo);

    for(int i=0; i < num_consumidores; i++){
        hebra_consumidora[i] = thread(funcion_hebra_consumidora, i);
    }

   hebra_productora.join() ;
   for(int i=0; i < num_consumidores; i++){
    hebra_consumidora[i].join() ;
   }

   hebra_consume_todo.join();

   test_contadores();
}