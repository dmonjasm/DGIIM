#include<stack>
#include "cola.h"

using namespace std;
template<class T>
bool cola<T>::empty() const{
    return normal.empty();
}

template<class T>
void cola<T>::clear(){
    normal.clear();
    reversa.clear();
}

template<class T>
T & cola<T>::front(){
    return reversa.top();
}

template<class T>
const T & cola<T>::front() const{
    return reversa.top();
}

template<class T>
void cola<T>::push_back(const T & elem){
    if(normal.empty()){
        normal.push(elem);
        reversa.push(elem);
    }
    
    else{
        normal.push(elem);
        reversa.clear();
        
        stack<T> auxiliar(normal);
        
        while(!auxiliar.empty()){
            reversa.push(auxiliar.top());
            auxiliar.pop();
        } 
    }     
}

template<class T>
void cola<T>::pop_front(){
    if(normal.size()>0 && normal.size()>0){
        if(normal.size()==1 && normal.size()==1){
            normal.pop();
            reversa.pop();
        }
        
        else{
            reversa.pop;
            normal.clear();
            stack<T> auxiliar(reversa);
            
            while(!auxiliar.empty()){
                normal.push(auxiliar.top());
                auxiliar.pop();
            }
        }        
    }     
}

template<class T>
unsigned int cola<T>::size() const{
    return normal.size();
}

template<class T>
void cola<T>::swap(cola<T>& c){
    cola<T> auxiliar(*this);
    
    this->clear();
    
    while(!c.empty()){
        this->push_back(c.front());
        c.pop_front();  
    }
    
    while(!auxiliar.empty()){
        c.push_back(auxiliar.front());
        auxiliar.pop_front();
    }
}

