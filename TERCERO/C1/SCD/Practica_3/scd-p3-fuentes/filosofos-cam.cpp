// -----------------------------------------------------------------------------
//
// Sistemas concurrentes y Distribuidos.
// Práctica 3. Implementación de algoritmos distribuidos con MPI
//
// Archivo: filosofos-plantilla.cpp
// Implementación del problema de los filósofos (sin camarero).
// Plantilla para completar.
//
// Historial:
// Actualizado a C++11 en Septiembre de 2017
// -----------------------------------------------------------------------------


#include <mpi.h>
#include <thread> // this_thread::sleep_for
#include <random> // dispositivos, generadores y distribuciones aleatorias
#include <chrono> // duraciones (duration), unidades de tiempo
#include <iostream>

using namespace std;
using namespace std::this_thread ;
using namespace std::chrono ;

const int
   num_filosofos = 5 ,
   num_procesos  = 2*num_filosofos+1, //Se suma uno pues ahora hay un camarero
   id_camarero = 2*num_filosofos,     //Se pone el id del camarero como el id más alto
   etiq_levantarse = 1,               //Se establecen etiquetas para los mensajes solicitando sentarse y levantarse, el resto de mensajes sigue con etiqueta 0
   etiq_sentarse = 2;



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

void funcion_filosofos( int id )
{
  int id_ten_izq = (id+1)              % (num_procesos-1), //id. tenedor izq., a la hora de establecer los id de los tenedores hay que tener en cuenta de no contar el camarero
      id_ten_der = (id+num_procesos-2) % (num_procesos-1), //id. tenedor der. Le resto 2 en la primera parte pues si fuese -1 no tendría en cuenta el camarero y se podría dar que 
                                                           //id=0 (0+11-1)%(11-1)=0 que es par luego se mandaría un mensaje a algo que no es un tenedor
      solicita=0, libera=0, sienta=0, levanta=0; //Se establecen variables para los mensajes, se podría usar una para todos pues no importa el contenido de la variable.

  while ( true )
  {
    //El filósofo solicita sentarse a la mesa
    cout << "Filósofo " << id << " solicita sentarse al camarero." << endl << flush;
    MPI_Ssend(&sienta, 1,MPI_INT, id_camarero, etiq_sentarse, MPI_COMM_WORLD);
    cout << "Filósofo " << id << " se sienta a la mesa." << endl;

    cout <<"Filósofo " <<id << " solicita ten. izq." <<id_ten_izq <<endl<<flush;
    MPI_Ssend(&solicita,1, MPI_INT, id_ten_izq, 0, MPI_COMM_WORLD);
    cout << "Filósofo " << id << " ha adquirido ten. izq." << id_ten_izq <<endl <<flush;
    // ... solicitar tenedor izquierdo (completar)

    cout <<"Filósofo " <<id <<" solicita ten. der." <<id_ten_der <<endl<<flush;
    MPI_Ssend(&solicita,1, MPI_INT, id_ten_der, 0, MPI_COMM_WORLD);
    cout << "Filósofo " << id << " ha adquirido ten. der." << id_ten_der <<endl <<flush;
    // ... solicitar tenedor derecho (completar)

    cout <<"Filósofo " <<id <<" comienza a comer" <<endl << flush;
    sleep_for( milliseconds( aleatorio<10,100>() ) );

    cout <<"Filósofo " <<id <<" suelta ten. izq. " <<id_ten_izq <<endl << flush;
    MPI_Ssend(&libera,1, MPI_INT, id_ten_izq, 0, MPI_COMM_WORLD);
    cout << "Filósofo " << id << " ha soltado ten. izq." << id_ten_izq <<endl <<flush;
    // ... soltar el tenedor izquierdo (completar)

    cout<< "Filósofo " <<id <<" suelta ten. der. " <<id_ten_der <<endl <<flush;
    MPI_Ssend(&libera,1, MPI_INT, id_ten_der, 0, MPI_COMM_WORLD);
    cout << "Filósofo " << id << " ha soltado ten. der." << id_ten_der <<endl <<flush;
    // ... soltar el tenedor derecho (completar)

    //El filósofo se levanta de su asiento
    cout << "Filósofo " << id << " informa al camarero que se levanta." << endl << flush;
    MPI_Ssend(&levanta, 1,MPI_INT, id_camarero, etiq_levantarse, MPI_COMM_WORLD);

    cout << "Filosofo " << id << " comienza a pensar" << endl<< flush;
    sleep_for( milliseconds( aleatorio<10,100>() ) );
    cout << "Filósofo " << id << " termina de pensar" << endl <<flush;
 }
}
// ---------------------------------------------------------------------

