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



/**
 * @brief Calcula el número de combinaciones posibles de trigramas
 * @return Un entero largo
 */
long maxKmer()  {
    return pow(VALIDOS.size(),K);
}

/**
 * @brief Normaliza un Kmer. La longitud debe ser exactamente la fijada por @p K y cualquier carácter
 * ausente o nó @p VALIDO debe ser sustituido por el carácter comodín @p VALIDOS[0].
 * Igualmente, cualquier carácter @p VALIDO debe pasarse a minúscula. Finalmente, la frecuencia
 * debe ser >= 0
 * @param km El Kmer a normalizar
 * @return Una copia normalizada de @p km
 */
Kmer normalizaKmer(const Kmer & km)  {
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

SecuenciasKmer::SecuenciasKmer(){
    Kmer inicial;
    
    inicial.setCadena("");
    inicial.setFrecuencia(0);
    _nKmer=0;
    _conjunto[0]=inicial;
    
}

bool SecuenciasKmer::addKmer(const Kmer& km){
    bool valido=true;
    Kmer medio;
    
    medio=km;
    medio=normalizaKmer(medio);
    
    if((_nKmer+1 >= 0)&&(_nKmer+1 <= _Max)){
        _conjunto[_nKmer]=medio;
        _nKmer++;
    }
    
    else{
        valido=false;
        cerr << "ERROR: no se pueden añadir mas kmers" << endl;
    }
    
    return valido;

    
    
}

Kmer SecuenciasKmer::getPosicion(long p) const{
    if(((p > -1)&&(p < _Max))&&(p < _nKmer)){
        return _conjunto[p];
    }
    
    else
        cerr << "ERROR: posicion no valida" << endl;
    
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

void SecuenciasKmer::deletePosicion(long p){
    if((p < _Max)&&(p < _nKmer)&&(p >= 0)){
        if(p==_nKmer-1)
            _nKmer--;
        
        else{
            for(int i = p; i < _nKmer-1; i++){
                _conjunto[i]=_conjunto[i+1];   
            }
        
        _nKmer--;
        }
    }
    
    else
        cerr << "ERROR: POSICION INCORRECTA" << endl;
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
        cerr << "ERROR: la posicion inicial no es valida" << endl;    
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
    int tope=_nKmer-1;
    
    for(int i = 0; i < tope; i++){
        posicion_elim=findKmer(_conjunto[i].getCadena(), i+1);
        
        if(posicion_elim > -1){
            for(int j = posicion_elim; j < tope+1; j++){
                
                while((_conjunto[i].getCadena()==_conjunto[j].getCadena())&&(j < _nKmer)){
                    _conjunto[i].setFrecuencia(_conjunto[i].getFrecuencia()+_conjunto[j].getFrecuencia());
                    deletePosicion(j);
                }
            }
        }        
    }
    
    tope=_nKmer;
    
    for(int i = 0; i < tope; i++){
        while((_conjunto[i].getFrecuencia()==0)&&(i < _nKmer))
            deletePosicion(i);
    }
    
    }
    


void SecuenciasKmer::readSecuenciasKmer(){
    int num_kmer;
    string secuencia;
    int frecuencia;
    Kmer nuevo_kmer;
    bool funciona;
    
    cout << "Introduzca el numero de kmers: " << endl;
    cin >> num_kmer;
    
    if(num_kmer <= 3000){
        for(int i = 0; i < num_kmer;i++){
        cout << "Introduzca el Kmer a introducir (primero el kmer, despues la frecuencia: " << endl;
        cin >> secuencia >> frecuencia;
    
        nuevo_kmer.setCadena(secuencia);
        nuevo_kmer.setFrecuencia(frecuencia);
        nuevo_kmer=normalizaKmer(nuevo_kmer);
    
        funciona=addKmer(nuevo_kmer);
    
        if(funciona)
            cout << "Añadido correctamente" << endl;
        }
    }
    
    else{
        cerr << "ERROR: demasiados kmers" << endl;
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

bool SecuenciasKmer::saveFichero(const char* fichero) const{
    bool funciona=true;
    ofstream salida;
    string kmer;
    int frecuencia;
    
    salida.open(fichero);
    
    if(salida){
        cout << "Guardando fichero " << fichero << endl;
        cout << "Escribiendo " << _nKmer << " kmers" << endl;
        salida << MAGIC << endl;
        salida << _nKmer << endl;
        
        for(int i = 0; i < _nKmer; i++)
            salida << _conjunto[i].getCadena() << " " << _conjunto[i].getFrecuencia() << endl;
        
        if(salida){
            salida.close();
            return funciona;
        }
        
        else{
            cerr << "ERROR: en la escritura de datos" << endl;
            salida.close();
            return funciona=false;
        }
    }
    
    else{
        cerr << "ERROR: en la apertura del fichero " << fichero << endl;
        return funciona=false;
    }      
}

bool SecuenciasKmer::loadFichero(const char* fichero){
    string cadena;
    int frecuencia;
    int num_kmer;
    ifstream entrada;
    bool funciona=true;
    Kmer introducir;
    
    entrada.open(fichero);
    cout << "Abriendo fichero " << fichero << endl;
    
    if(entrada){
        entrada >> cadena;
        
        if(cadena==MAGIC){
            entrada >> _nKmer;
            cout << "Leyendo " << _nKmer << " kmers" << endl;
            
            if(_nKmer <= _Max){
                for(int i = 0; i < _nKmer && entrada;i++){
                    entrada >> cadena;
                    if(entrada){
                    entrada >> frecuencia;
                
                    _conjunto[i].setCadena(cadena);
                    _conjunto[i].setFrecuencia(frecuencia);
                
                    _conjunto[i]=normalizaKmer(_conjunto[i]);
                    }
                }   
            
            
            if(entrada){
                entrada.close();
                return funciona;
            }
            
            else{
                cerr << "ERROR: en la lectura de datos" << endl;
                entrada.close();
                return funciona=false;
            }
        }
        
            else{
                entrada.close();
                cerr << "ERROR: numero de kmers incorrecto" << endl;
                return false;
            }
           
    }
        
        
        else{
            cerr << "ERROR: formato no reconocido" << endl;
            entrada.close();
            return funciona = false;
        }
    }
    
    else{
        cerr << "ERROR: en la apertura del fichero " << fichero << endl; 
        return funciona = false;
    }
}
    
    
