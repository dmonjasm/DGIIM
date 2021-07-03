#include <iostream>

using namespace std; 

int main () {
    
    int valor;
    double media=0;
    int contador=0;
    
    media += valor;
    contador ++;
    cin >> valor;
    
    while (valor!=-1){
        if (valor != -1){
        		cin >> valor;
            media += valor;
            contador ++;
        }
    }
    
    media = media / contador;
    cout << "\nLa media es; "  << media << "\n";
}
