//Monjas Miguelez, Daniel

#include <iostream>
#include <cassert>
#include <thread>
#include <mutex>
#include <random>
#include <atomic>
#include "Semaphore.h"

using namespace std ;
using namespace SEM ;

//**********************************************************************
// variables compartidas

const int num_items = 40 ,   // número de items
	       tam_vec   = 10 ;   // tamaño del buffer
atomic<int>   primera_libre(0); // primera celda libre del vector
atomic<int>   primera_ocupada(0); //primera celda del vector ocupada
int   buffer[tam_vec]; //vector de transporte

unsigned  cont_prod[num_items] = {0}, // contadores de verificación: producidos
          cont_cons[num_items] = {0}; // contadores de verificación: consumidos

Semaphore libre = tam_vec, ocupadas = 0, exclusion=1;


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

   cout << "producido: " << contador << endl << flush ;

   cont_prod[contador] ++ ;
   return contador++ ;
}
//----------------------------------------------------------------------

void consumir_dato( unsigned dato )
{
   assert( dato < num_items );
   cont_cons[dato] ++ ;
   this_thread::sleep_for( chrono::milliseconds( aleatorio<20,100>() ));

   cout << "                  consumido: " << dato << endl ;

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
   int indice;
   for( unsigned i = 0 ; i < num_items ; i++ )
   {
      int dato = producir_dato() ;
      
  
      sem_wait(libre);

      sem_wait(exclusion);
      buffer[primera_libre]=dato;

      indice = (primera_libre + 1) % tam_vec;
      primera_libre = indice;
      
      sem_signal(exclusion);
      
      sem_signal(ocupadas);

      // completar ........
   }
}

//----------------------------------------------------------------------

void funcion_hebra_consumidora(  )
{
   int indice;
   for( unsigned i = 0 ; i < num_items ; i++ )
   {
      int dato ;
      // completar ......
      sem_wait(ocupadas);

      sem_wait(exclusion);
      dato = buffer[primera_ocupada];
      indice = (primera_ocupada+1)%tam_vec;
      primera_ocupada=indice;
      sem_signal(exclusion);

      sem_signal(libre);

      consumir_dato( dato );     
    }
}
//----------------------------------------------------------------------

int main()
{
   cout << "--------------------------------------------------------" << endl
        << "Problema de los productores-consumidores (solución LIFO)." << endl
        << "--------------------------------------------------------" << endl
        << flush ;

   thread hebra_productora ( funcion_hebra_productora ),
          hebra_consumidora( funcion_hebra_consumidora );

   hebra_productora.join() ;
   hebra_consumidora.join() ;

   test_contadores();

   cout << "\t FIN \t" << endl;
}