void funcion_tenedores( int id )
{
  int valor, id_filosofo ;  // valor recibido, identificador del filósofo
  MPI_Status estado ;       // metadatos de las dos recepciones

  while ( true )
  {   
     // ...... recibir petición de cualquier filósofo (completar)
     MPI_Recv(&valor,1, MPI_INT, MPI_ANY_SOURCE, 0,MPI_COMM_WORLD, &estado);
     // ...... guardar en 'id_filosofo' el id. del emisor (completar)
     id_filosofo=estado.MPI_SOURCE;     
     cout <<"Ten. " <<id <<" ha sido cogido por filo. " <<id_filosofo <<endl<<flush;

     // ...... recibir liberación de filósofo 'id_filosofo' (completar)
     MPI_Recv(&valor,1,MPI_INT, MPI_ANY_SOURCE,0,MPI_COMM_WORLD,&estado);
     cout <<"Ten. "<< id<< " ha sido liberado por filo. " <<id_filosofo <<endl <<flush;
  }
}
// ---------------------------------------------------------------------

void funcion_camarero(int id)
{
    int filosofos_sentados=0, valor;
    MPI_Status estado;
    int tag_aceptado=0;

    while(true){
        if(filosofos_sentados<4){
            tag_aceptado=MPI_ANY_TAG;
        }

        else{
            tag_aceptado=etiq_levantarse;
        }
        
        MPI_Recv(&valor, 1, MPI_INT, MPI_ANY_SOURCE, tag_aceptado, MPI_COMM_WORLD, &estado);

        switch (estado.MPI_TAG)
        {
        case etiq_sentarse:
            cout << "El camarero permite al filósofo " << estado.MPI_SOURCE << " sentarse a la mesa" << endl<<flush;
            filosofos_sentados++;
            cout << "Actualmente hay " << filosofos_sentados << " sentados a la mesa" << endl<<flush;

            break;

        case etiq_levantarse:
            cout << "Se levanta de la mesa el filósofo " << estado.MPI_SOURCE << endl<<flush;
            filosofos_sentados--;
            cout << "Actualmente hay " << filosofos_sentados << " en la mesa" << endl<<flush;

            break;
        
        default:
            break;
        }
    }

}
// ---------------------------------------------------------------------

int main( int argc, char** argv )
{
   int id_propio, num_procesos_actual ;

   MPI_Init( &argc, &argv );
   MPI_Comm_rank( MPI_COMM_WORLD, &id_propio );
   MPI_Comm_size( MPI_COMM_WORLD, &num_procesos_actual );


   if ( num_procesos == num_procesos_actual )
   {
      // ejecutar la función correspondiente a 'id_propio'
      if ( id_propio % 2 == 0 && id_propio != id_camarero )          // si es par
         funcion_filosofos( id_propio ); //   es un filósofo
      else if(id_propio == id_camarero)  
         funcion_camarero(id_propio);
      else                            // si es impar
         funcion_tenedores( id_propio ); //   es un tenedor
   }
   else
   {
      if ( id_propio == 0 ) // solo el primero escribe error, indep. del rol
      { cout << "el número de procesos esperados es:    " << num_procesos << endl
             << "el número de procesos en ejecución es: " << num_procesos_actual << endl
             << "(programa abortado)" << endl ;
      }
   }

   MPI_Finalize( );
   return 0;
}

// ---------------------------------------------------------------------
