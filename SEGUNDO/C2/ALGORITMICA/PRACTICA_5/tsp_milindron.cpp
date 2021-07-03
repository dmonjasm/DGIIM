#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<math.h>
#include<map>
#include<time.h>


using namespace std;

struct nodo{
    nodo *padre=NULL;
    nodo **hijos=NULL;
    int cota_inferior=0;
    int cota_superior=0;
    int ciudad;
    bool podado=false;
    int num_hijos=0;
    vector<int> ciudades_restantes;
};

vector<int> insercion_milindrona(double ** matrix, vector<int> ciudades, int tamanio);
double distancia_milindrona(double** matrix,vector<int> ciudades);
bool next_milindrona(vector<int> ciudades,int ciudad);
vector<int> busqueda_milindrona(vector<pair<double,double>> datos);
double distancia(pair<double,double> origen, pair<double,double> destino);
string recortar(string cadena);
void crear_hijos(nodo * raiz,vector <int> ciudades_restantes);
nodo* ascender_arbol(nodo * hijo);
void esparcir_cota(nodo * ayuda);
void poda(double cota, nodo * hijo);
double distancia_rama(nodo * actual,double ** matriz);
double minima_distancia(int ciudad_actual, vector<int>ciudades_restantes, double ** matriz);
void branch_and_bound_milindron(nodo * raiz, multimap<double, nodo *> ramificacion,double ** matriz,nodo * ayuda,int & contador_podas,int &tamano_rami, int& nodos_exp);
void emancipacion(nodo * raiz);

int main(int argc, char*argv[]){   
    ifstream f(argv[1]);
    string name="", comment="", type="", dimension="", edge_weight_type="", display_data_type="", eof="";
    pair<double,double> auxiliar;
    vector<pair<double,double>> datos;
    struct timespec cgt1,cgt2;
    double ncgt;
    

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

    clock_gettime(CLOCK_REALTIME,&cgt1);
    ciudades= busqueda_milindrona(datos);
    ciudades=insercion_milindrona(matriz,ciudades,datos.size());

    double final=0;

    for(int i=0; i < ciudades.size()-1;i++)
        final += matriz[ciudades[i]-1][ciudades[i+1]-1];

    nodo * raiz = new nodo;
    multimap<double,nodo *> ramificacion;
    vector<int> ciudades_restantes;
    pair<double,nodo*> insertar;
    int contador_podas=0;
    int tamano_rami=0;
    int nodos_exp=0;
    
    for(int i=1; i < datos.size(); i++){
        ciudades_restantes.push_back(i+1);
    }

    raiz->ciudades_restantes=ciudades_restantes;
    raiz->ciudad = 1;
    raiz->cota_superior = final;
    insertar.first = minima_distancia(raiz->ciudad,raiz->ciudades_restantes,matriz);
    insertar.second = raiz;
    ramificacion.insert(insertar);

    nodo * salida = new nodo;
    salida->cota_inferior=final;
    salida->cota_superior=final;
    salida->ciudad = 0;


    branch_and_bound_milindron(raiz,ramificacion,matriz,salida,contador_podas,tamano_rami,nodos_exp);
    clock_gettime(CLOCK_REALTIME,&cgt2);

    ncgt=(double)(cgt2.tv_sec-cgt1.tv_sec) + (double)((cgt2.tv_nsec - cgt1.tv_nsec)/(1.e+9));

    int distancia=0;
    distancia = salida->cota_inferior;

    if(salida->cota_inferior-distancia > 0.5)
        distancia++;
        
    cout << "Distancia total: " << distancia << endl;
    cout << "Nº de podas: " << contador_podas << endl;
    cout << "Tamaño máximo cola con prioridad: " << tamano_rami << endl;
    cout << "Nº de nodos expandidos: " << nodos_exp << endl;
    cout << "Tiempo: " << ncgt << endl;

    ciudades.clear();

    while(salida->padre != NULL){
        cout << salida->ciudad << endl;
        ciudades.push_back(salida->ciudad);
        salida = salida->padre;

        if(salida->padre == NULL){
            ciudades.push_back(salida->ciudad);
            cout << salida->ciudad << endl;
        }
    }

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

    emancipacion(raiz);



    for(int i=0; i < ciudades.size()-1;i++)
        final += matriz[ciudades[i]-1][ciudades[i+1]-1];

        for(int i=0; i<datos.size(); i++){
        delete [] matriz[i];
    }
    delete [] matriz;
    return 0;
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

    ciudades.push_back(ciudades[0]);

	return ciudades;
}

double distancia_milindrona(double** matrix,vector<int> ciudades){
	double distancia=0;

	for(int i=0;i<ciudades.size()-1;i++){
		distancia+=matrix[ciudades[i]-1][ciudades[i+1]-1];
    }

	return distancia;
}

bool next_milindrona(vector<int> ciudades,int ciudad){
	bool salida=false;
	for(int i=0; i<ciudades.size()&&!salida;i++){
		if(ciudad==ciudades[i])
			salida=true;
	}
	return salida;
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

    return ciudades;
}

double distancia(pair<double,double> origen, pair<double,double> destino){
    double distancia=0;

    distancia = sqrt(pow(destino.first - origen.first,2)+pow(destino.second - origen.second,2));

    return distancia;
}

string recortar(string cadena){
    string auxiliar;
    int posicion=0;

    posicion = cadena.find(":");

    auxiliar = cadena.substr(posicion+1,auxiliar.size()-(posicion+1));

    return auxiliar;
}

