/**
 * @file main.cpp
 * @author MP
 */
#include <iostream>
#include <cstring>
#include <string>
#include "Kmer.h"
#include "SecuenciasKmer.h"

using namespace std;

void mensajeError() {
    cerr << "ERROR en la llamada" << endl;
    cerr << "   kmer [-i <fichero-entrada>] [-o <fichero-salida>]"<<endl;
    exit(1); 
}
 
int main(int narg, char *args[]) {
    SecuenciasKmer seq;
    string entrada="", salida="", arg;
    bool funciona=true;
    
    if (narg != 1 && narg != 3 && narg != 5)
        mensajeError();
    ///...
    if(narg == 5 || narg == 3){
        arg = args[1];
        
        if(arg=="-i")
            entrada = args[2];
        else if(arg=="-o")
            salida = args[2];
        else
            mensajeError();
        
        if(narg==5){
            arg= args[3];
            if(arg=="-i" && entrada=="")
                entrada= args[4];
            else if(arg == "-o" && salida=="")
                salida=args[4];
            else
                mensajeError();
        }  
    }
    
    if(entrada=="")
        seq.readSecuenciasKmer();
    else
        if(!seq.loadFichero(entrada.c_str())) {
            cerr << "ERROR en el fichero " << entrada << endl;
            exit(1);
        }
    
    cout << "Comprimiendo secuencia de kmers ..." << endl;
    seq.zipSecuenciasKmer();
    cout << "Ordenando secuencia de kmers ..." << endl;
    seq.ordenar();
    
    if(salida=="")
        seq.writeSecuenciasKmer();
    else
        if(!seq.saveFichero(salida.c_str())){
            cerr << "ERROR en el fichero " << salida << endl;
            exit(1);
        }
        

    
    return 0;    
}

        

