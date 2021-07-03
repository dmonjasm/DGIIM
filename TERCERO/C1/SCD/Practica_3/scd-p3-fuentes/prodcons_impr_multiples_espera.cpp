// -----------------------------------------------------------------------------
//
// Sistemas concurrentes y Distribuidos.
// Práctica 3. Implementación de algoritmos distribuidos con MPI
//
// Archivo: prodcons2.cpp
// Implementación del problema del productor-consumidor con
// un proceso intermedio que gestiona un buffer finito y recibe peticiones
// en orden arbitrario
// (versión con un único productor y un único consumidor)
//
// Historial:
// Actualizado a C++11 en Septiembre de 2017
// -----------------------------------------------------------------------------

#include <iostream>
#include <thread> // this_thread::sleep_for
#include <random> // dispositivos, generadores y distribuciones aleatorias
#include <chrono> // duraciones (duration), unidades de tiempo
#include <mpi.h>

using namespace std;
using namespace std::this_thread ;
using namespace std::chrono ;

const int
   num_prod              = 5,
   num_cons              = 7,
   id_buffer             = num_prod,
   id_impresor           = num_prod+num_cons+1,
   num_procesos_esperado = num_prod+num_cons+2,  //Se espera un proceso más ya que se añade una hebra que comprueba que sea correcto
   num_items             = 35,                   //luego se esperan tantos procesos como num_prod+num_cons+ 1 buffer+ 1 test
   tam_vector            = 10,
   num_valores_producidos=num_items/num_prod,
   num_valores_consumidos=num_items/num_cons,
   longitud              = 1024;

const int 
   etiq_consumidor = 1,      //etiqueta de los mensajes del consumidor al buffer y viceversa
   etiq_productor= 0,
   etiq_impresor=2;

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

// ----------------------------------------------------------------------

void imprimir(const char * mensaje)
{
    int num_car=strlen(mensaje);
    MPI_Ssend(mensaje, num_car,MPI_CHAR, id_impresor,etiq_impresor,MPI_COMM_WORLD);
}

// ---------------------------------------------------------------------
// ptoducir produce los numeros en secuencia (1,2,3,....)
// y lleva espera aleatorio
int producir(int orden_productor)
{
   static int contador = orden_productor*num_valores_producidos;     //el primera valor que se produce es orden_productor*num_valores_producidos+1
   sleep_for( milliseconds( aleatorio<10,100>()) );
   contador++ ;

   return contador ;
}
// ---------------------------------------------------------------------

void funcion_productor(int orden_productor)
{
    char mensaje[1024];
   for ( unsigned int i=0; i < num_valores_producidos; i++ )   //Cada productor produce num_items/num_prod valores
   {
      // producir valor
      int valor_prod = producir(orden_productor);
      snprintf(mensaje, longitud,"El proceso productor %d ha producido el valor %d", orden_productor, valor_prod); //1
      imprimir(mensaje);
      // enviar valor
      snprintf(mensaje, longitud,"El proceso productor %d va a enviar el valor %d al buffer",orden_productor, valor_prod);//2
      imprimir(mensaje);
      MPI_Ssend( &valor_prod, 1, MPI_INT, id_buffer, etiq_productor, MPI_COMM_WORLD );
   }
}
// ---------------------------------------------------------------------

void consumir( int valor_cons,int orden_consumidor )
{
   // espera bloqueada
   sleep_for( milliseconds( aleatorio<110,200>()) );
}
// ---------------------------------------------------------------------

void funcion_consumidor(int orden_consumidor)
{
   int         peticion,
               valor_rec = 1 ;
   MPI_Status  estado ;
   char mensaje[1024];

   for( unsigned int i=0 ; i < num_valores_consumidos; i++ )
   {
      MPI_Ssend( &peticion,  1, MPI_INT, id_buffer, etiq_consumidor, MPI_COMM_WORLD);
      MPI_Recv ( &valor_rec, 1, MPI_INT, id_buffer, etiq_consumidor, MPI_COMM_WORLD, &estado );
      snprintf(mensaje, longitud,"El proceso consumidor %d ha recibido el valor %d del buffer", orden_consumidor, valor_rec);//3
      imprimir(mensaje);
      consumir( valor_rec, orden_consumidor);
      snprintf(mensaje,longitud,"El proceso consumidor %d ha consumido el valor %d", orden_consumidor, valor_rec); //4
      imprimir(mensaje);
   }
}
// ---------------------------------------------------------------------

