#include "cola.h"

using namespace std;

int main(int argc, char** argv) {
    cola<int> cola_inicial;
    
    cola_inicial.push_back(1);
    cola_inicial.push_back(2);
    cola_inicial.push_back(3);
    cola_inicial.push_back(4);
    
    for(int i=0; i < cola_inicial.size();i++){
        cout << cola_inicial.front() << endl;
        cola_inicial.pop_front();
        
        if(cola_inicial.empty())
            cout << "VACIA" << endl;
        
        else
            cout << "NO VACIA" << endl;
    }
    
    cola_inicial.push_back(5);
    cola_inicial.push_back(6); 
    
    cola<int> cola_secundaria(cola_inicial);
    
    for(int i=0; i < cola_secundaria.size(); i++){
        cout << cola_secundaria.front() << endl;
        cola_secundaria.pop_front();
    }
    
    cola_secundaria.push_back(7);
    cola_secundaria.push_back(8);
    
    cola_inicial.swap(cola_secundaria);
    
    for(int i=0; i < cola_secundaria.size(); i++){
        cout << "COLA_SECUNDARIA" << cola_secundaria.front() << endl;
        cola_secundaria.pop_front();
    }
    
    for(int i=0; i < cola_inicial.size(); i++){
        cout << "COLA_INICIAL" << cola_inicial.front() << endl;
        cola_secundaria.pop_front();
    }
    
    return 0;
}

