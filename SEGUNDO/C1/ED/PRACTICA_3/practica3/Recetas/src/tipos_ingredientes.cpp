#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include "ingredientes.h"
#include "ingrediente.h"
#include "VD.h"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"

using namespace std;

void Ayuda();
VD<pair<double,string>>maximo(const ingredientes & tipo);
VD<pair<double,string>>minimo(const ingredientes & tipo);
VD<double> media(const ingredientes & tipo);
VD<double> desviacion(const ingredientes & tipo);

int main(int argc, char *argv[]){
    
    if(argc!=3){
        Ayuda();
        return 0;
    }
    
    string nf = argv[1];
    
    ifstream f(nf);
    if(!f){
        cout << "ERROR AL ABRIR EL ARCHIVO";
        return 0;
    }
    
    string linea; //Para quitar la primera linea
    getline(f,linea);
    
    ingredientes all_ingre;
    f >> all_ingre;
    
    VD<string> tipos = all_ingre.getTipos();
    cout << "Los tipos de alimentos son: " << endl;
    for(int i=0; i < tipos.size(); ++i){
        cout << tipos[i] << endl;
    }
    
    cout << "Pulse una tecla para continuar " << endl;
    cin.get();
    
    string tipo = argv[2];
    ingredientes ingre_tipo = all_ingre.getIngredienteTipo(tipo);
    VD<double> medias=media(ingre_tipo);
    VD<double> desviaciones=desviacion(ingre_tipo);
    VD<pair<double,string>> maximo_ingre=maximo(ingre_tipo);
    VD<pair<double,string>> minimo_ingre=minimo(ingre_tipo);
    
    cout << "Los ingredientes de tipo " << tipo << " son: "  << endl << ingre_tipo << endl; 
    
    cout << "Pulse una tecla para continuar " << endl;
    cin.get();
    
    cout << "Estadística___________________________________" << endl;
    cout << "Tipo de alimento: " << tipo << endl;
    
    cout << "Promedio +- Desviación" << endl;
    
    printf(ANSI_COLOR_RED "Calorías (Alimento)\tHidratos de Carb(Alimento)\tProteínas(Alimento)\tGrasas(Alimento)\tFibra(Alimento)\n" ANSI_COLOR_RESET);
    
    for(int i=0; i < medias.size(); i++)
	cout << medias[i] << "+-" << desviaciones[i] << "\t\t    ";
    
    
    cout << "\n\n" << "Máximos valores " << endl;
    
    printf(ANSI_COLOR_RED "Calorías (Alimento)\tHidratos de Carb(Alimento)\tProteínas(Alimento)\tGrasas(Alimento)\tFibra(Alimento)\n" ANSI_COLOR_RESET);
    
    for(int i=0; i < maximo_ingre.size(); i++)
	cout << maximo_ingre[i].first << " " << maximo_ingre[i].second << "\t      ";
    
    cout << "\n\n" << "Mínimos valores: " << endl;
    
    printf(ANSI_COLOR_RED "Calorías (Alimento)\tHidratos de Carb(Alimento)\tProteínas(Alimento)\tGrasas(Alimento)\tFibra(Alimento)\n" ANSI_COLOR_RESET);
    
    for(int i=0; i < minimo_ingre.size(); i++)
	cout << minimo_ingre[i].first << " " << minimo_ingre[i].second << "\t       ";
	
    cout << "\n";
}

void Ayuda(){
    cout << "Se han introducido los datos de manera incorrecta." << endl;
    cout << " <ejecutable> <fichero_ingredientes> <tipo de ingrediente>" <<endl;
}

VD<double> media(const ingredientes & tipo){
	VD<double>medias;

	for(int i=0; i < 5; i++)
		medias.Insertar(0,i);

	
	for(int i=0; i < tipo.size();i++){
		medias[0]=medias[0]+tipo[i].getCalorias();
		medias[1]=medias[1]+tipo[i].getHc();
		medias[2]=medias[2]+tipo[i].getProteinas();
		medias[3]=medias[3]+tipo[i].getGrasas();
		medias[4]=medias[4]+tipo[i].getFibra();
	}

	for(int i=0; i < medias.size(); i++)
		medias[i]=medias[i]/tipo.size();

	return medias;
}


