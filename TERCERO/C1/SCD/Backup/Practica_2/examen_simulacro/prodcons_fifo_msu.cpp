//Monjas Miguelez, Daniel

#include <iostream>
#include <cassert>
#include <thread>
#include <mutex>
#include <random>
#include <atomic>
#include "Semaphore.h"
#include "HoareMonitor.h"

using namespace std ;
using namespace HM ;

//**********************************************************************
// variables compartidas

const int num_items = 40 ,   // número de items
	       tam_vec   = 10 ;   // tamaño del buffer
atomic<int>   primera_libre(0); // primera celda libre del vector
atomic<int>   primera_ocupada(0); //primera celda del vector ocupada
int   buffer[tam_vec]; //vector de transporte

unsigned  cont_prod[num_items] = {0}, // contadores de verificación: producidos
          cont_cons[num_items] = {0}, // contadores de verificación: consumidos
          num_ocupadas=0;

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

class Productor_consumidor : public HoareMonitor
{
   private:
      int ingrediente_mostrador;
      CondVar cola_productor;
      CondVar cola_consumidora;
   public:
      Productor_consumidor(){
         cola_productor = newCondVar();
         cola_consumidora = newCondVar();
      }

      void meter_en_buffer(int dato){
         int indice;

         if(num_ocupadas == tam_vec)
            cola_productor.wait();

         buffer[primera_libre] = dato;
         indice = (primera_libre + 1) % tam_vec;
         primera_libre = indice;
         num_ocupadas++;

         cola_consumidora.signal();

      }

      int sacar_de_buffer(){
         int dato, indice;

         if(num_ocupadas == 0){
            cola_consumidora.wait();
         }

         dato = buffer[primera_ocupada];
         indice = (primera_ocupada+1)%tam_vec;
         primera_ocupada=indice;
         num_ocupadas--;

         cola_productor.signal();

         return dato;
      }

   
};

//----------------------------------------------------------------------

void  funcion_hebra_productora( MRef<Productor_consumidor> monitor )
{
   int indice;
   for( unsigned i = 0 ; i < num_items ; i++ )
   {
      int dato = producir_dato() ;
      
  
      monitor->meter_en_buffer(dato);

      // completar ........
   }
}

//----------------------------------------------------------------------

void funcion_hebra_consumidora( MRef<Productor_consumidor> monitor )
{
   for( unsigned i = 0 ; i < num_items ; i++ )
   {
      int dato ;
      // completar ......
      dato = monitor->sacar_de_buffer();

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

   MRef<Productor_consumidor> monitor = Create<Productor_consumidor>();
   thread hebra_productora ( funcion_hebra_productora , monitor),
          hebra_consumidora( funcion_hebra_consumidora , monitor);

   hebra_productora.join() ;
   hebra_consumidora.join() ;

   test_contadores();

   cout << "\t FIN \t" << endl;
}
