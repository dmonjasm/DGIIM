//Monjas Miguélez, Daniel
//Pregunta 1:
//¿Cual es el mínimo tiempo de espera que queda al final de las
//iteraciones del ciclo secundario con tu solución ?
//Teniendo en cuenta que para ejecutivo2.cpp Ts=500 milisegundos en cada iteración del ciclo secundario vemos el tiempo de ejecución
//i=1 tiempo de cálculo=450 milisegundos, espera=50 milisegundos
//i=2 tiempo de cálculo=490 milisegundos, espera=10 milisegundos
//i=3 tiempo de cálculo=450 milisegundos, espera=50 milisegundos
//i=4 tiempo de cálculo=250 milisegundos, espera=250 milisegundos
//Luego de aquí se deduce que el mínimo tiempo de espera es 10 milisegundos
//------------------------------------------------------------------------------
//Pregunta 2:
//¿Sería planificable si la tarea D tuviese un tiempo cómputo de 250 ms ?
//Teóricamente si lo sería, pues como la tarea D sólo se ejecuta en la iteración 2, y esta iteración tiene un tiempo de espera de 10ms
//sucedería que si aumentamos el tiempo de cálculo de la tarea D en 10 milisegundos la espera sería de 0 milisegundos, pero no se saldría del tiempo asignado a la iteración.
//En la práctica debemos tener en cuenta que seguramente haya un retraso respecto al tiempo esperado, aunque este sea muy pequeño. A pesar de esto el programa funcionaría,
//pues si bien puede haber un retraso, lo que implicaría que se coge tiempo asociado a la iteración 3, como la iteración 3 tiene una espera de 50 milisegundos, lo más probable es,
//que la ejecución de la iteración 3 no se salga de sus correspondientes 500 milisegundos, sino que se reducirá el tiempo de espera. Además con la restricción que hemos puesto
//el programa permite en cada iteración retrasos de hasta 20 milisegundos. Si hacemos el cambio especificado y mantenemos la planificación actual, vemos que el programa no se aborta.
// -----------------------------------------------------------------------------
// Sistemas concurrentes y Distribuidos.
// Práctica 4. Implementación de sistemas de tiempo real.
//
// Archivo: ejecutivo1.cpp
// Implementación del primer ejemplo de ejecutivo cíclico:
//
//   Datos de las tareas:
//   ------------
//   Ta.  T    C
//   ------------
//   A  250  100
//   B  250   80
//   C  500   50
//   D  500   40
//   E 1000   20
//  -------------
//
//  Planificación (con Ts == 250 ms)
//  *---------*----------*---------*--------*
//  | A B C   | A B D E  | A B C   | A B D  |
//  *---------*----------*---------*--------*
//
//
// Historial:
// Creado en Diciembre de 2017
// -----------------------------------------------------------------------------

#include <string>
#include <iostream> // cout, cerr
#include <thread>
#include <chrono>   // utilidades de tiempo
#include <ratio>    // std::ratio_divide
#include <cassert>  // para abortar el programa si no se comprueba la condición

using namespace std ;
using namespace std::chrono ;
using namespace std::this_thread ;

// tipo para duraciones en segundos y milisegundos, en coma flotante:
typedef duration<float,ratio<1,1>>    seconds_f ;
typedef duration<float,ratio<1,1000>> milliseconds_f ;

// -----------------------------------------------------------------------------
// tarea genérica: duerme durante un intervalo de tiempo (de determinada duración)

void Tarea( const std::string & nombre, milliseconds tcomputo )
{
   cout << "   Comienza tarea " << nombre << " (C == " << tcomputo.count() << " ms.) ... " ;
   sleep_for( tcomputo );
   cout << "fin." << endl ;
}

// -----------------------------------------------------------------------------
// tareas concretas del problema:

void TareaA() { Tarea( "A", milliseconds(100) );  }
void TareaB() { Tarea( "B", milliseconds( 150) );  }
void TareaC() { Tarea( "C", milliseconds( 200) );  }
void TareaD() { Tarea( "D", milliseconds( 240) );  }
//void TareaE() { Tarea( "E", milliseconds( 20) );  }

// -----------------------------------------------------------------------------
// implementación del ejecutivo cíclico:

int main( int argc, char *argv[] )
{
   // Ts = duración del ciclo secundario
   const milliseconds Ts( 500 ); //La duración que he elegido para el ciclo secundario

   // ini_sec = instante de inicio de la iteración actual del ciclo secundario
   time_point<steady_clock> ini_sec = steady_clock::now();
   time_point<steady_clock> check;
   steady_clock::duration retraso;

   while( true ) // ciclo principal
   {
      cout << endl
           << "---------------------------------------" << endl
           << "Comienza iteración del ciclo principal." << endl ;

      for( int i = 1 ; i <= 4 ; i++ ) // ciclo secundario (4 iteraciones)
      {
         cout << endl << "Comienza iteración " << i << " del ciclo secundario." << endl ;

         switch( i )
         {
            case 1 : TareaA(); TareaB(); TareaC();           break ;
            case 2 : TareaA(); TareaB(); TareaD();           break ;
            case 3 : TareaA(); TareaB(); TareaC();           break ;
            case 4 : TareaA(); TareaB();                     break ;
         }

         // calcular el siguiente instante de inicio del ciclo secundario
         ini_sec += Ts ;

         // esperar hasta el inicio de la siguiente iteración del ciclo secundario
         sleep_until( ini_sec );

         check=steady_clock::now(); //Se establece en check el instante en el que termina el ciclo secundario

         retraso=check-ini_sec; //Se guarda en duración la diferencia en milisegundos entre el instante final del ciclo secundario real y el esperado

         cout << "El retraso actual es " << milliseconds_f(retraso).count() << " milisegundos" << endl;

         assert(retraso <= milliseconds(20));  //Tras cada ciclo secundario se comprueba que el retraso no sea mayor que 20 milisegundos, si lo es se aborta el programa.  
      } 
   }
}
