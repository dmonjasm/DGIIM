#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <time.h>

using namespace std;

string recortar(string cadena);
double distancia(pair<double,double> origen, pair<double,double> destino);
vector<int> milindron_predictor(double** matriz, int tamanio);

int main(int argc, char * argv[]){
    ifstream f(argv[1]);
    string name="", comment="", type="", dimension="", edge_weight_type="", display_data_type="", eof="";
    pair<double,double> auxiliar;
    vector<pair<double,double>> datos;
    

    if(argc < 2){
        cerr << "Modo ejecución: <programa> <nombre_archivo>" << endl;
        exit(EXIT_FAILURE);
    }

    if(f){
        string aux;
        int posicion=0;

        getline(f,aux);

        while(aux != "NODE_COORD_SECTION"){
            posicion=aux.find(":");
            
            if(aux.substr(0,posicion) == "NAME" || aux.substr(0,posicion) == "NAME "){
                name = recortar(aux);
            }

            if(aux.substr(0,posicion) == "COMMENT" || aux.substr(0,posicion) == "COMMENT "){
                comment = recortar(aux);
            }

            if(aux.substr(0,posicion) == "TYPE" || aux.substr(0,posicion) == "TYPE "){
                type = recortar(aux);
            }

            if(aux.substr(0,posicion) == "DIMENSION" || aux.substr(0,posicion) == "DIMENSION "){
                dimension = recortar(aux);
            }

            if(aux.substr(0,posicion) == "EDGE_WEIGHT_TYPE" || aux.substr(0,posicion) == "EDGE_WEIGHT_TYPE "){
                edge_weight_type = recortar(aux);
            }

            if(aux.substr(0,posicion) == "DISPLAY_DATA_TYPE" || aux.substr(0,posicion) == "DISPLAY_DATA_TYPE "){
                display_data_type = recortar(aux);
            }

            getline(f,aux);
               
        }

        f >> eof;

        while(eof != "EOF"){
            f >> auxiliar.first;
            f >> auxiliar.second;

            datos.push_back(auxiliar);

            f >> eof;
        }
    }
    else{
        cerr << "No existe el archivo" << endl;
        exit(EXIT_FAILURE);
    }
    
    double** matriz;
    matriz = new double*[datos.size()];
    for(int i=0; i<datos.size(); i++){
        matriz[i]= new double[datos.size()];
    }


    for(int i=0; i<datos.size(); i++){
        for(int j=i; j<datos.size(); j++){
            matriz[i][j] = distancia(datos[i],datos[j]);
            matriz[j][i] = matriz[i][j];
        }
    }


    vector<int> ciudades;
    int redondeo;

    clock_t tantes= clock();

    ciudades=milindron_predictor(matriz, datos.size());

    clock_t tdespues = clock();

    cout << "Tiempo: " << (double)(tdespues - tantes)/CLOCKS_PER_SEC << endl;
    double final=0;

    for(int i=0; i<datos.size(); i++){
        for(int j=i; j<datos.size(); j++){
            matriz[i][j] = distancia(datos[i],datos[j]);
            matriz[j][i] = matriz[i][j];
        }
    }

    for(int i=0; i < ciudades.size()-1;i++)
        final += matriz[ciudades[i]-1][ciudades[i+1]-1];

    redondeo=final;

    if((final - redondeo) >= 0.5)
        redondeo++;

    cout << "Distancia final -> " << redondeo <<endl;
    

    int posi=name.find(".");
    name = name.substr(1,posi);
    name = name+"reord.tsp";
    ofstream os(name);
    
    if(name!="")
        os << "NAME :" << name << "\n";
    if(type!="")
        os << "TYPE :" << type << "\n";
    if(comment!="")
        os << "COMMENT :" << comment << "\n";
    if(dimension!="")
        os << "DIMENSION :" << dimension << "\n";
    if(edge_weight_type!="")
        os << "EDGE_WEIGHT_TYPE :" << edge_weight_type << "\n";
    if(display_data_type!="")
        os << "DISPLAY_DATA_TYPE :" << display_data_type << "\n";

    os << "TOUR_SECTION\n";
    for(int i=0; i<ciudades.size();i++){
        os << ciudades[i] << " " << datos[ciudades[i]-1].first << " " << datos[ciudades[i]-1].second << "\n"; 
    }
    os << -1;



    for(int i=0; i<datos.size(); i++){
        delete [] matriz[i];
    }
    delete [] matriz;
    return 0;    
}


string recortar(string cadena){
    string auxiliar;
    int posicion=0;

    posicion = cadena.find(":");

    auxiliar = cadena.substr(posicion+1,auxiliar.size()-(posicion+1));

    return auxiliar;
}

double distancia(pair<double,double> origen, pair<double,double> destino){
    double distancia=0;

    distancia = sqrt(pow(destino.first - origen.first,2)+pow(destino.second - origen.second,2));

    return distancia;
}

vector<int> milindron_predictor(double** matriz, int tamanio){
    vector<int> ciudades;
    vector<pair<int,int>> prediccion;
    vector<double> distancias;
    double distancia;
    pair<double,int> minimo;
    int ciudad=0;
    pair<int,int> auxiliar;

    ciudades.push_back(ciudad+1);

    for(int i=1; i < tamanio; i++){
        
        for(int j=0; j < tamanio; j++){
            if(j != ciudad && matriz[ciudad][j] != 0){
                auxiliar.first = j;

                for(int k=0; k < tamanio; k++){
                    if(k != ciudad && k != auxiliar.first && matriz[j][k] != 0 && matriz[ciudad][k] != 0)
                        auxiliar.second = k;
                }

                prediccion.push_back(auxiliar);
            }
        }

        for(int j=0; j < prediccion.size(); j++){
            distancia = matriz[ciudad][prediccion[j].first] + matriz[prediccion[j].first][prediccion[j].second];

            if(j==0){
                minimo.first=distancia;
                minimo.second=j;
            }

            if(minimo.first >= distancia){
                minimo.first = distancia;
                minimo.second = j;
            }
        }

        ciudades.push_back(prediccion[minimo.second].first + 1);

        for(int j=0; j < tamanio; j++){
            matriz[j][ciudad] = 0;
        }

        ciudad=prediccion[minimo.second].first;

        prediccion.clear();
    }

    ciudades.push_back(1);
    
    return ciudades;
}

