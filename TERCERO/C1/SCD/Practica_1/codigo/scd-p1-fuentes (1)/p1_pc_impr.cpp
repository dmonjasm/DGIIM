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
	       tam_vec   = 10 ;   // tamaño del buffer
unsigned  cont_prod[num_items] = {0}, // contadores de verificación: producidos
          cont_cons[num_items] = {0}; // contadores de verificación: consumidos

int vec[tam_vec];                                   //Buffer por el que se intercambian datos entre el productor y el consumidor.
int primera_libre=0;                                //Primera posición del buffer libre la aumenta la hebra productora
int primera_ocupada=0;                              //La aumenta la hebra consumidora
int longitud=0;                                     //Longitud actual del buffer
Semaphore ocupadas=0, libres=tam_vec, exclusion=1;  //El semáforo exclusión asegura que cuando se modifique primera_libre y vec se haga en exclusión mutua
Semaphore impresora=0;                              //Semoforo que se encarga de sincronizar la hebra impresora
                                                    //Libres permite que la productora empiece a generar datos y que pueda seguir generandolos hasta al menos tam_vec
                                                    //Ocupadas obliga a la hebra consumidora a esperar hasta que se haya producido al menos un dato


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
   for( unsigned i = 0 ; i < num_items ; i++ )
   {
      int dato = producir_dato() ;

      sem_wait(libres);
      sem_wait(exclusion);                          //Aseguramos que dentro de la exclusión mutua se realice los accesos a primera_libre y primera_ocupada
      vec[primera_libre] = dato;                    
      primera_libre = (primera_libre+1)%tam_vec;    //Una vez introducido un dato en el buffer se actualiza primera_libre y se comprueba si el dato es múltiplo de 5

      if(dato % 5 == 0){
        if(primera_libre - primera_ocupada >= 0){       //Si dato es múltiplo de 5 entonces se determina los datos sin consumir en el vector
            longitud = primera_libre - primera_ocupada;
        }

        else{
            longitud = tam_vec - primera_ocupada + primera_libre;
        }

        sem_signal(impresora);                          //Se avisa a impresora para que imprima su correspondiente mensaje
        sem_wait(libres);                               //Se bloquea la hebra productora dentro de la exclusión mutua para que ninguna consumidora 
      }                                                 //pueda actualizar primera_ocupada modificando así la ocupación y dejando desfasado el mensaje de impresora.

      sem_signal(exclusion);
      sem_signal(ocupadas);
   }
}

//----------------------------------------------------------------------

void funcion_hebra_consumidora(  )
{

   for( unsigned i = 0 ; i < num_items ; i++ )
   {
      int dato;
      
      sem_wait(ocupadas);

      sem_wait(exclusion);
      dato=vec[primera_ocupada];
      primera_ocupada = (primera_ocupada+1)%tam_vec;
      sem_signal(exclusion);
      sem_signal(libres);

      consumir_dato( dato ) ;
    }
}
//----------------------------------------------------------------------

void funcion_hebra_impresora()
{
   for(int i=0; i < num_items/5; i++){
      sem_wait(impresora);

      cout << "La ocupación actual del vector es: " << longitud << endl;

      sem_signal(libres);
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
          hebra_consumidora( funcion_hebra_consumidora ),
          hebra_impresora(funcion_hebra_impresora);

   hebra_productora.join() ;
   hebra_consumidora.join() ;
   hebra_impresora.join() ;


   test_contadores();
}