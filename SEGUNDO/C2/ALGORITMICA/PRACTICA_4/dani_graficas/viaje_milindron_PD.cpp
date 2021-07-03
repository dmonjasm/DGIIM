#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <time.h>

using namespace std;

string recortar(string cadena);
double distancia(pair<double,double> origen, pair<double,double> destino);
pair<vector<int>,double> milindri_dynamic(int indice, vector<int> descartados, double ** matriz, int tamanio);

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
    vector<int> nodos;
    pair<vector<int>,double> distancia;
    int redondeo;

    for(int i=1; i < datos.size();i++){
            nodos.push_back(i);
    }

    clock_t tantes = clock();
    distancia = milindri_dynamic(0,nodos,matriz,datos.size());
    clock_t tdespues = clock();
	
    redondeo = distancia.second;
   
    if((distancia.second - redondeo) > 0.5){
	redondeo++;
    }

    cout << "Tiempo:  " << (double)(tdespues-tantes)/CLOCKS_PER_SEC << endl;

    cout << "Distancia: " << redondeo << " Tamaño: " << distancia.first.size() << endl;
    ciudades = distancia.first;
    
    

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
        cout << ciudades[i] << "\n";
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

pair<vector<int>,double> milindri_dynamic(int indice, vector<int> ciudades, double ** matriz, int tamanio){
    pair<vector<int>,double> minimo;
    pair<vector<int>,double> distancia;
    vector<int> auxiliar = ciudades;
    vector<int>::iterator it;
    it = auxiliar.begin();

    if(ciudades.size()==0){
	minimo.first.push_back(1);
        minimo.first.push_back(indice+1);
        minimo.second = matriz[indice][0];
    }

        for(int i=0; i < ciudades.size(); i++){
            if(i==0){
                auxiliar.erase(it);
                minimo = milindri_dynamic(ciudades[i],auxiliar,matriz,tamanio);
                minimo.second += matriz[indice][ciudades[i]];
                minimo.first.push_back(indice + 1);
                it++;
            }

            else{
                auxiliar=ciudades;
                it=auxiliar.begin();

                for(int j=0; j < i; j++)
                    it++;
                
                auxiliar.erase(it);
                distancia = milindri_dynamic(ciudades[i],auxiliar, matriz,tamanio);
                distancia.second += matriz[indice][ciudades[i]];
                distancia.first.push_back(indice + 1);
                
                if(distancia.second < minimo.second)
                    minimo=distancia;
            }
        }

        return minimo;
}







