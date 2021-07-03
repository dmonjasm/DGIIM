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

int m =3;   //numero de escritores
int n = 10; //numero de lectores
template< int min, int max > int aleatorio()
{
  static default_random_engine generador( (random_device())() );
  static uniform_int_distribution<int> distribucion_uniforme( min, max ) ;
  return distribucion_uniforme( generador );
}

class Lesc_Esc : public HoareMonitor
{
    private:
        bool escrib;
        int n_lec;
        CondVar lectura, escritura;

    public:
        Lesc_Esc(){
            escrib = false;
            n_lec = 0;
            lectura = newCondVar();
            escritura = newCondVar();
        }

        void ini_lectura(int i){
            if (escrib){
                lectura.wait();
            }

            n_lec++;

            cout << "El lector " << i << " empieza a leer" << endl;
            lectura.signal();
        }

        void fin_lectura(int i){
            cout << "El lector " << i << " termina de leer" << endl;
            n_lec--;



            if(n_lec == 0)
                escritura.signal();
        }

        void ini_escritura(int i){
            if(n_lec > 0 || escrib)
                escritura.wait();

            cout << "El escritor " << i << " empieza a escribir" << endl;
            escrib = true;
        }

        void fin_escritura(int i){
            escrib = false;

            cout << "El escritor " << i << " termina de escribir" << endl;

            if (!lectura.empty())
                lectura.signal();

            else
                escritura.signal();
        }


};

void leer_escribir(){
    chrono::milliseconds duracion_produ( aleatorio<10,100>() );
    this_thread::sleep_for( duracion_produ );
}

void proceso_lector(int i, MRef<Lesc_Esc> lector){
    while (true){
        lector->ini_lectura(i);
        leer_escribir();
        lector->fin_lectura(i);
        chrono::milliseconds duracion_produ( aleatorio<20,200>() );
        this_thread::sleep_for( duracion_produ );
    }
}

void proceso_escritor(int i, MRef<Lesc_Esc> escritor){
    while(true){
        escritor->ini_escritura(i);
        leer_escribir();
        escritor->fin_escritura(i);
    }
}

int main (int agrc, char* argv[]){

    MRef<Lesc_Esc> monitor = Create<Lesc_Esc>();

    thread escritores[m], lectores[n];

    for(int i=0; i < m; i++){
        escritores[i]=thread(proceso_escritor,i,monitor);
    }

    for(int i=0; i < n; i++){
        lectores[i] = thread(proceso_lector,i,monitor);
    }
        

    for(int i=0; i < m; i++){
        escritores[i].join();
    }

    for(int i = 0; i < n; i++){
        lectores[i].join();
    }

    return 0;
}