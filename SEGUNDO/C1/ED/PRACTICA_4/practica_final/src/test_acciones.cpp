#include "acciones.h"
#include <map>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char * argv[]){

    if(argc < 2){
        cout << "MODO EMPLEO: PROGRAMA DATOS" << endl;
        exit(EXIT_FAILURE);
    }

    acciones prueba;
    string nf=argv[1];
    ifstream f(nf);

    if(!f){
        cerr << "error al abrir el archivo de datos" << endl;
    }

    f >> prueba;

    cout << prueba;

    if(prueba.empty()){
        cout << "el archivo esta vacio" << endl;
    }

    else{
        cout << "el archivo tiene elementos" << endl;
    }

    cout << "El numero de elementos del archivo es: " << prueba.size() << endl;

    prueba.borrar("Cocer");
    prueba.borrar("Freir");
    prueba.borrar("Add");

    cout << "Los elementos tras el borrado son: " << endl;
    cout << prueba;
    cout << "El numero de elementos tras el borrados es: " << prueba.size() << endl;

    pair<string, unsigned char> insertar("Add", 2);

    prueba.insertar(insertar);

    cout << "Los elementod tras la insercion son: " << endl;
    cout << prueba << endl;
    cout << "El numero de elementos tras la inserciones es: " << prueba.size() << endl;

    acciones copia(prueba);

    cout << "Mostrando copia " << endl;
    cout << copia << endl;

    return 0;
}