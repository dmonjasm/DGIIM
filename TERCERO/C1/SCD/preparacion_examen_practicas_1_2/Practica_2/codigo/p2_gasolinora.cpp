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

using namespace std;
using namespace HM;

int num_hebras=10,
    num_gasolina=6,
    num_gasoil=4;

template< int min, int max > int aleatorio()
{
  static default_random_engine generador( (random_device())() );
  static uniform_int_distribution<int> distribucion_uniforme( min, max ) ;
  return distribucion_uniforme( generador );
}

class Gasolinera : public HoareMonitor
{
    private:
        CondVar gasoil,
                gasolina;
        int surtidores_gasoil,   //Surtidores libres gasoil
            surtidores_gasolina,  //Surtidores libres gasolina
            surtidores_uso;

    public:
        Gasolinera(){
            gasoil = newCondVar();
            gasolina = newCondVar();
            surtidores_gasoil=2;
            surtidores_gasolina=3;
            surtidores_uso=0;
        }

        void entra_coche_gasoil(int coche){
            if(surtidores_gasoil == 0)
                gasoil.wait();

            surtidores_gasoil--;
            surtidores_uso++;

            cout << "El coche " << coche << " entra a repostar gasoil." << endl << flush;
            cout << "Hay " << surtidores_uso << " en uso." << endl;
        }

        void entra_coche_gasolina(int coche){
            if(surtidores_gasolina == 0){
                gasolina.wait();
            }

            surtidores_gasolina--;
            surtidores_uso++;

            cout << "El coche " << coche << " entra a repostar gasolina." << endl << flush;
            cout << "Hay " << surtidores_uso << " en uso." << endl;
        }

        void sale_coche_gasoil(int coche){
            cout << "El coche " << coche << " sale de repostar gasoil." << endl << flush;
            surtidores_gasoil++;
            surtidores_uso--;
            cout << "Hay " << surtidores_uso << " en uso." << endl;
        }

        void sale_coche_gasolina(int coche){    
            cout << "El coche " << coche << " sale de repostar gasolina." << endl << flush;
            surtidores_gasolina++;
            surtidores_uso--;
            cout << "Hay " << surtidores_uso << " en uso." << endl;
        }
};

void Repostar(){
    chrono::milliseconds duracion_produ( aleatorio<10,100>() );
    this_thread::sleep_for( duracion_produ );
}

void Retraso(){
    chrono::milliseconds duracion_produ( aleatorio<10,100>() );
    this_thread::sleep_for( duracion_produ );
}

void fucniones_hebra_gasolina(MRef<Gasolinera> gasolinera, int coche){
    while(true){
        gasolinera->entra_coche_gasoil(coche);
        Repostar();
        gasolinera->sale_coche_gasoil(coche);
        Retraso();
    }
}

void fucniones_hebra_gasoil(MRef<Gasolinera> gasolinera, int coche){
    while(true){
        gasolinera->entra_coche_gasolina(coche);
        Repostar();
        gasolinera->sale_coche_gasolina(coche);
        Retraso();
    }
}

int main(int argc, char * argv[])
{
    MRef<Gasolinera> gasolinera = Create<Gasolinera>();

    thread coches[num_hebras];

    for(int i=0; i < num_hebras; i++){
        if(i < num_gasoil)
            coches[i]=thread(fucniones_hebra_gasoil,gasolinera,i);

        else
            coches[i]=thread(fucniones_hebra_gasolina,gasolinera,i);
    }

    for(int i=0; i < num_hebras; i++){
        if(i < num_gasoil)
            coches[i].join();

        else
            coches[i].join();
    }

    return 0;
}