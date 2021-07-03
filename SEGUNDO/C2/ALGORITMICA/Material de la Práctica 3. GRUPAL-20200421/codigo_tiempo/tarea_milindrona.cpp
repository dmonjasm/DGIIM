#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <cmath>
#include <vector>
#include <time.h>

using namespace std;

vector<pair<int,double>> tarea_milindrona(vector<pair<int,double>> tareas);

int main(int argc, char** argv){

    vector<pair<int,double>> tareas;

    if(argc!=2){
        cerr << "Error en el parametro n";
        exit(1);
    }

    int n=atoi(argv[1]);

    pair<int,double> aux;
    srand((unsigned int) getpid());
    
    for(int i=0; i<n; i++){
        aux.first=rand()%n + 1;
        aux.second= (double) (rand()%n+1) * M_PI;     
        tareas.push_back(aux);
    }
    
    cout << "El vector de tareas es:\n";
	    for(int j=0; j<tareas.size();j++){
		cout << tareas[j].first << "\t" << tareas[j].second << endl;
	}

    vector<pair<int,double>> resultado;

    clock_t tantes = clock();
    resultado=tarea_milindrona(tareas);
    clock_t tdespues = clock();

    cout << "\n\nEl vector resultado:\n";
    for(int i=0; i<resultado.size();i++){
        cout << resultado[i].first << "\t" << resultado[i].second << endl;
    }

    cout << "Tiempo: " << (double)(tdespues - tantes)/CLOCKS_PER_SEC << endl;

    return 0;
}

vector<pair<int,double>> tarea_milindrona(vector<pair<int,double>> tareas){
    
    double max_ganancia;
    int instante=1;
    int resta=0;
    int pos=0;
    vector<pair<int,double>> resultado;
    bool salir=false;
    bool encontrado=false;
    

    for(int i=0; i<tareas.size(); i++){
        
        for(int j=0; j<tareas.size();j++){
            if(j==0){
                for(int k=0; k<tareas.size()&&!encontrado; k++){
                    if(tareas[k].second!=0&&(tareas[k].first-instante)>=0){
                        resta=tareas[k].first-instante;
                        encontrado=true;
                    }
                }
            }else{
		    if((tareas[j].first-instante)>=0&&encontrado){
		        if(resta>(tareas[j].first-instante)&&(tareas[j].second!=0)){
		            resta=tareas[j].first-instante;
		        	
		        }
		    }
            }
        }
        
        vector<pair<int,double>> ganancia;
        if(encontrado){
            for(int t=0; t<tareas.size(); t++){
            	int aux=tareas[t].first-instante;
                if((aux==resta)&&(tareas[t].second!=0)){
                	pair<int,double> aux1(t,tareas[t].second);
                    //aux1.first=j;
                    //aux1.second=tareas[j].second;
                    ganancia.push_back(aux1);
                    
                }
            }


            for(int j=0; j<ganancia.size(); j++){
                if(j==0){
                    max_ganancia=ganancia[j].second;
                    pos=ganancia[j].first;
                }
                if(max_ganancia<ganancia[j].second){
                    max_ganancia=ganancia[j].second;
                    pos=ganancia[j].first;
                }
            }
            

		pair<int,double> aux2;
            aux2.first=tareas[pos].first;
            aux2.second=tareas[pos].second;
            resultado.push_back(aux2);
            tareas[pos].second=0.0;
		encontrado=false;
	
            instante++;
        }

	else{
		for(int j = 0; j < tareas.size(); j++){
			if(tareas[j].second != 0){
				tareas[j].second = 0;
				resultado.push_back(tareas[j]);
			}
		}
		
	}
    }

    return resultado;
}
