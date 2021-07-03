/** 
 * @file SecuenciasKmer.cpp
 * @author Daniel Monjas Miguélez
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

#include "Kmer.h"
#include "SecuenciasKmer.h"

using namespace std;

const int K=5; /// Número de genes en el Kmer
const string VALIDOS="_atgc"; /// Caracteres vaĺidos

long maxKmer();
Kmer normalizaKmer(const Kmer & km);


long maxKmer(){
    return pow(VALIDOS.size(),K);
}

Kmer normalizaKmer(const Kmer & km){
    const int DIST_MAY_MIN='a'-'A';
    int frec_normalizada;
    string kmer_normalizado;
    bool coinciden=false;
    int util=K;
    
    frec_normalizada=km.getFrecuencia();
    kmer_normalizado=km.getCadena();
    
    while(kmer_normalizado.size() < util){
        kmer_normalizado.push_back('_');
    }
    
    if(frec_normalizada < 0)
        frec_normalizada=0;
    
    for(int i=0; i < kmer_normalizado.size(); i++){
        
        
        if((kmer_normalizado[i]<='Z')&&(kmer_normalizado[i]>='A'))
            kmer_normalizado[i]+=DIST_MAY_MIN;
        
        for(int j = 0; (j < VALIDOS.size())&&(coinciden==false);j++){
            if(kmer_normalizado[i]!=VALIDOS[j])
                coinciden=false;
            else
                coinciden=true;
        }
        
        if(coinciden==false)
            kmer_normalizado[i]='_';
        
        else
            coinciden=false;
        
            
        if(i>=(util))
            kmer_normalizado[i]='\0';
    }
           
    Kmer prueba;
    
    prueba.setCadena(kmer_normalizado);
    prueba.setFrecuencia(frec_normalizada);
    
    return prueba;


}


void SecuenciasKmer::reservarMemoria(long n){ 
    if(_conjunto==nullptr)
    _conjunto= new Kmer [n];
    
    else{
        _conjunto=nullptr;
        _conjunto=new Kmer [n];
        
    }
}

void SecuenciasKmer::liberarMemoria(){
    if(_conjunto!=nullptr)
        delete [] _conjunto;
}

SecuenciasKmer::SecuenciasKmer(){
    _conjunto=nullptr;
    _nKmer=0;
}

SecuenciasKmer::SecuenciasKmer(long nkm){
    if(_conjunto==nullptr)
        reservarMemoria(nkm);
    
    else{
        _conjunto=nullptr;
        reservarMemoria(nkm);
    }
}

SecuenciasKmer::~SecuenciasKmer(){
    liberarMemoria();
}

Kmer SecuenciasKmer::getPosicion(long p) const{
    if(_nKmer != 0){
        if((p >= 0)&&(p < _nKmer))
            return _conjunto[p];
    
        else
            cerr << "ERROR: posicion invalida" << endl;
    }

}

void SecuenciasKmer::setPosicion(long p, const Kmer & km){
    Kmer *copia=nullptr;
    Kmer auxiliar;
    
    if((p > 0)&&(p <= _nKmer)){
        _nKmer++;
        copia = new Kmer [_nKmer];
        
        for(int i = 0; i < _nKmer-1; i++){
            copia[i]=_conjunto[i];
        }
        
        liberarMemoria();
        
        _conjunto=copia;
        copia=nullptr;
        
        _conjunto[_nKmer-1]=_conjunto[p-1];
        _conjunto[p-1]=km;     
    }
    
    else
        cerr << "ERROR: posición inválida" << endl;
}

void SecuenciasKmer::deletePosicion(long p){
    Kmer *copia=nullptr;
    Kmer auxiliar;

    if((p >= 0)&&(p < _nKmer)&&(_nKmer >= 0)){
        for(int i = p ; i < _nKmer-1; i++)
            _conjunto[i]=_conjunto[i+1];
        
        _nKmer--;
        
        if(_nKmer != 0){
            copia = new Kmer [_nKmer];
        
            for(int i = 0; i < _nKmer; i++)
                copia[i]=_conjunto[i];
        
            liberarMemoria();
        
            _conjunto=copia;
            copia=nullptr;
        }
    }
    
    else
        cerr << "ERROR-> posicion invalida" << endl;   
}


long SecuenciasKmer::findKmer(const std::string& km, long inicial) const{
    bool encontrado=false;
    int posicion=0;
    
    if((inicial >= 0)&&(inicial < _nKmer)){
        for(int i = inicial; i < _nKmer && !encontrado; i++){
            if(_conjunto[i].getCadena()==km){
                encontrado=true;
                posicion=i;
            }
        }
        
        if(encontrado)
            return posicion;
        
        else
            return -1;
    }
    
    else
        cerr << "ERROR: posicion inicial no valida" << endl; cout << _nKmer;
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
    int posicion_elim=0;
    int contador=0;
    
    
    for(int i = 0; i < _nKmer; i++){    
        while((i < _nKmer)&&(getPosicion(i).getFrecuencia()==0)){
            deletePosicion(i);  
        }
    }
    
    
    if(_nKmer != 0){
        for(int i = 0; i < _nKmer-1; i++){
            posicion_elim=findKmer(getPosicion(i).getCadena(),i+1);
        
            if(posicion_elim >= 0){
                for(int j=posicion_elim; j < _nKmer; j++){
                    while((j < _nKmer)&&(getPosicion(i).getCadena() == getPosicion(j).getCadena())){
                        _conjunto[i].setFrecuencia(getPosicion(i).getFrecuencia()+ getPosicion(j).getFrecuencia());
                        deletePosicion(j);
                    }
                }
            }
        }
    }
}

void SecuenciasKmer::readSecuenciasKmer(){
    string secuencia;
    int frecuencia;
    
    cout << "Introduzca el numero de kmer que quiere insertar:" << endl;
    cin >> _nKmer;
    
    if(_nKmer > 0){
        reservarMemoria(_nKmer);
    
        for(int i = 0; i < _nKmer; i++){
            cin >> secuencia >> frecuencia;
        
            _conjunto[i].setCadena(secuencia);
            _conjunto[i].setFrecuencia(frecuencia);
            _conjunto[i]=normalizaKmer(_conjunto[i]);
        }
    }
}

void SecuenciasKmer::writeSecuenciasKmer(int frecmin) const{
    int contador=0;
    
    if(_nKmer > 0){
        for(int i = 0; i < _nKmer; i++)
            if(_conjunto[i].getFrecuencia() >= frecmin)
                contador++;
    
    
        cout << "Escribiendo " << contador << " kmers ..." << endl;
    
        for(int i = 0; i < _nKmer; i++){
            if(_conjunto[i].getFrecuencia() >= frecmin)
                cout << _conjunto[i].getCadena() << " " << _conjunto[i].getFrecuencia() << endl;
        }
    }
    
    else
        cout << "Escribiendo " << _nKmer << " kmers ... " << endl;
}

bool SecuenciasKmer::saveFichero(const char* fichero) const{
    ofstream salida;
    bool funciona=true;
    
    
    salida.open(fichero);
    
    if(salida){
        cout << "Guardando fichero " << fichero << endl;
        cout << "Escribiendo " << _nKmer << " kmers" << endl;
        salida << MAGIC << endl;
        salida << _nKmer << endl;
        
        for(int i = 0 ; i < _nKmer; i++)
            salida << _conjunto[i].getCadena() << " " << _conjunto[i].getFrecuencia() << endl;
        
        if(salida)
            funciona=true;
        
        else{
            cerr << "ERROR: en la escritura de datos en el fichero -> " << fichero << endl; 
            funciona=false;
        }
        
        salida.close();
        return funciona;
    }
    
    else
        cerr << "ERROR: en la apertura del fichero ->" << fichero << endl;
}

bool SecuenciasKmer::loadFichero(const char* fichero){
    string cadena;
    ifstream entrada;
    int frecuencia;
    Kmer insertar;
    bool funciona=true;

    
    entrada.open(fichero);
    
    if(entrada){
        cout << "Abriendo fichero " << fichero << " ..." << endl;
        entrada >> cadena;
        if(cadena==MAGIC){
            entrada >> _nKmer;
            cout << "Leyendo " << _nKmer << " kmers ..." << endl;
            reservarMemoria(_nKmer);
            
            for(int i = 0; i < _nKmer && entrada; i++){
                entrada >> cadena;
                entrada >> frecuencia;
                
                _conjunto[i].setCadena(cadena);
                _conjunto[i].setFrecuencia(frecuencia);
                _conjunto[i]=normalizaKmer(_conjunto[i]);
                
            }
            
            if(!entrada){
                cerr << "ERROR: en la lectura de datos del fichero -> " << fichero << endl;
                funciona=false;
                liberarMemoria();
            }
            
        }
        
        else{
            cerr << "ERROR: formato no reconocido" << endl;
            funciona=false;
        }
    
        return funciona;
        entrada.close();
    
    }
    else
        cerr << "ERROR: en la apertura del fichero -> " << fichero << endl;
    
}

