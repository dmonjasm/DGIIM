/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newmain.cpp
 * Author: daniel
 *
 * Created on 18 de mayo de 2019, 13:53
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

/*
 * 
 */
int main() {

        int indice=96;
        int _K=3;
        int posiciones[_K];
        string cadena="___";
        string _VALIDOS="_actg";
        int divisor=0;
        
        for(int i=0; i<_K-1;i++)
            posiciones[i]=0;
        
        posiciones[_K-1]=indice;
        
        for(int i=(_K-1); i>0;i--){
            divisor=pow(_VALIDOS.size(),i);
            posiciones[i-1]=(posiciones[i]%divisor);
            posiciones[i]=(posiciones[i]/pow(_VALIDOS.size(),i));
        }
        
        for(int i=0;i < _K;i++)
            cadena[i]=_VALIDOS[posiciones[_K-1-i]];
        
        for (int i=0;i <_K;i++){
            cout << posiciones[i] << endl;
            cout << cadena[i] << endl;
        }
        

    return 0;
}