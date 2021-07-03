/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int nargs, char * args[]) {
    int i;
    double d;
    string s;
    ifstream paco;      //input file stream
    ofstream paca;      //output file stream
    
    if(nargs == 3){
       
    
    paco.open(args[1]);
    if(paco){
    paco >> i;
    paco >> d;
    paco >> s;
    if (paco)
    cout << "Datos leídos\n" <<i<<endl<<d<<endl<<s<<endl;
    
    else
        cerr << "ERROR" << endl;
    
    paco.close();       //la clase fstream dispone de un destructor pero es aconsejable cerrar manualmente los ficheros
    }
    
    
    else
        cerr << "ERROR" << endl;
    
    paca.open(args[2]);
    if (paca){
        paca << i+100 << endl;
        paca << d+100 << endl;
        paca << s +"Pepa"<< endl;
        
        if(paca)
            paca.close();
        
        else
            cerr << "Error en la escritura de datos" << endl;
    }
    
    else    
        cerr << "Error en la apertura del fichero" << endl;
    }
    else
        cerr << "Llamada incorrecta\n <ficheroentrada> <ficherosalida>" << endl;
    
    return 0;

            
}