void funcion_buffer()
{
   int        buffer[tam_vector],      // buffer con celdas ocupadas y vacías
              valor,                   // valor recibido o enviado
              primera_libre       = 0, // índice de primera celda libre
              primera_ocupada     = 0, // índice de primera celda ocupada
              num_celdas_ocupadas = 0, // número de celdas ocupadas
              tag_aceptable ;    // identificador de emisor aceptable
   MPI_Status estado ;                 // metadatos del mensaje recibido
   char mensaje[longitud];

   for( unsigned int i=0 ; i < num_items*2 ; i++ )
   {
      // 1. determinar si puede enviar solo prod., solo cons, o todos

      if ( num_celdas_ocupadas == 0 )               // si buffer vacío
         tag_aceptable = etiq_productor;       // $~~~$ solo prod.
      else if ( num_celdas_ocupadas == tam_vector ) // si buffer lleno
         tag_aceptable = etiq_consumidor;      // $~~~$ solo cons.
      else                                          // si no vacío ni lleno
         tag_aceptable = MPI_ANY_TAG;     // $~~~$ cualquiera

      // 2. recibir un mensaje del emisor o emisores aceptables

      MPI_Recv( &valor, 1, MPI_INT, MPI_ANY_SOURCE, tag_aceptable, MPI_COMM_WORLD, &estado );

      // 3. procesar el mensaje recibido

      switch( estado.MPI_TAG ) // leer etiqueta del mensaje en metadatos
      {
         case etiq_productor: // si ha sido el productor: insertar en buffer
            buffer[primera_libre] = valor ;
            primera_libre = (primera_libre+1) % tam_vector ;
            num_celdas_ocupadas++ ;
            snprintf(mensaje, longitud, "Buffer ha recibido el valor %d del productor", valor); //5
            imprimir(mensaje);
            break;

         case etiq_consumidor: // si ha sido el consumidor: extraer y enviarle
            valor = buffer[primera_ocupada] ;
            primera_ocupada = (primera_ocupada+1) % tam_vector ;
            num_celdas_ocupadas-- ;
            snprintf(mensaje, longitud, "Buffer envia el valor %d al consumidor", valor); //5
            imprimir(mensaje);
            MPI_Ssend( &valor, 1, MPI_INT, estado.MPI_SOURCE, etiq_consumidor, MPI_COMM_WORLD);
            break;
      }
   }
}

void funcion_impresor()
{   
    int num_char;
    int flag;
    MPI_Status estado;
    for(int i=0; i < num_items*6; i++){

       for(int i=0; i < num_prod+num_cons; i++){
          MPI_Iprobe(i, etiq_impresor,MPI_Comm MPI_COMM_WORLD, &flag, &estado);
       }

       if(flag==0){
        MPI_Probe(MPI_ANY_SOURCE,etiq_impresor,MPI_Comm MPI_COMM_WORLD, &estado);
       }

        MPI_Get_count(&estado,MPI_CHAR, &num_char);

        char * recibido=new char[num_char];

        MPI_Recv( recibido, num_char, MPI_CHAR, estado.MPI_SOURCE, etiq_impresor, MPI_COMM_WORLD, &estado);
        recibido[num_char]=0;
        cout << recibido << endl; 

        delete [] recibido;
        sleep_for(milliseconds(20));       
    }
}


// ---------------------------------------------------------------------

int main( int argc, char *argv[] )
{
   int id_propio, num_procesos_actual;

   // inicializar MPI, leer identif. de proceso y número de procesos
   MPI_Init( &argc, &argv );
   MPI_Comm_rank( MPI_COMM_WORLD, &id_propio );
   MPI_Comm_size( MPI_COMM_WORLD, &num_procesos_actual );

   if ( num_procesos_esperado == num_procesos_actual )
   {
      // ejecutar la operación apropiada a 'id_propio'
      if ( id_propio>=0 && id_propio< num_prod)
         funcion_productor(id_propio);
      else if ( id_propio==num_prod)
         funcion_buffer();
      else if(id_propio>(num_cons+num_prod))
         funcion_impresor();
      else
         funcion_consumidor(id_propio-num_prod-1);
   }
   else
   {
      if ( id_propio == 0 ) // solo el primero escribe error, indep. del rol
      { cout << "el número de procesos esperados es:    " << num_procesos_esperado << endl
             << "el número de procesos en ejecución es: " << num_procesos_actual << endl
             << "(programa abortado)" << endl ;
      }
   }

   // al terminar el proceso, finalizar MPI
   MPI_Finalize( );
   return 0;
}