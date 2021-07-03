/** 
 * @file ContadorKmer.cpp
 * @author Daniel Monjas Miguélez
*/

#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <cstring>

#include "Kmer.h"
#include "SecuenciasKmer.h"
#include "ContadorKmer.h"

using namespace std;

void ContadorKmer::reservarMemoria(int npersonas){
    _nperfiles=npersonas;
    
    if(_contador!=nullptr)
        _contador=nullptr;
    
    _contador=new int* [npersonas];
    
    for(int i=0;i < npersonas;i++){
        _contador[i]=new int [_NKMER];
    }
}

void ContadorKmer::liberarMemoria(){
    if(_contador!=nullptr){
        
        for(int i=0;i < _nperfiles;i++){
            if(_contador[i]!=nullptr)
                delete [] _contador[i];
                
            _contador[i]=nullptr;
        }
        
        delete[] _contador; 
        _contador=nullptr;
    }
}

void ContadorKmer::copiar(const ContadorKmer& otro){
    liberarMemoria();
    
    _nperfiles=otro.getNumPerfiles();
    _NKMER=otro.getNumKmer();
    _VALIDOS=otro._VALIDOS;
    _K=otro._K;
    
    reservarMemoria(_nperfiles);
    
    for(int i=0;i < _nperfiles;i++){
        
        for(int j=0;j < _NKMER;j++)
            _contador[i][j]=otro._contador[i][j];      
    }  
}


Kmer ContadorKmer::normalizaKmer(const Kmer& ng) const{
    const int DISTANCIA_MAY_MIN='a'-'A';
    Kmer normalizado;
    string resultado(_K,'_');
    int frecuencia;
    bool permitido=true;
    
    for(int i=0;i < _K;i++)
        resultado[i]=normalizado.getCadena()[i];
    
    frecuencia=normalizado.getFrecuencia();
    
    for(int i=0;i < _K;i++){
        if((resultado[i]<'Z')||(resultado[i]>'A'))
                resultado[i]=resultado[i]+DISTANCIA_MAY_MIN;
    }
    
    for(int i=0;i < _K;i++){
        for(int j=0;j < _VALIDOS.size() && permitido;j++){
            if(resultado[i]==_VALIDOS[j])
                permitido=true;
            
            else
                permitido=false;    
        }
        
        if(!permitido)
            resultado[i]='_';
    }
    
    normalizado.setCadena(resultado);
    normalizado.setFrecuencia(frecuencia);
    
    return normalizado;  
}


long ContadorKmer::getIndiceKmer(const Kmer& t) const{
    int posicion=0;
    int indice=0;
    
    for(int i=0;i < _K;i++){
        
        for(int j=0; j < _VALIDOS.size();j++){
            if(t.getCadena()[_K-i-1]==_VALIDOS[j])
                posicion=j;
        }
        
        indice=indice+pow(_VALIDOS.size(),i)*posicion;
    }
    
    return indice;
}


Kmer ContadorKmer::getIndiceInversoKmer(long i) const{
    int indice=i;
    int frecuencia=0;
    int posiciones[_K];
    string cadena(_K,'_');
    int divisor=0;
    Kmer inverso;
    
    if((i>_NKMER)||(i<0))
        cerr << "ERROR: el índice introducido no es válido.";
                
    else{
        
        for(int j=0; j < _K; j++)
            posiciones[j]=0;
        
        posiciones[0]=i;
        
        for(int j=0; j < (_K-1); j++){
            divisor=pow(_VALIDOS.size(),(_K-1-j));
            posiciones[j+1]=(posiciones[j]%divisor);
            posiciones[j]=(posiciones[j]/divisor);
            
            cadena[j]=_VALIDOS[posiciones[j]]; 
        }
        
        cadena[_K-1]=_VALIDOS[posiciones[_K-1]];
        
        
        inverso.setCadena(cadena);
        frecuencia=_contador[0][indice];
        inverso.setFrecuencia(frecuencia);
        
        return inverso;
    }
}

ContadorKmer::ContadorKmer(){
    _contador=nullptr;
    _nperfiles=0;
    _VALIDOS=INI_VALIDOS;
    _K=INI_K;
    _NKMER= pow(_VALIDOS.size(),_K);
}

ContadorKmer::ContadorKmer(const std::string& validos, int k){
    _contador=nullptr;
    _nperfiles=0;
    _VALIDOS=validos;
    _K=k;
    _NKMER=pow(_VALIDOS.size(),_K);
}

