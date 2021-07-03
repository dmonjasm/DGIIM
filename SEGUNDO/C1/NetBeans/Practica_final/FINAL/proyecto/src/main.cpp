/**
 * @file main.cpp
 * @author Daniel Monjas Miguélez
 */
#include <iostream>
#include <string>
#include "Kmer.h"
#include "SecuenciasKmer.h"
#include "ContadorKmer.h"

using namespace std;

void mensajeError();

const string ContadorKmer::INI_VALIDOS = "_acgt";
const int ContadorKmer::INI_K=5;


int main(int narg, char *args[]) {
    SecuenciasKmer secuencia;
    ContadorKmer base_datos;
    string modo;
    bool funciona=true;
    int sugerencia=0;
    int perfiles[narg-3];
    double minimo=1;
    
    if(narg < 4)
        mensajeError();
    
    else{
        modo=args[1];
        
        if(modo=="-l"){
            if(!secuencia.loadFichero(args[2])){
                cerr << "ERROR: el fichero no existe" << endl;
                
                base_datos.addPerfil();
            }
            
            else
                base_datos.addPerfil(secuencia);
            
            
            for(int i=3; (i < narg); i++){
                funciona=base_datos.calcularFrecuenciasKmer(0,args[i]);
                
                if(!funciona)
                    cerr << "ERROR: en el fichero " << args[i] << endl;
            }
             
            
            
            cout << "Lectura de datos finalizada" << endl;
            
            secuencia=base_datos.getSecuenciasKmer(0,1);
            
            secuencia.saveFichero(args[2]);
        }
        
        else{
            
            if(modo=="-c"){
                int perfiles[narg-3];
                int k=0;
                
                for(int i=0; i < narg-3; i++)
                    perfiles[i]=0;
                
                base_datos.addPerfil();
                
                if(!base_datos.calcularFrecuenciasKmer(0,args[2])){
                    cerr << "ERROR: el fichero " << args[2] << " no existe" << endl;
                    exit(1);
                }
                
                for(int i=3; (i < narg); i++){
                    funciona=secuencia.loadFichero(args[i]);
                    
                    if(funciona){
                        base_datos.addPerfil(secuencia); 
                        perfiles[k]=i;
                        k++;                    
                    }
                }

                secuencia=base_datos.getSecuenciasKmer(0,1);
                
                if(base_datos.getNumPerfiles() > 1){
                    minimo=secuencia.distancia(base_datos.getSecuenciasKmer(1,1));
                
                    for(int i=1; (i < base_datos.getNumPerfiles()); i++){
                        if(secuencia.distancia(base_datos.getSecuenciasKmer(i,1)) <= minimo){
                            minimo=secuencia.distancia(base_datos.getSecuenciasKmer(i,1));
                            sugerencia=perfiles[i-1];
                        }
                    
                            cout << "[" << i << ", " << args[perfiles[i-1]] << "]=" << secuencia.distancia(base_datos.getSecuenciasKmer(i,1)) << endl;
                    }
                
                    cout << "Sugerencia= " << args[sugerencia] << endl;
                }
                
                else
                    cerr << "ERROR: no existen perfiles para calcular la distancia" << endl;
            }
            
            
            else
                mensajeError(); 
        }
    }
 
    return 0;
}

void mensajeError() {
    cerr << "ERROR en la llamada" << endl;
    cerr << "   kmer [-l f.kmer fa.dna [fn.dna]] [-c f.dna fa.kmer [fn.kmer]]"<<endl;
    exit(1); 
}