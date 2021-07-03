#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <time.h>

using namespace std;

string recortar(string cadena);
double distancia(pair<double,double> origen, pair<double,double> destino);
vector<int> busqueda_milindrona(vector<pair<double,double>> datos);
double distancia_milindrona(double** matrix,vector<int> ciudades);
vector<int> insercion_milindrona(double ** matrix, vector<int> ciudades, int tamanio);
bool next_milindrona(vector<int> ciudades, int ciudad);


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

    ciudades=busqueda_milindrona(datos);

    clock_t tantes= clock();
    ciudades=insercion_milindrona(matriz,ciudades,datos.size());
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

    cout << "Distancia final -> " << final <<endl;
	
    

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

vector<int> busqueda_milindrona(vector<pair<double,double>> datos){
    vector<int> ciudades;
    int min_x=0;
    int max_x=0;
    int max_y=0;
    
    for(int i=0; i<datos.size();i++){
    	if(datos[min_x].first>datos[i].first)
    		min_x=i;
	}
	
	for(int i=0; i<datos.size();i++){
    	if(datos[max_x].first<datos[i].first)
    		max_x=i;
	}
	
	ciudades.push_back(min_x+1);
    ciudades.push_back(max_x+1);
   
   	for(int i=0; i<datos.size();i++){
    	if(datos[max_y].second<datos[i].second)
    		max_y=i;
	}
	
	ciudades.push_back(max_y+1);
   
   /* double minimo=matriz[0][1];
    int auxiliar=0;
    
    
	
	ciudades.push_back(ciudad+1);
	
	
    for(int i=1; i<tamanio; i++){
        for(int j=0; j<tamanio; j++){
            if(matriz[ciudad][j]!=0){
                if(minimo>=matriz[ciudad][j]){
                    minimo=matriz[ciudad][j];
                    auxiliar=j;
                }
            }
        }
        for(int k=0; k<tamanio; k++){
            matriz[k][ciudad]=0;
        }
        ciudad=auxiliar;
        ciudades.push_back(auxiliar+1);
        int z=0;
        minimo=0;
        while(z<tamanio&&minimo==0){
            minimo=matriz[ciudad][z];
            z++;
        }
        
    }*/
    return ciudades;
}
double distancia_milindrona(double** matrix,vector<int> ciudades){
	double distancia=0;

	for(int i=0;i<ciudades.size()-1;i++){
		distancia+=matrix[ciudades[i]-1][ciudades[i+1]-1];
    }

	return distancia;
}

vector<int> insercion_milindrona(double ** matrix, vector<int> ciudades, int tamanio){
	double distancia=0;
	double min=0;
	int ciudad=0;
    vector<int>::iterator pos_min=ciudades.begin();
    vector<int>::iterator pos=ciudades.begin();
    vector<int>::iterator it=ciudades.begin();

	
	for(int milindri=0; milindri<tamanio-3;milindri++){
		distancia=distancia_milindrona(matrix,ciudades)*2;
		pos_min=ciudades.begin();

		for(int i=0; i<tamanio; i++){
            int longitud=ciudades.size();
            it=ciudades.begin();

			if(!next_milindrona(ciudades,i+1)){
				for(int j=0; j< longitud;j++){
                    it=ciudades.insert(it,i+1);
					if(j==0){
						min=distancia_milindrona(matrix,ciudades);
						pos=it;
					}

					else{
						if(min>distancia_milindrona(matrix,ciudades)){
							pos=it;
							min=distancia_milindrona(matrix,ciudades);
						}	
					}
                    it=ciudades.erase(it);
                    it++;
				}

				if(distancia>min){
					distancia=min;
					ciudad=i+1;
					pos_min=pos;
				}
			}
		}

		ciudades.insert(pos_min,ciudad);
	}

	return ciudades;
}

bool next_milindrona(vector<int> ciudades,int ciudad){
	bool salida=false;
	for(int i=0; i<ciudades.size()&&!salida;i++){
		if(ciudad==ciudades[i])
			salida=true;
	}
	return salida;
}