ContadorKmer::ContadorKmer(const ContadorKmer& orig){
    liberarMemoria();
    
    for(int i=0; i < _nperfiles; i++)
        _contador[i]=nullptr;
    
    _contador=nullptr;
    copiar(orig);
}

ContadorKmer::~ContadorKmer(){
    liberarMemoria();
}

ContadorKmer& ContadorKmer::operator =(const ContadorKmer& orig){
    liberarMemoria();
    copiar(orig);
}

int ContadorKmer::getNumPerfiles() const{
    return _nperfiles;
}      

long ContadorKmer::getNumKmer() const{
    return _NKMER;
}

void ContadorKmer::addPerfil(){
    int **puntero=nullptr;

    if(_nperfiles >= 0){
        
        puntero=new int* [_nperfiles+1];
        
        for(int i=0; i < _nperfiles+1;i++){
            puntero[i]=new int [_NKMER];
        }
        
        for(int i=0;i < _nperfiles+1;i++){
            for(int j=0; j < _NKMER; j++){
                if(i==(_nperfiles))
                    puntero[i][j]=0;
                
                else
                    puntero[i][j]=_contador[i][j];
            }
        }
        
        liberarMemoria();
        _nperfiles++;
        _contador=puntero;
        puntero=nullptr;
        
    }
    
    else
        cerr << "ERROR:numero de perfil invalido" << endl;
}   


void ContadorKmer::addPerfil(SecuenciasKmer perfil){
    int indice=0;
    
    addPerfil();

    for(int i= 0; i < perfil.getSize(); i++){
        indice=getIndiceKmer(perfil.getPosicion(i));
        
        if(perfil.getPosicion(i).getFrecuencia()==0)
            _contador[_nperfiles-1][indice]++;
        
        else
            _contador[_nperfiles-1][indice] += perfil.getPosicion(i).getFrecuencia();
    }
}

bool ContadorKmer::addKmer(int perfil, const Kmer& tg){
    int indice=0;
    bool correcto=false;
    
    if((perfil < _nperfiles)&&(perfil >= 0)){
        indice=getIndiceKmer(tg);
    
        if(tg.getFrecuencia()==0)
            _contador[perfil][indice]++;
    
        else
            _contador[perfil][indice]+=tg.getFrecuencia();
        
        correcto=true;
    }
    
    else{
        cerr << "ERROR: el perfil buscado no existe";
        correcto=false;
    }
    
    return correcto;
}

SecuenciasKmer ContadorKmer::getSecuenciasKmer(int perfil, int frecmin) const{
    Kmer insertar;
    int j=0;
    int valido=0;
    
    
    for(int i=0; i < _NKMER; i++)
        if(_contador[perfil][i] >= frecmin)
            valido++;
    
    SecuenciasKmer salida(valido);
    
    for(int i=0; i < _NKMER; i++){
        if(_contador[perfil][i]>=frecmin){
            insertar.setCadena(getIndiceInversoKmer(i).getCadena());
            insertar.setFrecuencia(_contador[perfil][i]);
            
            salida.setPosicion(j,insertar);
            j++;  
        }      
    }
   
    salida.ordenar();
    return salida;        
}

bool ContadorKmer::calcularFrecuenciasKmer(int perfil, const char* nfichero){
    ifstream entrada;
    string cadena;
    string particion(_K,'_');
    bool valido=true;
    Kmer insercion;
    int contador=0;
    char formato[]="dna";
    
    for(int i=strlen(nfichero)-3; (i < strlen(nfichero))&&valido; i++){
        if(nfichero[i]==formato[contador])
            contador++;
        
        else
            valido=false;
    }

        if(valido){
        entrada.open(nfichero);
        cout << "Abriendo el fichero " << nfichero << " ..." << endl;
    
        if(entrada){
        
            entrada >> cadena;
            if(entrada){
            
                for(int i=0; (i < (cadena.size())-(_K-1))&&(valido); i++){
                    for(int j=0; j < _K; j++)
                        particion[j]=cadena[i+j];
                
                    insercion.setCadena(particion);
                    insercion.setFrecuencia(0);
                    valido=addKmer(perfil,insercion);
                } 
            
                cout << "Procesados " << (cadena.size()-_K+1) << " kmers ..." << endl;
            }
        
            else{
                cerr << "ERROR:en la lectura de datos en " << nfichero << endl;
                valido=false;
                liberarMemoria();
            }
        }
    
        else{
            cerr << "ERROR: en la apertura del fichero " << nfichero << endl;
            valido=false;
        
        }
    }
    
    else
        cerr << "ERROR: formato desconocido" << endl;

    return valido;
}
