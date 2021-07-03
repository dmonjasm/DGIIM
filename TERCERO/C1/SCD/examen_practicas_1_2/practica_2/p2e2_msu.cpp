//Monjas Miguelez Daniel
// -----------------------------------------------------------------------------
//
// Sistemas concurrentes y Distribuidos.
// Seminario 2. Introducción a los monitores en C++11.
//
// archivo: prodcons_1.cpp
// Ejemplo de un monitor en C++11 con semántica SC, para el problema
// del productor/consumidor, con un único productor y un único consumidor.
// Opcion LIFO (stack)
//
// Historial:
// Creado en Julio de 2017
// -----------------------------------------------------------------------------


#include <iostream>
#include <iomanip>
#include <cassert>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <random>
#include "HoareMonitor.h"

using namespace std ;
using namespace HM;

constexpr int
   num_items  = 40 ;     // número de items a producir/consumir

mutex
   mtx ;                 // mutex de escritura en pantalla
unsigned
   cont_prod[num_items], // contadores de verificación: producidos
   cont_cons[num_items]; // contadores de verificación: consumidos

int num_consumidoras=8;
int num_productoras=4;
int num_hebras_computo=5;

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

int producir_dato(int hebra)
{
   static int contador = 0 ;
   this_thread::sleep_for( chrono::milliseconds( aleatorio<20,100>() ));
   mtx.lock();
   cout << "Hebra productora " << hebra << " producido: " << contador << endl << flush ;
   mtx.unlock();
   cont_prod[contador] ++ ;
   return contador++ ;
}
//----------------------------------------------------------------------

void consumir_dato( unsigned dato, int hebra )
{
   if ( num_items <= dato )
   {
      cout << " dato === " << dato << ", num_items == " << num_items << endl ;
      assert( dato < num_items );
   }
   cont_cons[dato] ++ ;
   this_thread::sleep_for( chrono::milliseconds( aleatorio<20,100>() ));
   mtx.lock();
   cout << "                Hebra consumidora " << hebra << " consumido: " << dato << endl ;
   mtx.unlock();
}
//----------------------------------------------------------------------

void ini_contadores()
{
   for( unsigned i = 0 ; i < num_items ; i++ )
   {  cont_prod[i] = 0 ;
      cont_cons[i] = 0 ;
   }
}

//----------------------------------------------------------------------

void test_contadores()
{
   bool ok = true ;
   cout << "comprobando contadores ...." << flush ;

   for( unsigned i = 0 ; i < num_items ; i++ )
   {
      if ( cont_prod[i] != 1 )
      {
         cout << "error: valor " << i << " producido " << cont_prod[i] << " veces." << endl ;
         ok = false ;
      }
      if ( cont_cons[i] != 1 )
      {
         cout << "error: valor " << i << " consumido " << cont_cons[i] << " veces" << endl ;
         ok = false ;
      }
   }
   if (ok)
      cout << endl << flush << "solución (aparentemente) correcta." << endl << flush ;
}

// *****************************************************************************
// clase para monitor buffer, version LIFO, semántica SC, un prod. y un cons.

class ProdConsSU : public HoareMonitor
{
 private:
 static const int           // constantes:
   num_celdas_total_buffer1 = 10,   //  núm. de entradas del buffer
   num_celdas_total_buffer2 = 15;
   
 int                        // variables permanentes
   buffer_inicial[num_celdas_total_buffer1],//  buffer de tamaño fijo, con los datos
   buffer_final[num_celdas_total_buffer2], //Segundo buffer de tamaño fijo
   primera_libre_inicial,         //  indice de celda de la próxima inserción del buffer inicial
   primera_libre_final,           //inidice de celda de la proxima inserción del buffer final
   primera_ocupada_final,        //inidice de la celda de la proxima extracción del buffer final
   num_celdas_ocupadas_final;
 CondVar         // colas condicion:
   ocupadas_final,                //  cola donde espera el consumidor (n>0)
   libres_final,                 //  cola donde espera el productor  (n<num_celdas_total)
   ocupadas_inicial,
   libres_inicial;

 public:                    // constructor y métodos públicos
   ProdConsSU(  ) ;           // constructor
   int  leerProd();                // extraer un valor (sentencia L) (consumidor)
   void escribirProd( int valor ); // insertar un valor (sentencia E) (productor)
   int  leerCons();
   void escribirCons( int valor );
} ;
// -----------------------------------------------------------------------------

ProdConsSU::ProdConsSU(  )
{
   primera_libre_final = 0 ;
   primera_libre_inicial = 0;
   primera_ocupada_final = 0;
   num_celdas_ocupadas_final = 0;
   ocupadas_inicial=newCondVar();
   libres_inicial=newCondVar();
   ocupadas_final=newCondVar();
   libres_final=newCondVar();

}
// -----------------------------------------------------------------------------
// función llamada por el consumidor para extraer un dato

