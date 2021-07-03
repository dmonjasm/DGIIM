#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void milindri_marchatras(pair<int,bool> ** matriz, int tamanio, vector<pair<int,int>> & resultado, pair<int,int> pos_actual, pair<int,int> posicion_anterior);

int main(int argc, char * argv[]){
    if(argc < 2){
        cerr << "Modo de ejecución: <programa> <archivo>" << endl;
        exit(-1);
    }

    ifstream f(argv[1]);
    int dimension;
    bool archivo=false;
    pair<int,bool> ** matriz = NULL;
    vector<pair<int,int>> resultado;

    if(f){
        archivo = true;
        string aux;

        f >> dimension;
        matriz = new pair<int,bool>*[dimension];

        for(int i=0; i< dimension; i++){
            matriz[i]=new pair<int,bool>[dimension];
        }

        for(int i =0; i < dimension; i++){
            for(int j=0; j < dimension; j++){
                f >> matriz[i][j].first;
                if(matriz[i][j].first == 0)
                    matriz[i][j].second = false;

                else
                    matriz[i][j].second = true;
                

            }
        }
    }

    pair<int,int> aux(0,0);
    resultado.push_back(aux);
    aux.first = -1;
    aux.second = -1;
    milindri_marchatras(matriz,dimension,resultado,resultado[0],aux);




    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
            cout << matriz[i][j].first << " ";
        }

        cout << endl;
    }

    if(resultado.size() > 0){
        for(int i=0; i < resultado.size(); i++){
            cout << "(" << resultado[i].first << "," << resultado[i].second << ")" << endl;
        }   
    }

    else{
        cout << "No hay camino posible" << endl;
    }

    f.close();
    
    for(int i=0; i< dimension; i++){
        delete [] matriz[i];
    }

    delete [] matriz;
    
}

 void milindri_marchatras(pair<int,bool> ** matriz, int tamanio, vector<pair<int,int>> & resultado, pair<int,int> pos_actual, pair<int,int> posicion_anterior){
    bool camino=true;
    pair<int,int> pos_siguiente;
    int contador_caminos=0;

    if(resultado.size() > 0){
        if(pos_actual.first != tamanio - 1 || pos_actual.second != tamanio - 1){
            if(matriz[pos_actual.first][pos_actual.second].second){
                resultado.pop_back();
                if(resultado.size() - 2 >= 0)
                    milindri_marchatras(matriz, tamanio, resultado,resultado[resultado.size()-1],resultado[resultado.size()-2]);

                else{
                    pair<int,int> aux(0,0);
                    milindri_marchatras(matriz, tamanio, resultado,resultado[resultado.size()-1],aux);
                    }
            }
        

            else{
                if(pos_actual.first + 1 < tamanio && posicion_anterior.first != pos_actual.first + 1){
                    if(matriz[pos_actual.first+1][pos_actual.second].first == 0 && matriz[pos_actual.first+1][pos_actual.second].second == false){
                        contador_caminos++;
                        
                        if(camino){
                            pos_siguiente.first = pos_actual.first+1;
                            pos_siguiente.second = pos_actual.second;
                            resultado.push_back(pos_siguiente);
                            camino = false;
                        }
                    }
                }

                if(pos_actual.first-1 >= 0 && posicion_anterior.first != pos_actual.first - 1){
                    if(matriz[pos_actual.first-1][pos_actual.second].first == 0 && matriz[pos_actual.first-1][pos_actual.second].second == false){
                        contador_caminos++;

                        if(camino){
                            pos_siguiente.first = pos_actual.first-1;
                            pos_siguiente.second = pos_actual.second;
                            resultado.push_back(pos_siguiente);
                            camino = false;
                        }
                    }
                }

                if(pos_actual.second + 1 < tamanio && posicion_anterior.second != pos_actual.second + 1){
                    if(matriz[pos_actual.first][pos_actual.second+1].first == 0 && matriz[pos_actual.first][pos_actual.second+1].second == false){
                        contador_caminos++;

                        if(camino){
                            pos_siguiente.first = pos_actual.first;
                            pos_siguiente.second = pos_actual.second +1;
                            resultado.push_back(pos_siguiente);
                            camino = false;
                        }
                    }
                }

                if(pos_actual.second - 1 >= 0 && posicion_anterior.second != pos_actual.second - 1){
                    if(matriz[pos_actual.first][pos_actual.second-1].first == 0 && !matriz[pos_actual.first][pos_actual.second-1].second){
                        contador_caminos++;

                        if(camino){
                            pos_siguiente.first = pos_actual.first;
                            pos_siguiente.second = pos_actual.second-1;
                            resultado.push_back(pos_siguiente);
                            camino = false;
                        }
                    }
                }

                if(contador_caminos > 1){
                    matriz[pos_actual.first][pos_actual.second].second = false;
                }

                if(contador_caminos <= 1){
                    matriz[pos_actual.first][pos_actual.second].second = true;
                }

                
                if(camino){
                    milindri_marchatras(matriz, tamanio, resultado,pos_actual, posicion_anterior);
                }
                
                else{
                    if(resultado.size() > 0)
                        milindri_marchatras(matriz, tamanio, resultado, pos_siguiente, pos_actual);
                }  
            }
        }
    }
}