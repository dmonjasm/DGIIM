#include "acciones.h"
#include <map>
#include <string>
#include <iostream>

using namespace std;


std::istream & operator >>(std::istream &is, acciones & entrada){
    string primero;
    int valor;
    pair<string, unsigned char> auxiliar;
    
    while(!is.eof()){
        is >> primero;
        is >> valor;

        auxiliar.first=primero;
        auxiliar.second=valor;

        entrada.insertar(auxiliar);
    }

    return is;
}

std::ostream & operator <<(std::ostream &os, const acciones & salida){
    acciones::const_iterator output=salida.begin();

    for(; output != salida.end() ; ++output){
        cout << (*output).first << " " << (int)(*output).second << endl;
    }

    return os;
}