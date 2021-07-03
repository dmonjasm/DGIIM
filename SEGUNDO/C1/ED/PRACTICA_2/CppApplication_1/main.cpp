/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: daniel
 *
 * Created on 15 October 2019, 16:52
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    string cadena="Ketchup;98;24;2;0;0;Procesado";
    string delim=";";
    double cal, hcar, prot, grasas, fibra;
    string tipo;
    int delims[6];
    string delimsa="456";
    int pos_ini=0;
    int tamano=cadena.size();
    int i=0;
    
    while(cadena.find(delim,pos_ini)!=std::string::npos){
        pos_ini=cadena.find(delim,pos_ini);
        delims[i]=pos_ini;
        cout << pos_ini;
        i++;
        pos_ini++;
    }
    
    for(int i=0; i <= 6; i++){
        if(i==0)
            cout << "\n" << cadena.substr(0,delims[i]) << endl;
        if(i==1){
            pos_ini=atof(cadena.substr(delims[i-1]+1,delims[i]).c_str());
            cout << pos_ini << endl;
        }
        if(i==2){
            pos_ini=atof(cadena.substr(delims[i-1]+1,delims[i]).c_str());
            cout << pos_ini<< endl;
        }
        if(i==3){
            pos_ini=atof(cadena.substr(delims[i-1]+1,delims[i]).c_str());
            cout << pos_ini<< endl;
        }
        if(i==4){
            pos_ini=atof(cadena.substr(delims[i-1]+1,delims[i]).c_str());
            cout << pos_ini<< endl;
        }
        if(i==5){
            pos_ini=atof(cadena.substr(delims[i-1]+1,delims[i]).c_str());
            cout << pos_ini<< endl;
        }
        if(i==6)
            cout << cadena.substr(delims[i-1]+1,cadena.size()) << endl;
    }
    
    

    return 0;
}

