/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VD.cpp
 * Author: daniel
 * 
 * Created on 15 October 2019, 11:27
 */

#include <iostream>
using namespace std;

template <class T>
void VD<T>:: resize(int nuevotam){
    
    T *aux=new T [nuevotam];
    int minimo = (n<nuevotam)?n:nuevotam;
    for(int i=0; i < minimo; i++)
        aux[i] = datos[i];
    
    reservados = nuevotam;
    n = minimo;
    delete [] datos;
    datos = aux;    
}

template<class T>
void VD<T>::Copiar(const VD<T>& v){
    
    reservados = v.reservados;
    n = v.n;
    datos = new T[reservados];
    for(int i=0; i < n; i++)
        datos[i] = v.datos[i];

}

template <class T>
void VD<T>::Liberar(){
    
    delete [] datos;
}

template <class T>
VD<T>::VD(int tam){
    
    reservados = tam;
    datos = new T[reservados];
    n = 0;

}

template <class T>
VD<T>::VD(const VD<T>& original){
    
    Copiar(original);
}

template <class T>
VD<T>::~VD(){
    
    Liberar();
    
}

template <class T>
VD<T> & VD<T>::operator =(const VD<T>& v){
    
    if(this != &v){
        
        Liberar();
        Copiar(v);
    }
    
    return *this;
}

template <class T>
void VD<T>::Insertar(const T dato_insertar, const int indice_insertar){
    
    if (n >= (reservados/2))
        resize(2*reservados);
    
    for(int i=0; i > indice_insertar; i--)
        datos[i] = datos[i-1];
    
    datos[indice_insertar] = dato_insertar;
    n++;
    
}

template <class T>
void VD<T>::Borrar(const int indice_borrar){
    
    for(int i= indice_borrar; i < n-1; i++)
        datos[i] = datos[i+1];
    
    n--;
    
    if(n < (reservados/))
        resize(reservados/2);
}
