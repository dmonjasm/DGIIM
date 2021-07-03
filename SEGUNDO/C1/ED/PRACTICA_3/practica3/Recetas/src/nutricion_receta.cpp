#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<list>
#include<fstream>
#include "receta.h"
#include "recetas.h"
#include "ingrediente.h"
#include "ingredientes.h"

using namespace std;

float calcularCalorias(receta rec, ingredientes ing){
    list<pair<string,unsigned int>> ingredientes = rec.getIngredientes();
    float cal_totales = 0;
    float cal_ingrediente = 0;
    list<pair<string,unsigned int>>::iterator it;
    ingredientes::iterator iter;
    
    for(it = ingredientes.begin(); it != ingredientes.end(); ++it ){
        for(iter = ing.begin(); iter != ing.end(); ++iter){
            if((*it).first == (*iter).getNombre()){
                cal_ingrediente = ((*it).second * (*iter).getCalorias())/100;
                cal_totales += cal_ingrediente;
            }
        }
    }
    
    return cal_totales;
    
}

float calcularHc(receta rec, ingredientes ing){
    list<pair<string,unsigned int>> ingredientes = rec.getIngredientes();
    float hc_totales = 0;
    float hc_ingrediente = 0;
    list<pair<string,unsigned int>>::iterator it;
    ingredientes::iterator iter;
    
    for(it = ingredientes.begin(); it != ingredientes.end(); ++it ){
        for(iter = ing.begin(); iter != ing.end(); ++iter){
            if((*it).first == (*iter).getNombre()){
                hc_ingrediente = ((*it).second*(*iter).getHc())/100;
                hc_totales += hc_ingrediente;
            }
        }
    }
    
    return hc_totales;
}

float calcularProteinas(receta rec, ingredientes ing){
    list<pair<string,unsigned int>> ingredientes = rec.getIngredientes();
    float prot_totales = 0;
    float prot_ingrediente = 0;
    list<pair<string,unsigned int>>::iterator it;
    ingredientes::iterator iter;
    
    for(it = ingredientes.begin(); it != ingredientes.end(); ++it ){
        for(iter = ing.begin(); iter != ing.end(); ++iter){
            if((*it).first == (*iter).getNombre()){
                prot_ingrediente = ((*it).second*(*iter).getProteinas())/100;
                prot_totales += prot_ingrediente;
            }
        }
    }
    
    return prot_totales;
}

float calcularGrasas(receta rec, ingredientes ing){
    list<pair<string,unsigned int>> ingredientes = rec.getIngredientes();
    float gras_totales = 0;
    float gras_ingrediente = 0;
    list<pair<string,unsigned int>>::iterator it;
    ingredientes::iterator iter;
    
    for(it = ingredientes.begin(); it != ingredientes.end(); ++it ){
        for(iter = ing.begin(); iter != ing.end(); ++iter){
            if((*it).first == (*iter).getNombre()){
                gras_ingrediente = ((*it).second*(*iter).getGrasas())/100;
                gras_totales += gras_ingrediente;
            }
        }
    }
    
    return gras_totales;
}

float calcularFibra(receta rec, ingredientes ing){
    list<pair<string,unsigned int>> ingredientes = rec.getIngredientes();
    float fibr_totales = 0;
    float fibr_ingrediente = 0;
    list<pair<string,unsigned int>>::iterator it;
    ingredientes::iterator iter;
    
    for(it = ingredientes.begin(); it != ingredientes.end(); ++it ){
        for(iter = ing.begin(); iter != ing.end(); ++iter){
            if((*it).first == (*iter).getNombre()){
                fibr_ingrediente = ((*it).second*(*iter).getFibra())/100;
                fibr_totales += fibr_ingrediente;
            }
        }
    }
    
    return fibr_totales;
}

float maximo(float a, float b){
    float retorno=0;

    if(a >= b)
        retorno=a;
    
    else
        retorno=b;
    
    return retorno;
    
}

float caloriasTotales(const vector<receta> & admitted){
    float acumulador=0;
    int tamanio; //Para quitar Warning
    
    for(int i=0; i < (tamanio = admitted.size()); i++)
        acumulador+=admitted.at(i).getCalorias();
    
    return acumulador;
}

