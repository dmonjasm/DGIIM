#include<stack>
#include "cola.h"

using namespace std;

template<class T>
cola<T>::cola(const cola<T>& c){
    pila=c.pila;
}
        
template<class T>
bool cola<T>::empty() const{
    return pila.empty();
}

template<class T>
void cola<T>::clear(){
    while(!pila.empty()){
        pila.pop();
    }

}

template<class T>
T cola<T>::front(){
    T devolver=0;
    if(!pila.empty()){
        stack<T> auxiliar;
        
        while(!pila.empty()){
            auxiliar.push(pila.top());
            pila.pop();
        }
        
        devolver=auxiliar.top();
        
        while(!auxiliar.empty()){
            pila.push(auxiliar.top());
            auxiliar.pop();
        }
        
        return devolver;
    }
    else{
        cerr << "La cola está vacía" << endl;
        return -1;
    }
    
    
}

template<class T>
const T & cola<T>::front() const{
    if(!pila.empty()){
        stack<T> auxiliar(pila);
        
        while(auxiliar.size()>1){
            auxiliar.pop();
        }
        
        return auxiliar.top();
    }  
}

template<class T>
void cola<T>::push_back(const T & elem){
    pila.push(elem);   
}

template<class T>
void cola<T>::pop_front(){
    if(!pila.empty()){
        stack<T> auxiliar;
        
        while(!pila.empty()){
            auxiliar.push(pila.top());
            pila.pop();
        }
        auxiliar.pop();
        
        while(!auxiliar.empty()){
            pila.push(auxiliar.top());
            auxiliar.pop();
        }
    }     
}

template<class T>
unsigned int cola<T>::size() const{
    return pila.size();
}

template<class T>
void cola<T>::swap(cola<T> & c){  
    if(!pila.empty()){
        cola<T> auxiliar(*this);
        
        while(!(*this).empty()){
            (*this).pop_front();
        }
        
        while(!c.empty()){
            (*this).push_back(c.front());
            c.pop_front();
        }
        
        while(!auxiliar.empty()){
            c.push_back(auxiliar.front());
            auxiliar.pop_front();
        }   
    }
}


