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

const int m_clientes=10;
const int m_proveedores=10;
const int num_productos=10;

template< int min, int max > int aleatorio()
{
  static default_random_engine generador( (random_device())() );
  static uniform_int_distribution<int> distribucion_uniforme( min, max ) ;
  return distribucion_uniforme( generador );
}

class Supermercado : public HoareMonitor
{
   private:
        int stock_productos[num_productos];
      CondVar cola[num_productos];
      CondVar cola_prov[num_productos];
   public:
   Supermercado(){
       for(int i=0; i < num_productos; i++){
           stock_productos[i]=5;
           cola[i]=newCondVar();
           cola_prov[i]=newCondVar();
       }
   }

   void comprar(int p,int n){
       if(stock_productos[p] > n){
           stock_productos[p]=stock_productos[p] - n;
           cout << "Se compra " << n << "unidades del producto " << p << endl;
       }

       else{
           cout << "Se pide reponer " << p << endl;
           cola_prov[p].signal();
           cola[p].wait();
       }

   }

   void reponer(int p, int n){
      stock_productos[p]+=n;
      cout << "SE repone el producto  " << p << endl;
      cola[p].signal();
   }
};

void funcion_hebra_cliente(MRef<Supermercado> monitor)
{
   int p,n;

   while (true)
   {
      p = aleatorio<0,num_productos>();
      n = aleatorio<10,20>();

      monitor->comprar(p,n);

      chrono::milliseconds duracion_produ( aleatorio<20,30>() );
      this_thread::sleep_for( duracion_produ );

   }

}

void  funcion_hebra_proveedor( MRef<Supermercado> monitor)
{
    int p,n;
   while(true)
   {
      p = aleatorio<0,num_productos>();
      n = aleatorio<10,20>();

      monitor->reponer(p,n);

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
       clientes[i]=thread(funcion_hebra_cliente,monitor);
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