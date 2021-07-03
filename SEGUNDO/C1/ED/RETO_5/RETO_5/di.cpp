#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
int recursivo(int iteracion, int a, int b, int primo);
bool esprimo(int primo){
    bool es_primo=true;
    for(int i=2; i < primo && es_primo; i++){
        if(primo % i == 0)
            es_primo=false;
    }

    return es_primo;
}

vector<pair<int,int>> validos(int primo){
    bool es_valido=true;
    int resultados[primo];
    vector<pair<int,int>> retorno;
    pair<int,int> insertar;

    for(int a=0; a < primo; a++){
        for(int b=0; b < primo; b++){
            if(a==0 && b==0){
                continue;
            }

            es_valido=true;

            for(int i=0; i < primo; i++){
                resultados[i]=recursivo(i,a,b,primo);
            }

            for(int i=0; i < primo && es_valido; i++){
                es_valido=false;
                for(int j=0; j < primo && !es_valido; j++){
                    if(i==resultados[j]){
                        es_valido=true;
                    }
                }
            }          

            if(es_valido){
                insertar.first=a;
                insertar.second=b;
                retorno.push_back(insertar);
            }

            else{
                insertar.first=0;
                insertar.second=0;
                retorno.push_back(insertar);
            }
        }
    }

    return retorno;

}


int recursivo(int iteracion, int a, int b, int primo){
    int resultado;

    if(iteracion==0){
        resultado=0;
    }

    else{
        resultado=((a*recursivo(iteracion-1,a,b,primo)+b)%primo);
    }

    return resultado;
}

int main(int argc, char* argv[]){
    int primo;
    bool es_primo;
    vector<pair<int,int>> valido;

    cout << "introduzca un numero primo "<< endl;
    cin >> primo;

    if(primo < 0 || primo == 0){
        cerr << "El valor introducido no es primo" << endl;
        exit(EXIT_FAILURE);
    }

    if(! esprimo(primo)){
        cerr << "El valor introducido no es primo" << endl;
        exit(EXIT_FAILURE);
    }

    valido=validos(primo);

    cout << "Los valores de a y c validos son: " << endl;
    for(int i=0; i < valido.size(); i++){
        if(valido[i].first!=0 || valido[i].second !=0)
        cout << "a=" << valido[i].first << " b=" << valido[i].second << endl;
    }
    return 0;
}
