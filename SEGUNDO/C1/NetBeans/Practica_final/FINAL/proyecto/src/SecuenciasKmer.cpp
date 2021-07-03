/** 
 * @file SecuenciasKmer.cpp
 * @author Daniel Monjas Miguélez
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <string>

#include "Kmer.h"
#include "SecuenciasKmer.h"

using namespace std;



double SecuenciasKmer::distancia(const SecuenciasKmer & d) const {
    long posB;
    long posA = 0;
    double dist = 0.0;

    for (long i = 0; i < this->getSize(); ++i) {
        posB = d.findKmer (getPosicion(i).getCadena());
        if (posB < 0) {
            posB = getSize();
        }

        dist += abs(posA - posB);
        posA++;
    }
    return dist / (getSize() * getSize()); 
}

void SecuenciasKmer::reservarMemoria(long n){
    if(_conjunto!=nullptr){
        _conjunto=nullptr;
    }
    
    _nKmer=n;
    _conjunto= new Kmer [n];
}

void SecuenciasKmer::liberarMemoria(){
    if(_conjunto!=nullptr){
        delete [] _conjunto;
    }
        
    _conjunto=nullptr;
    _nKmer=0;    
}

void SecuenciasKmer::copiar(const SecuenciasKmer& otro){
    liberarMemoria();
    
    _nKmer=otro.getSize();
    reservarMemoria(_nKmer);
    
    
    for(int i=0; i < _nKmer;i++)
        setPosicion(i,otro.getPosicion(i));
    
}

SecuenciasKmer::SecuenciasKmer(){
    _conjunto=nullptr;
    _nKmer=0;
}

SecuenciasKmer::SecuenciasKmer(long nkm){
    _conjunto=nullptr;
    reservarMemoria(nkm);
    _nKmer=nkm;
}

SecuenciasKmer::SecuenciasKmer(const SecuenciasKmer& orig){
    _conjunto=nullptr;
    copiar(orig);
}

SecuenciasKmer::~SecuenciasKmer(){
    liberarMemoria();
}

SecuenciasKmer& SecuenciasKmer::operator=(const SecuenciasKmer& orig){
    if(this != & orig)
        liberarMemoria();
    
    copiar(orig);
    
    return *this;
}
    

Kmer SecuenciasKmer::getPosicion(long p) const{
    if(_nKmer > 0){
        if((p >= 0)&&(p < _nKmer))
            return _conjunto[p];
    
        else
            cerr << "ERROR: posicion invalida" << endl;
    }
}

void SecuenciasKmer::setPosicion(long p, const Kmer & km){
    
    if((p>=0)&&(p<_nKmer))
        _conjunto[p]=km;
    
    else
        cerr << "ERROR: la posicion no es valida " << endl;
     
}

void SecuenciasKmer::deletePosicion(long p){
    Kmer *copia=nullptr;
    Kmer auxiliar;

    if((p >= 0)&&(p < _nKmer)&&(_nKmer > 0)){
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


long SecuenciasKmer::findKmer(const std::string& km) const{
    bool encontrado=false;
    int posicion=0;
    
    if(_nKmer > 0){
        for(int i=0; (i < _nKmer)&&(!encontrado); i++){
            if(km==_conjunto[i].getCadena()){
                encontrado=true;
                posicion=i;
            } 
        }
    }
    
    else{
        cerr << "ERROR: el conjunto de kmers esta vacío" << endl;
        posicion=-1;
    }
    
    if(encontrado)
        return posicion;
    
    else
        return -1;
    
}

void SecuenciasKmer::ordenar(){
    int max_frecuencia;
    int posicion_max;
    Kmer intercambia;
    
    for(int i=0; i < _nKmer;i++){
        max_frecuencia=_conjunto[i].getFrecuencia();
        posicion_max=i;
        
        for(int j=i+1; j < _nKmer; j++){
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


bool SecuenciasKmer::saveFichero(const char* fichero) const{
    ofstream salida;
    bool funciona=false;
    
    
    salida.open(fichero);
    
    cout << "Abriendo fichero " << fichero << " ..." << endl;
    
    if(salida){
        
        salida << *this;
        
        if(salida){
            cout << "Se ha compleatado la escritura de datos" << endl;
            funciona=true;
        }
        
        else{
            cerr << "ERROR: en la escritura de datos " << endl;
            funciona=false;
        }
        
        salida.close();
    }
    
    else
        cerr << "ERROR: en la apertura del archivo " << fichero;
    
    return funciona;
}


bool SecuenciasKmer::loadFichero(const char* fichero){
    ifstream entrada;
    bool funciona=false;
    char formato[]="kmer";
    int contador=0;
    bool valido=true;
    
    
    for(int i=strlen(fichero)-4; (i < strlen(fichero))&&(valido); i++){
        if(fichero[i]==formato[contador])
            contador++;
        
        else
            valido=false;
    }
    
    if(valido){
        entrada.open(fichero);
        cout << "Abriendo fichero " << fichero << " ..." << endl;
    
        if(entrada){
            entrada >> *this;
        
            if(entrada){
                cout << "Se ha completado la lectura de datos" << endl; 
                funciona=true;
            }
            
            else{
                cerr << "ERROR: en la lectura de datos del fichero " << fichero << endl;
                funciona=false;
                liberarMemoria();
            }
            
            entrada.close();     
        }
    
        else
            cerr << "ERROR:en la apertura del fichero " << fichero << endl;
    }
    
    else
        cerr << "ERROR: el formato del fichero no es valido" << endl; 
    
    return funciona; 
}
std::istream & operator>>(std::istream & os, SecuenciasKmer & s){
    string entrada;
    int frecuencia=0;
    Kmer insertar;
    
    s.liberarMemoria();
    os>>entrada;
    
    if(entrada==MAGIC){
        os>>s._nKmer;
        cout << "Leyendo " << s._nKmer << " kmers ..." << endl;
        
        if(s._nKmer!=0){
            s.reservarMemoria(s._nKmer);

            for(int i=0; (i < s._nKmer)&&os;i++){ 
                os>> entrada;
                os>> frecuencia;
        
                insertar.setCadena(entrada);
                insertar.setFrecuencia(frecuencia);
        
                s.setPosicion(i,insertar);
            }
        }
    }
    
    else
        cerr << "ERROR:formato desconocido" << endl;
    
    return os;
}


std::ostream & operator<<(std::ostream & os, const SecuenciasKmer & s){
    os << MAGIC << endl;
    os << s.getSize() << endl;
    cout << "Escribiendo " << s.getSize() << " kmers ..." << endl;
    
    for(int i=0; (i < s.getSize())&&os; i++)
        os << s.getPosicion(i).getCadena() << " " << s.getPosicion(i).getFrecuencia() << endl;
    
    return os;
}