VD<double> desviacion(const ingredientes & tipo){
	VD<double> medias=media(tipo);
	VD<double> desviacion;

	for(int i=0; i < 5; i++)
		desviacion.Insertar(0,i);

	
	for(int i=0; i < tipo.size(); i++){
		desviacion[0]=desviacion[0]+pow(medias[0]-tipo[i].getCalorias(),2);
		desviacion[1]=desviacion[1]+pow(medias[1]-tipo[i].getHc(),2);
		desviacion[2]=desviacion[2]+pow(medias[2]-tipo[i].getProteinas(),2);
		desviacion[3]=desviacion[3]+pow(medias[3]-tipo[i].getGrasas(),2);
		desviacion[4]=desviacion[4]+pow(medias[4]-tipo[i].getFibra(),2);
	}

	for(int i=0; i < desviacion.size(); i++){
		desviacion[i]=desviacion[i]/tipo.size();
		desviacion[i]=sqrt(desviacion[i]);
	}

	return desviacion;
}



VD<pair<double,string>>maximo(const ingredientes & tipo){
	VD<pair<double,string>> maximo_valor;
	pair<double,string>auxiliar(0,"");

	for(int i=0; i < 5; i++)
		maximo_valor.Insertar(auxiliar,i);
	
	maximo_valor[0].first=tipo[0].getCalorias();
	maximo_valor[0].second=tipo[0].getNombre();
	maximo_valor[1].first=tipo[0].getHc();
	maximo_valor[1].second=tipo[0].getNombre();
	maximo_valor[2].first=tipo[0].getProteinas();
	maximo_valor[2].second=tipo[0].getNombre();
	maximo_valor[3].first=tipo[0].getGrasas();
	maximo_valor[3].second=tipo[0].getNombre();
	maximo_valor[4].first=tipo[0].getFibra();
	maximo_valor[4].second=tipo[0].getNombre();		

	for(int i=0; i < tipo.size()-1; i++){
		if(maximo_valor[0].first < tipo[i+1].getCalorias()){
			maximo_valor[0].first=tipo[i+1].getCalorias();
			maximo_valor[0].second=tipo[i+1].getNombre();
		}
		if(maximo_valor[1].first < tipo[i+1].getHc()){
			maximo_valor[1].first=tipo[i+1].getHc();
			maximo_valor[1].second=tipo[i+1].getNombre();
		}
		if(maximo_valor[2].first < tipo[i+1].getProteinas()){
			maximo_valor[2].first=tipo[i+1].getProteinas();
			maximo_valor[2].second=tipo[i+1].getNombre();
		}
		if(maximo_valor[3].first < tipo[i+1].getGrasas()){
			maximo_valor[3].first=tipo[i+1].getGrasas();
			maximo_valor[3].second=tipo[i+1].getNombre();
		}
		if(maximo_valor[4].first < tipo[i+1].getFibra()){
			maximo_valor[4].first=tipo[i+1].getFibra();
			maximo_valor[4].second=tipo[i+1].getNombre();
		}
	}

	return maximo_valor;
}

VD<pair<double,string>>minimo(const ingredientes & tipo){
	VD<pair<double,string>> minimo_valor;
	pair<double,string>auxiliar(0,"");

	for(int i=0; i < 5; i++)
		minimo_valor.Insertar(auxiliar,i);
	
	minimo_valor[0].first=tipo[0].getCalorias();
	minimo_valor[0].second=tipo[0].getNombre();
	minimo_valor[1].first=tipo[0].getHc();
	minimo_valor[1].second=tipo[0].getNombre();
	minimo_valor[2].first=tipo[0].getProteinas();
	minimo_valor[2].second=tipo[0].getNombre();
	minimo_valor[3].first=tipo[0].getGrasas();
	minimo_valor[3].second=tipo[0].getNombre();
	minimo_valor[4].first=tipo[0].getFibra();
	minimo_valor[4].second=tipo[0].getNombre();		

	for(int i=0; i < tipo.size()-1; i++){
		if(minimo_valor[0].first > tipo[i+1].getCalorias()){
			minimo_valor[0].first=tipo[i+1].getCalorias();
			minimo_valor[0].second=tipo[i+1].getNombre();
		}
		if(minimo_valor[1].first > tipo[i+1].getHc()){
			minimo_valor[1].first=tipo[i+1].getHc();
			minimo_valor[1].second=tipo[i+1].getNombre();
		}
		if(minimo_valor[2].first > tipo[i+1].getProteinas()){
			minimo_valor[2].first=tipo[i+1].getProteinas();
			minimo_valor[2].second=tipo[i+1].getNombre();
		}
		if(minimo_valor[3].first > tipo[i+1].getGrasas()){
			minimo_valor[3].first=tipo[i+1].getGrasas();
			minimo_valor[3].second=tipo[i+1].getNombre();
		}
		if(minimo_valor[4].first > tipo[i+1].getFibra()){
			minimo_valor[4].first=tipo[i+1].getFibra();
			minimo_valor[4].second=tipo[i+1].getNombre();
		}
	}

	return minimo_valor;
}
	











	