int ProdConsSU::leerProd(  )
{

   // esperar bloqueado hasta que 0 < num_celdas_ocupadas
   if ( primera_libre_inicial == 0 )
      ocupadas_inicial.wait();

   // hacer la operación de lectura, actualizando estado del monitor
   assert( 0 < primera_libre_inicial  );
   primera_libre_inicial-- ;
   const int valor = buffer_inicial[primera_libre_inicial] ;


   // señalar al productor que hay un hueco libre, por si está esperando
   libres_inicial.signal();

   // devolver valor
   return valor ;
}
// -----------------------------------------------------------------------------

void ProdConsSU::escribirProd( int valor )
{

   // esperar bloqueado hasta que num_celdas_ocupadas < num_celdas_total
   if ( primera_libre_inicial == num_celdas_total_buffer1 )
      libres_inicial.wait();

   //cout << "escribir: ocup == " << num_celdas_ocupadas << ", total == " << num_celdas_total << endl ;
   assert( primera_libre_inicial < num_celdas_total_buffer1 );

   // hacer la operación de inserción, actualizando estado del monitor
   buffer_inicial[primera_libre_inicial] = valor ;
   primera_libre_inicial++ ;

   // señalar al consumidor que ya hay una celda ocupada (por si esta esperando)
   ocupadas_inicial.signal();
}

//-------------------------------------------------------------------------------

int ProdConsSU::leerCons(  )
{

   // esperar bloqueado hasta que 0 < num_celdas_ocupadas
   if ( num_celdas_ocupadas_final == 0 )
      ocupadas_final.wait();

   // hacer la operación de lectura, actualizando estado del monitor
   assert( 0 < num_celdas_ocupadas_final  );
   const int valor = buffer_final[primera_ocupada_final] ;
   primera_ocupada_final = (primera_ocupada_final+1)%num_celdas_total_buffer2;
   num_celdas_ocupadas_final--;


   // señalar al productor que hay un hueco libre, por si está esperando
   libres_final.signal();

   // devolver valor
   return valor ;
}
// -----------------------------------------------------------------------------

void ProdConsSU::escribirCons( int valor )
{

   // esperar bloqueado hasta que num_celdas_ocupadas < num_celdas_total
   if ( num_celdas_ocupadas_final == num_celdas_total_buffer2 )
      libres_final.wait();

   //cout << "escribir: ocup == " << num_celdas_ocupadas << ", total == " << num_celdas_total << endl ;
   assert( num_celdas_ocupadas_final < num_celdas_total_buffer2 );

   // hacer la operación de inserción, actualizando estado del monitor
   buffer_final[primera_libre_final] = valor ;
   primera_libre_final= (primera_libre_final+1)%num_celdas_total_buffer2 ;
   num_celdas_ocupadas_final++;

   // señalar al consumidor que ya hay una celda ocupada (por si esta esperando)
   ocupadas_final.signal();
}
// *****************************************************************************
// funciones de hebras

void funcion_hebra_productora( MRef<ProdConsSU> monitor, int num_productora )
{
   for( unsigned i = (num_items/num_productoras)*num_productora; i < (num_items/num_productoras)*(num_productora+1) ; i++ )
   {
      int valor = producir_dato(num_productora) ;
      monitor->escribirProd( valor );
   }
}
// -----------------------------------------------------------------------------

void funcion_hebra_consumidora( MRef<ProdConsSU> monitor, int num_consumidor)
{
   for( unsigned i = (num_items/num_consumidoras)*num_consumidor ; i < (num_items/num_consumidoras)*(num_consumidor+1) ; i++ )
   {
      int valor = monitor->leerCons();
      valor=(valor-3)/4;
      consumir_dato( valor, num_consumidor ) ;
   }
}
// -----------------------------------------------------------------------------

void funcion_hebra_computo( MRef<ProdConsSU> monitor, int num_computo)
{
    for(int i = 0; i < num_items/num_hebras_computo; i++){
        int valor = monitor->leerProd();
        valor=valor*4+3;
        monitor->escribirCons(valor);
    }
}

//_------------------------------------------------------------------------------
int main()
{
   cout << "-------------------------------------------------------------------------------" << endl
        << "Problema de los productores-consumidores (1 prod/cons, Monitor SU, buffer LIFO). " << endl
        << "-------------------------------------------------------------------------------" << endl
        << flush ;

   MRef<ProdConsSU> monitor = Create<ProdConsSU>();

   thread hebra_productora[num_productoras],
          hebra_consumidora[num_consumidoras],
          hebra_computos[num_hebras_computo];

    for(int i=0; i < num_productoras; i++){
        hebra_productora[i]=thread(funcion_hebra_productora, monitor, i);
    }

    for(int i=0; i < num_hebras_computo; i++){
        hebra_computos[i]=thread(funcion_hebra_computo, monitor, i);
    }

    for(int i=0; i < num_consumidoras; i++){
        hebra_consumidora[i] = thread(funcion_hebra_consumidora, monitor, i);
    }

   for(int i=0; i < num_productoras; i++){
       hebra_productora[i].join();
   }

   for(int i=0; i < num_hebras_computo; i++){
       hebra_computos[i].join();
   }

   for(int i=0; i < num_consumidoras; i++){
       hebra_consumidora[i].join();
   }

   // comprobar que cada item se ha producido y consumido exactamente una vez
   test_contadores() ;
}
