/***  fichero repeticion.cpp ***/

#include <iostream>
#include <string>

using namespace std;

int main(){
    char cadena[40];
    
    cin.getline(cadena,30);
    
    for (int i=0;i<5;i++)
        cout << cadena << endl;
}
