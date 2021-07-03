// -----------------------------------------------------------------------------
//
// Sistemas concurrentes y Distribuidos.
// Práctica 3. Implementación de algoritmos distribuidos con MPI
//
// Archivo: prodcons.cpp
// Implementación del problema del productor-consumidor con
// un proceso intermedio que recibe mensajes síncronos de forma alterna.
// (versión con un único productor y un único consumidor)
//
// Historial:
// Actualizado a C++11 en Septiembre de 2017
// -----------------------------------------------------------------------------


#include <iostream>
#include <thread> // this_thread::sleep_for
#include <random> // dispositivos, generadores y distribuciones aleatorias
#include <chrono> // duraciones (duration), unidades de tiempo
#include <mpi.h>  // includes de MPI

using namespace std;
using namespace std::this_thread ;
using namespace std::chrono ;

// ---------------------------------------------------------------------
// constantes que determinan la asignación de identificadores a roles:
const int
   id_productor          = 0 , // identificador del proceso productor
   id_buffer             = 1 , // identificador del proceso buffer
   id_consumidor         = 2 , // identificador del proceso consumidor
   id_impresor           = 3 , // identificador del proceso impresor
   num_procesos_esperado = 4 , // número total de procesos esperado
   num_items             = 20, // numero de items producidos o consumidos
   longitud              = 1024;// longitud máxima de los mensajes

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
// ---------------------------------------------------------------------
// produce los numeros en secuencia (1,2,3,....)

int producir()
{
   static int contador = 0 ;
   sleep_for( milliseconds( aleatorio<10,200>()) );
   contador++ ;
   return contador ;
}
// ---------------------------------------------------------------------

void imprimir(const char * mensaje)
{
    int num_car=strlen(mensaje);
    MPI_Ssend(mensaje, num_car,MPI_CHAR, id_impresor,0,MPI_COMM_WORLD);
}

// ---------------------------------------------------------------------

void funcion_productor()
{
   char mensaje[longitud];
   for ( unsigned int i= 0 ; i < num_items ; i++ )
   {
      // producir valor
      int valor_prod = producir();
      snprintf(mensaje, longitud,"El proceso productor ha producido el valor %d", valor_prod); //1
      imprimir(mensaje);
      // enviar valor
      snprintf(mensaje, longitud,"El proceso productor va a enviar el valor %d al buffer",valor_prod);//2
      imprimir(mensaje);
      //cout << "Productor va a enviar valor " << valor_prod << endl << flush;
      MPI_Ssend( &valor_prod, 1, MPI_INT, id_buffer, 0, MPI_COMM_WORLD );
   }
}
// ---------------------------------------------------------------------

void consumir( int valor_cons )
{
   // espera bloqueada
   sleep_for( milliseconds( aleatorio<10,200>()) );
}
// ---------------------------------------------------------------------

void funcion_consumidor()
{
   char mensaje[longitud];
   int         peticion,
               valor_rec = 1 ;
   MPI_Status  estado ;

   for( unsigned int i=0 ; i < num_items; i++ )
   {
      MPI_Ssend( &peticion,  1, MPI_INT, id_buffer, 0, MPI_COMM_WORLD);
      MPI_Recv ( &valor_rec, 1, MPI_INT, id_buffer, 0, MPI_COMM_WORLD,&estado );
      snprintf(mensaje, longitud,"El proceso consumidor ha recibido el valor %d del buffer", valor_rec);//3
      imprimir(mensaje);
      //cout << "Consumidor ha recibido valor " << valor_rec << endl << flush ;
      consumir( valor_rec );
      snprintf(mensaje,longitud,"El proceso consumidor ha consumido el valor %d", valor_rec); //4
      imprimir(mensaje);
   }
}
// ---------------------------------------------------------------------

void funcion_buffer()
{
   char mensaje[longitud];
   int         valor ,
               peticion ;
   MPI_Status  estado ;

   for ( unsigned int i = 0 ; i < num_items ; i++ )
   {
      MPI_Recv( &valor, 1, MPI_INT, id_productor,  0, MPI_COMM_WORLD, &estado );
      snprintf(mensaje, longitud, "El proceso buffer ha recibido el valor %d del proceso productor", valor);//5
      imprimir(mensaje);
      //cout << "Buffer ha recibido valor " << valor << endl ;

      MPI_Recv ( &peticion, 1, MPI_INT, id_consumidor, 0, MPI_COMM_WORLD, &estado );
      snprintf(mensaje, longitud, "El proceso buffer ha recibido una petición de lectura del proceso consumidor");//6
      imprimir(mensaje);

      //cout << "Buffer va a enviar valor " << valor << endl ;
      snprintf(mensaje, longitud, "El proceso buffer va a enviar el valor %d al consumidor", valor);//7
      imprimir(mensaje);
      MPI_Ssend( &valor,    1, MPI_INT, id_consumidor, 0, MPI_COMM_WORLD);
   }
}

// ---------------------------------------------------------------------

void funcion_impresor()
{   
    int flag;
    int num_char;
    MPI_Status estado;
    for(int i=0; i < num_items*7; i++){
        for(int i=0; i < num_procesos_esperado-1; i++){
          MPI_Iprobe(i, 0,MPI_Comm MPI_COMM_WORLD, &flag, &estado);
       }

       if(flag==0){
        MPI_Probe(MPI_ANY_SOURCE,0,MPI_Comm MPI_COMM_WORLD, &estado);
       }

        MPI_Get_count(&estado,MPI_CHAR, &num_char);

        char * recibido=new char[num_char];

        MPI_Recv( recibido, num_char, MPI_CHAR, estado.MPI_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &estado);
        recibido[num_char]=0;
        cout << recibido << endl; 

        delete [] recibido;
        sleep_for(milliseconds(20));       
    }
}


//----------------------------------------------------------------------

int main( int argc, char *argv[] )
{
  int id_propio, num_procesos_actual; // ident. propio, núm. de procesos

  MPI_Init( &argc, &argv );
  MPI_Comm_rank( MPI_COMM_WORLD, &id_propio );
  MPI_Comm_size( MPI_COMM_WORLD, &num_procesos_actual );

  if ( num_procesos_esperado == num_procesos_actual )
  {
    if ( id_propio == id_productor )  // si mi ident. es el del productor
      funcion_productor();            //    ejecutar función del productor
    else if ( id_propio == id_buffer )// si mi ident. es el del buffer
      funcion_buffer();               //    ejecutar función buffer
    else if ( id_propio == id_impresor)//si mi ident. es el del impresor
      funcion_impresor();             //    ejecutar función impresora
    else                              // en otro caso, mi ident es consumidor
      funcion_consumidor();           //    ejecutar función consumidor
  }
  else if ( id_propio == 0 )  // si hay error, el proceso 0 informa
    cerr << "error: número de procesos distinto del esperado." << endl ;

  MPI_Finalize( );
  return 0;
}
// ---------------------------------------------------------------------
