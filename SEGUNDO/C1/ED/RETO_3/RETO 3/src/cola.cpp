#include<stack>
#include "cola.h"

using namespace std;
template<class T>
bool cola<T>::empty() const{
    return reversa.empty();
}

template<class T>
void cola<T>::clear(){
    for(int i=0; i < normal.size() && !normal.empty(); i++)
                normal.pop();
    for(int i=0; i < reversa.size() && !reversa.empty(); i++)
            reversa.pop();
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
        for(int i=0; i < reversa.size() && !reversa.empty(); i++)
            reversa.pop();
        
        stack<T> auxiliar(normal);
        
        while(!auxiliar.empty()){
            reversa.push(auxiliar.top());
            auxiliar.pop();
        } 
    }     
}

template<class T>
void cola<T>::pop_front(){
    if(normal.size()>0 && reversa.size()>0){
        if(normal.size()==1 && reversa.size()==1){
            normal.pop();
            reversa.pop();
        }
        
        else{
            reversa.pop();

            while(!normal.empty()){
		normal.pop();
	    }
            
            stack<T> auxiliar(reversa);
            
            while(!auxiliar.empty()){
		normal.push(auxiliar.top());
		auxiliar.pop();
		
            }
        }        
    }
    
    cout << "LA COLA ESTÁ VACÍA" << endl;      
}

template<class T>
unsigned int cola<T>::size() const{
    return reversa.size();
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

