#include <iostream>
#include <cassert>
#include <thread>
#include <mutex>
#include <random> // dispositivos, generadores y distribuciones aleatorias
#include <chrono> // duraciones (duration), unidades de tiempo
#include "Semaphore.h"
#include "HoareMonitor.h"

using namespace std;
using namespace HM;

int num_lectores= 10;
int num_escritores= 5;

template< int min, int max > int aleatorio()
{
  static default_random_engine generador( (random_device())() );
  static uniform_int_distribution<int> distribucion_uniforme( min, max ) ;
  return distribucion_uniforme( generador );
}

class Lec_Esc : public HoareMonitor
{
    private:
        int n_lec;      //número de lectores leyendo
        bool escrib;    //true si hay algún escritor escribiendo
        int n_escrituras; //numero de escrituras realizadas
        CondVar lectura;
        CondVar escritura;

    public:
        Lec_Esc(){
            n_lec=0;
            escrib=false;
            lectura=newCondVar();
            escritura=newCondVar();
            n_escrituras=0;
        }
        
        //Funciones ejecutadas por los lectores

        void ini_lectura(){
            if(escrib)              //Si hay alguien escribiendo se espera
                lectura.wait();

            n_lec++;                //Una vez se deje de escribir se aumenta el número de lectores en el momento y 
                                    //se avisa a otras hebras para que lean concurrentemente
            lectura.signal();
        }

        void fin_lectura(){
            n_lec--;                //Una vez termina de leer se disminuye el número de lectores en el momento

            if(n_lec == 0){         //Si no hay nadie que siga leyendo estonces se avisa al escritor para que siga escribiendo
                escritura.signal();
            }
        }

        //Funciones ejecutadas por los escritores
        void ini_escritura(){
            if (n_lec > 0 || escrib)        //Si hay alguien leyendo o escribiendo se espera a que termine
                escritura.wait();

            escrib=true;                    //Una vez no haya nadie leyendo o escribiendo se empieza a escribir
        }

        void fin_escritura(){
            escrib=false;                   //Se indica a todas las hebras que ya no se está escribiendo

            n_escrituras++;

            if(!escritura.empty())            //Si hay algún escritor esperando se le indica que puede escribir
                escritura.signal();
            
            else{                          //Si no lo hay se indica al siguiente lector que puede escribir (preferencia escritores)
                lectura.signal();
                n_escrituras = 0;
            }
        }
};

void lee(int num_lector){
    // calcular milisegundos aleatorios de duración de la acción de fumar)
   chrono::milliseconds duracion_leer( aleatorio<10,100>() );

   cout << "Lector " << num_lector << " empieza a leer." << endl << flush;

   this_thread::sleep_for( duracion_leer );

}

void escribir(int num_escritor){
    // calcular milisegundos aleatorios de duración de la acción de fumar)
   chrono::milliseconds duracion_escribir( aleatorio<20,150>() );

   cout << "Escribir " << num_escritor << " empieza a escribir." << endl << flush;

   this_thread::sleep_for( duracion_escribir );
}

void funcion_hebra_escritor(int num_escritor, MRef<Lec_Esc> lec_esc){
    while(true){
        lec_esc->ini_escritura();
        escribir(num_escritor);
        lec_esc->fin_escritura();
        chrono::milliseconds descanso( aleatorio<150,200>() );
        this_thread::sleep_for( descanso );
    }
}

void funcion_hebra_lectora(int num_lector, MRef<Lec_Esc> lec_esc){
    while(true){
        lec_esc->ini_lectura();
        lee(num_lector);
        lec_esc->fin_lectura();
        chrono::milliseconds descanso( aleatorio<10,100>() );
        this_thread::sleep_for( descanso );
    }
}

int main(int argc, char * argv[])
{
    MRef<Lec_Esc> lec_esc=Create<Lec_Esc>();
    thread lectores[num_lectores], escritores[num_escritores];

    for(int i=0; i < num_escritores; i++){
        escritores[i] = thread(funcion_hebra_escritor, i, lec_esc);
    }

    for(int i=0; i < num_lectores; i++){
        lectores[i] = thread(funcion_hebra_lectora, i, lec_esc);
    }

    for(int i=0; i < num_escritores; i++){
        escritores[i].join();
    }

    for(int i=0; i < num_lectores; i++){
        lectores[i].join();
    }

    return 0;
}