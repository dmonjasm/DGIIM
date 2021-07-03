/** 
 * @file SecuenciasKmer.cpp
 * @author Daniel Monjas Miguélez
*/

#include <string>
#include <iostream>
#include "SecuenciasKmer.h"

using namespace std;

SecuenciasKmer::SecuenciasKmer(){
    Kmer constructor;
    
    constructor.setCadena("_____");
    constructor.setFrecuencia(0);
    
    _nKmer=0;
    _conjunto[0]=constructor;
}

bool SecuenciasKmer::addKmer(const Kmer& km){
    bool valido=true;
    
    if((_nKmer+1 >= 0)&&(_nKmer+1 <= _Max)){
        _conjunto[_nKmer]=km;
        _nKmer++;
    }
    
    else{
        valido=false;
        cerr << "ERROR" << endl;
    }
    
    return valido;
        
}

Kmer SecuenciasKmer::getPosicion(long p) const{
    if(((p > -1)&&(p <= _Max))&&(p < _nKmer)){
        return _conjunto[p];
    }
    
    else
        cerr << "ERROR" << endl;
    
}

void SecuenciasKmer::setPosicion(long p, const Kmer& km){
    
    if((p > 0)&&(p+1 < _Max)&&(_nKmer+1 <= _Max)){   
        
        
        for(int i = _nKmer-1; i >= p-1; i--){
            _conjunto[i+1]=_conjunto[i];
        }
        _conjunto[p-1]=km;
        _nKmer++;
        
    }
  
}

long SecuenciasKmer::findKmer(const std::string& km, long inicial) const{
    int posicion;
    bool contenido=false;
    
    if((inicial >= 0)&&(inicial < _Max)){
        for(int i = inicial; i < _nKmer && !contenido; i++){
            if(_conjunto[i].getCadena()==km){
                posicion=i;
                contenido = true;
            }
            
            else
                contenido = false;
        }
        
        if(contenido)
            return posicion;
        
        else
            return -1;
            
        
    }
    
    else
        cerr << "ERROR" << endl;
    
}

void SecuenciasKmer::ordenar(){
    int max_frecuencia;
    int posicion_max;
    Kmer intercambia;
    
    for(int i=0; i < _nKmer;i++){
        max_frecuencia=_conjunto[i].getFrecuencia();
        posicion_max=i;
        
        for(int j=i; j < _nKmer; j++){
            if(max_frecuencia < _conjunto[j].getFrecuencia()){
                max_frecuencia = _conjunto[j].getFrecuencia();
                posicion_max = j;
            }
        }
        
        intercambia = _conjunto[i];
        _conjunto[i] = _conjunto[posicion_max];
        _conjunto[posicion_max] = intercambia;
         
    }
    
}

void SecuenciasKmer::zipSecuenciasKmer(){
    int posicion_elim;
    int tope=_nKmer-1;
    int frecuencia;
    int m=0;
    
    for(int i = 0; i < tope+1; i++){
        posicion_elim=findKmer(_conjunto[i].getCadena(),i+1);
        
        if(posicion_elim > -1){
            
            for(int j = posicion_elim; j < tope+1; j++){
                
                while(_conjunto[i].getCadena()==_conjunto[j].getCadena()){
                    
                    frecuencia=_conjunto[i].getFrecuencia()+_conjunto[j].getFrecuencia();
                    
                    _conjunto[i].setFrecuencia(frecuencia);
                    
                    for(int k=j; k <= tope; k++){
                            _conjunto[k]=_conjunto[k+1];
                    }
                    
                    _nKmer--;
                }

            }
            
        }
    }

        
}

void SecuenciasKmer::writeSecuenciasKmer(int frecmin) const{
    int num_kmer=0;
    
    for(int i = 0; i < _nKmer;i++){
        if(_conjunto[i].getFrecuencia() >= frecmin)
            num_kmer++;
    }
    
    
    cout << "Escribiendo " << num_kmer << " kmers " << endl;
    
    for(int i = 0; i <_nKmer; i++){
        if(_conjunto[i].getFrecuencia() >= frecmin)
            cout << _conjunto[i].getCadena() << " " << _conjunto[i].getFrecuencia() << endl;
    }
}
