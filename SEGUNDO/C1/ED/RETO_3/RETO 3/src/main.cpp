#include <stack>
#include <iostream>
#include "cola.h"

using namespace std;

void comprobacion(cola<int> cola){
    if(cola.empty()){
        cout << "Está vacía" << endl;
    }
    else{
        cout << "La cola no está vacía" << endl;
    }
}

int main(int argc, char** argv) {
    cola<int> cola_inicial;
    
    cout << "Se llena y se comprueba pop_front()..." << endl;
    
    cola_inicial.push_back(1);
    comprobacion(cola_inicial);
    
    cola_inicial.pop_front();
    
    cout << "pop_front() ejecutado..." << endl;
    comprobacion(cola_inicial);
    
    cout << "Se vuelve a llenar con distintos datos y comprobamos la función front()" << endl;
    cola_inicial.push_back(8);
    cola_inicial.push_back(5);
    cola_inicial.push_back(2);
    cola_inicial.push_back(3);
    cola_inicial.push_back(2);
    cola_inicial.push_back(3);
    
    
    for(int i=0; !cola_inicial.empty() ;i++){
        cout << cola_inicial.front() << endl;
        cola_inicial.pop_front();
    }
    
    comprobacion(cola_inicial);
    
    cout << "Procedemos ahora a llenar la cola con dos elementos..." << endl;
    cola_inicial.push_back(6);
    cola_inicial.push_back(9);
    
    cout << "Vemos que se ha llenado con algunos elementos..." << endl;
    
    comprobacion(cola_inicial);
    
    cout << "Ahora procedemos a vaciar la cola con el método clear()" << endl;
    
    cola_inicial.clear();
    
    comprobacion(cola_inicial);
    
    

    cola_inicial.push_back(6);
    cola_inicial.push_back(1);
    cola_inicial.push_back(2);
    cola_inicial.push_back(3);
    
    cout << "Se crea otra cola para llenarla e intercambiar sus datos con la cola anterior..." << endl;
    cola<int> cambia;
    
    cambia.push_back(4);
    cambia.push_back(9);
    
    cola_inicial.swap(cambia);
    
    cout << "COLA_1 tras el cambio: " << endl;

    for(int i=0; !cola_inicial.empty() ; i++){
        cout << cola_inicial.front() << endl;
        cola_inicial.pop_front();
    }
    
    cout << "COLA_2 tras el cambio: " << endl;
            
    for(int i=0;!cambia.empty(); i++){
        cout << cambia.front() << endl;
        cambia.pop_front();
    }
    
    if(cola_inicial.empty()&&cambia.empty())
        cout << "AMBAS PILAS ESTAN VACIAS" << endl;

    
    return 0;
}

