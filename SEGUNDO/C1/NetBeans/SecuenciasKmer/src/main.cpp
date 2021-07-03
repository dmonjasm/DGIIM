/**
 * @file main.cpp
 * @author Daniel Monjas Miguélez
 */
#include <iostream>
#include <string>
#include <cmath>
#include "Kmer.h"
#include "SecuenciasKmer.h"

using namespace std;

const int K=5; /// Número de genes en el Kmer
const string VALIDOS="_atgc"; /// Caracteres vaĺidos

long maxKmer();
Kmer normalizaKmer(const Kmer & km);
 
int main() {
    long nkm;
    SecuenciasKmer seq;
    int frecuencia;
    Kmer kmer;
    bool admitido;
    /// ...
    cin >> nkm;
    cout << "Leyendo " << nkm << " Kmers"<<endl;
    /// ....
    
    for(int i = 0; i < nkm; i++){
        kmer.readKmer();
        cin >> frecuencia;
        kmer.setFrecuencia(frecuencia);
        
        kmer=normalizaKmer(kmer);
        
        admitido=seq.addKmer(kmer);

    }
    
    cout << "Comprimiendo secuencia de Kmers ..."<<endl;
    seq.zipSecuenciasKmer();
    cout << "Ordenando secuencia de kmers ..." << endl;
    seq.ordenar();
    seq.writeSecuenciasKmer();
    
    return 0;
}


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