void crear_hijos(nodo * raiz,vector <int> ciudades_restantes){
    raiz->hijos = new nodo* [ciudades_restantes.size()];
    raiz->num_hijos=ciudades_restantes.size();

    for(int i=0; i < ciudades_restantes.size(); i++){
        raiz->hijos[i] = new struct nodo;
        raiz->hijos[i]->ciudad = ciudades_restantes[i];
        raiz->hijos[i]->padre = raiz;
        raiz->hijos[i]->podado = false;
    }
}

nodo* ascender_arbol(nodo * hijo){
    nodo * raiz;
    raiz = hijo;

    while(raiz->padre != NULL){
        raiz = raiz->padre;
    }

    return raiz;
}

void esparcir_cota(nodo * ayuda){
    if(ayuda -> num_hijos > 0){
        for(int i = 0; i < ayuda->num_hijos; i++){
            ayuda->hijos[i]->cota_superior=ayuda->cota_superior;
            esparcir_cota(ayuda->hijos[i]);
        }
    }
}

void poda(double cota, nodo * hijo){
    nodo * ayuda = ascender_arbol(hijo);

    if(hijo->cota_inferior < cota){
        hijo->podado = true;
        //cout << "Se ha podado un hijo " << endl;
    }
}

double distancia_rama(nodo * actual,double ** matriz){
    nodo * raiz;
    raiz = actual;
    double acumulador = 0;

    while(raiz->padre != NULL){
        acumulador += matriz[raiz->ciudad -1][raiz->padre->ciudad -1];
        raiz = raiz->padre;

    }

    return acumulador; 

}

double minima_distancia(int ciudad_actual, vector<int>ciudades_restantes, double ** matriz){
    double minimo; 
    double auxiliar;
    int ciudad_min = ciudades_restantes[0];

    minimo = matriz[ciudad_actual-1][ciudad_min-1];

    for(int i=1; i < ciudades_restantes.size(); i++){
        auxiliar = matriz[ciudad_actual-1][ciudades_restantes[i]-1];
        if(minimo > auxiliar && ciudad_actual != ciudades_restantes[i]){
            minimo = auxiliar;
        }
    }

    return minimo;
}

void emancipacion(nodo * raiz){
    if(raiz->num_hijos > 0){
        for(int i = 0; i < raiz->num_hijos; i++){
            emancipacion(raiz->hijos[i]);
        }
        delete  [] raiz->hijos;
        delete raiz;
    }
    else{
        delete raiz;
    }
}

void branch_and_bound_milindron(nodo * raiz, multimap<double, nodo*> ramificacion,double ** matriz,nodo * salida,int& contador_podas,int &tamano_rami, int &nodos_exp){
    if(raiz->ciudades_restantes.size() > 0){
        crear_hijos(raiz,raiz->ciudades_restantes);
        nodos_exp+=raiz->ciudades_restantes.size();
        esparcir_cota(raiz);
        multimap<double,nodo *>::iterator elim=ramificacion.begin();
        ramificacion.erase(elim);

        for(int i = 0; i < raiz->num_hijos; i++){
            vector<int> auxiliar = raiz->ciudades_restantes;
            bool encontrado = false;

            for(vector<int>::iterator it=auxiliar.begin(); it != auxiliar.end() && !encontrado; ++it){
                if(*it == raiz->hijos[i]->ciudad){
                    auxiliar.erase(it);
                    encontrado=true;
                }
            }

            raiz->hijos[i]->ciudades_restantes = auxiliar;

            int distancia = 0;
            if(raiz->hijos[i]->ciudades_restantes.size() > 0){
                distancia = minima_distancia(raiz->hijos[i]->ciudad,raiz->hijos[i]->ciudades_restantes,matriz);
                pair<double,nodo *> insertar(distancia,raiz->hijos[i]);
                ramificacion.insert(insertar);
            }

            raiz->hijos[i]->cota_inferior = distancia + distancia_rama(raiz->hijos[i],matriz);

            if(raiz->hijos[i]->ciudades_restantes.size() == 0){
                raiz->hijos[i]->ciudades_restantes.push_back(1);
                crear_hijos(raiz->hijos[i],raiz->hijos[i]->ciudades_restantes);
                raiz->hijos[i]->ciudades_restantes.pop_back();
                raiz->hijos[i]->hijos[0]->ciudades_restantes=raiz->hijos[i]->ciudades_restantes;
                esparcir_cota(raiz->hijos[i]);
                raiz->hijos[i]->hijos[0]->cota_inferior=distancia_rama(raiz->hijos[i]->hijos[0],matriz);

                if(salida->cota_inferior > raiz->hijos[i]->hijos[0]->cota_inferior)
                    *salida= *raiz->hijos[i]->hijos[0];
            }

            if(raiz->hijos[i]->cota_inferior > raiz->hijos[i]->cota_superior){
                raiz->hijos[i]->podado=true;
                contador_podas++;
            }
        }

        if(ramificacion.size()>tamano_rami)
            tamano_rami = ramificacion.size();
        

        if(ramificacion.size() > 0){
            while((*ramificacion.begin()).second->podado == true && ramificacion.size() > 0){
                ramificacion.erase(ramificacion.begin());
            }
        }

        if(ramificacion.size() > 0)
            branch_and_bound_milindron((*ramificacion.begin()).second,ramificacion,matriz,salida,contador_podas,tamano_rami,nodos_exp);

    }
}   
