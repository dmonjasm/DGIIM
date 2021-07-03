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

int m_clientes=10;
int m_proveedores=10;
int num_productos=100;
int stock_productos[num_productos];
template< int min, int max > int aleatorio()
{
  static default_random_engine generador( (random_device())() );
  static uniform_int_distribution<int> distribucion_uniforme( min, max ) ;
  return distribucion_uniforme( generador );
}

class Supermercado : public HoareMonitor
{
   private:
      CondVar cola[num_productos];
      CondVar cola_prov[num_productos];
   public:
   Estanquero(){
       for(int i=0; i < num_productos; i++){
           stock_productos[i]=5;
           cola[i]=newCondVar();
           cola_prov[i]=newCondVar();
       }
   }

   void comprar(int p,int n){
       if(stock_productos[p] > n){
           stock_productos[p]=stock_productos[p] - n;
       }

       else{
           cola_prov[p].signal();
           cola[p].wait();
       }

   }

   void reponer(int p, int n){
      cola_prov[p].wait();
      stock_productos[p]+=n;
      cola[p].signal();
   }
};

void funcion_hebra_cliente(MRef<Estanquero> monitor)
{
   int p,n;

   while (true)
   {
      p = aleatorio<0,num_productos>;
      n = aleatorio<10,20>;

      monitor->comprar;

      chrono::milliseconds duracion_produ( aleatorio<20,30>() );
      this_thread::sleep_for( duracion_produ );

   }

}

void  funcion_hebra_proveedor( MRef<Estanquero> monitor)
{
   while(true)
   {
      p = aleatorio<0,num_productos>;
      n = aleatorio<10,20>;

      monitor->reponer;

      chrono::milliseconds duracion_produ( aleatorio<20,30>() );
      this_thread::sleep_for( duracion_produ );
   }
}

//----------------------------------------------------------------------

int main()
{
   MRef<Supermercado> monitor = Create<Supermercado>();
   thread clientes[m_clientes],proveedores[m_proveedores];

   for(int i=0; i < m_clientes; i++){
       clientes[i]=thread(funcion_hebra_cliente,monitor)
   }

   for(int i=0; i < m_proveedores; i++){
       proveedores[i]=thread(funcion_hebra_proveedor,monitor);
   }

   for(int i=0; i < m_clientes; i++){
       clientes[i].join();
   }

   for(int i=0; i < m_proveedores; i++){
       proveedores[i].join();
   }

   return 0;
}