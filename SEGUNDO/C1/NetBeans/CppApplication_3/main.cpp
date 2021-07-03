/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: daniel
 *
 * Created on 20 de mayo de 2019, 20:10
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

/*
 * 
 */
int main(int narg, char *args[]) {
    char operativa;
    bool activa=false;
    ifstream entrada;
    
    entrada.open(args[1]);
    
    entrada >> operativa;
    
    
    if(operativa=='C'){
        activa=true;
        cout << "True" << endl;
    }
    
    else{
        activa=false;
        cout << "False" << endl;
    }
    
    return 0;
}       
