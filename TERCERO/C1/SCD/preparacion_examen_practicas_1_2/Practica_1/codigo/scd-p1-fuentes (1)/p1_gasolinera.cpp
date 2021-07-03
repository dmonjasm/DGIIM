#include <iostream>
#include <cassert>
#include <thread>
#include <mutex>
#include <random>
#include "Semaphore.h"

using namespace std ;
using namespace SEM ;

//******************************************************

int numero_coches= 10;
int coches_gasoil = 4;
int coches_gasolina = 6;
int surtidores_uso=0;
int num_surtidores=5;
Semaphore surtidor_gasolina=3;      //Semaforo que controlara los accesos a surtidores de gasolina
Semaphore surtidor_gasoil=2;        //Semaforo que controlara los accesos a surtidores de gasoil
Semaphore exclusion = 1;            //Semaforo para que la impresión de mensajes sea en exclusión mutua.

//******************************************************
template< int min, int max > int aleatorio()
{
  static default_random_engine generador( (random_device())() );
  static uniform_int_distribution<int> distribucion_uniforme( min, max ) ;
  return distribucion_uniforme( generador );
}
//*******************************************************
void repostar(int num_coche)
{
    chrono::seconds duracion_produ( aleatorio<1,2>() );

    cout << "El coche " << num_coche << " empieza a repostar(" << duracion_produ.count() << " segundos):" << endl << flush;
    cout << "Quedan " << num_surtidores-surtidores_uso << " sin usar." << endl << flush;

    this_thread::sleep_for( duracion_produ );

    cout << "El coche " << num_coche << " termina de respostar." << endl << flush;
}

//******************************************************
void funcion_hebra_gasolina(int num_coche)
{
    while (true)
    {
        sem_wait(surtidor_gasolina);

        sem_wait(exclusion);
        surtidores_uso++;
        sem_signal(exclusion);

        repostar(num_coche);

        sem_wait(exclusion);
        surtidores_uso--;
        sem_signal(exclusion);

        sem_signal(surtidor_gasolina);
    }
}

//******************************************************
void funcion_hebra_gasoil(int num_coche)
{
    while(true)
    {
        sem_wait(surtidor_gasoil);
        sem_wait(exclusion);
        surtidores_uso++;
        sem_signal(exclusion);

        repostar(num_coche);

        sem_wait(exclusion);
        surtidores_uso--;
        sem_signal(exclusion);
        sem_signal(surtidor_gasoil);
    }
}

int main(int argc, char * argv[])
{
    thread coches[numero_coches];

    for(int i=0; i < numero_coches; i++){
        if(i < coches_gasoil){
            coches[i] = thread(funcion_hebra_gasoil,i);
        }

        else{
            coches[i] = thread(funcion_hebra_gasolina,i);
        }
    }

    for(int i=0; i < numero_coches; i++){
        coches[i].join();
    }

    return 0;
}
