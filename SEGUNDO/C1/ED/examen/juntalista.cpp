#include <list>
#include <iostream>

using namespace std;

void juntalista(list<int> & l, int n){
    list<int>::iterator inicio=l.begin();
    list<int>::iterator avanzado=l.begin();
    int acumulador=0;
    int grupos=l.size()/n;

    if(l.size()%n!=0){
        grupos++;
    }

    int tamano=l.size()-grupos;


    for(int i=0; i < grupos; i++, ++inicio){
        for(int j=0; j < n && avanzado != l.end(); j++, ++avanzado){
            acumulador+=*avanzado;
        }

        *inicio=acumulador;
        acumulador=0;
    }

    for(int i=0; i < tamano; i++){
        l.pop_back();
    }
}

int main(int argc, char * argv[]){
    list<int> lista={1,3,2,4,5,2,2,3,5,7,4,3,2,2};
    int n=3;

    juntalista(lista,n);
    list<int>::iterator it=lista.begin();

    for( ;it != lista.end(); ++it){
        cout << *it << endl;
    }

    return 0;
}