float proteinasTotales(const vector<receta> & admitted){
    float acumulador=0;
    int tamanio; //Para quitar Warning
    
    for(int i=0; i < (tamanio = admitted.size()); i++)
        acumulador+=admitted.at(i).getProteinas();
    
    return acumulador;
}

vector<receta> recetasAdmitidas(recetas todas_recetas, int max_calorias){
    float ** matriz;
    float razon=0;
    int columna= max_calorias;
    int auxiliar=0;
    vector<receta> admitidas;
    recetas::iterator it=todas_recetas.begin();
    
    matriz=new float * [todas_recetas.size()+1];
    
    for(int i=0; i < todas_recetas.size()+1; i++)
        matriz[i]= new float [max_calorias+1];
        
        
    for(int i=0; i < todas_recetas.size()+1; i++){
        if(i > 0)
            razon=(*it).getProteinas()/(*it).getHc();
      
        for(int j=0; j < max_calorias+1; j++){
            if(i==0 || j==0)
                matriz[i][j]=0;
            
            else{
                auxiliar=(*it).getCalorias();
                if(auxiliar >= j)
                    matriz[i][j]=matriz[i-1][j];
                
                else{
                    matriz[i][j] = maximo(matriz[i-1][j],matriz[i-1][j-auxiliar]+razon);
                }
            }
        }
        
        if(i != 0)
            ++it;
    }
    
    --it;
    
    for(int i=todas_recetas.size(); i > 0; i--){
        if(i==todas_recetas.size()){
            if(matriz[i][max_calorias]!=matriz[i-1][columna]){
                admitidas.push_back((*it));
                auxiliar=(*it).getCalorias();
                columna = columna -auxiliar;
            }
        }
        
        else{            
            if(matriz[i][columna]!=matriz[i-1][columna]){
                admitidas.push_back((*it));
                auxiliar=(*it).getCalorias();
                columna=columna - auxiliar;
            }
        }
        
        --it;         
    }
        
    for(int i=0; i < todas_recetas.size()+1; i++)
        delete [] matriz[i];
    
    delete [] matriz;
    
    return admitidas;     
}

int main(int argc, char *argv[]){
    if(argc !=4){
        cerr << "Error al introducir los datos" << endl;
        exit(-1);
    }
    
    vector<receta> admitidas;
    int calorias_max=stoi(argv[3]);
    
    string rec = argv[1];
    
    ifstream f(rec);
    
    if(!f){
        cerr << "ERROR AL ABRIR EL FICHERO " << rec << endl;
        return 0;
    }
    
    recetas allrecet;
    f >> allrecet;
    
    string in = argv[2];
    ifstream s(in);
    
    if(!s){
        cerr << "ERROR AL ABRIR EL FICHERO " << in << endl;
        return 0;
    }
    
    ingredientes allingre;
    s >> allingre;
  
    recetas::iterator it;
    
    for(it = allrecet.begin(); it != allrecet.end(); ++it){
        (*it).setCalorias(calcularCalorias(*it, allingre));
        (*it).setHc(calcularHc(*it, allingre));
        (*it).setProteinas(calcularProteinas(*it, allingre));
        (*it).setGrasas(calcularGrasas(*it, allingre));
        (*it).setFibra(calcularFibra(*it, allingre));
    }
    
    
    
    
    
    for(it = allrecet.begin(); it != allrecet.end(); ++it){
        cout << "Valores Nutricionales de la receta: " << (*it)<< endl;
        cout << "Calorías: \t" << (*it).getCalorias() << "\t\t Hidratos de Carb: " << (*it).getHc() << "\t\t Proteínas: " << (*it).getProteinas() << "\t\t Grasas: " << (*it).getGrasas() << "\t\t Fibra: " << (*it).getFibra() << endl << endl;
    }
    
    admitidas=recetasAdmitidas(allrecet, calorias_max);
    cout << "________________________________________________________________" << endl;
    cout << "Las calorías máximas introducidas por el usuario son: "  << calorias_max << endl;
 
    cout << "Las recetas escogidas son: " << endl;
    for(int i=admitidas.size()-1; i >= 0; i--)
        cout << admitidas.at(i) << endl;
    
    cout << "Calorias Totales: "<< caloriasTotales(admitidas) << "\tProteinas Totales: " << proteinasTotales(admitidas) << endl;
    
    
}
