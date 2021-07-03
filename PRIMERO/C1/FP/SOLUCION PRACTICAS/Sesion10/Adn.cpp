#include <iostream>
#include <string>

using namespace std;

struct Especie{
	string nombre;
	string ADN;
};

struct BaseDeDatos{
	Especie especies[1000];
	int num_especies;
};

void Ordenar (string &t);

bool ComparaSecuencias(BaseDeDatos e.especies[], string s);

int main() {
	BaseDeDatos base;
	string adn;
	bool comprobar = false;
	
	cout << "\nIntroduzca el numero de especies de la base de datos: ";
	cin >> base.num_especies;
	
	for (int i = 0; i < base.num_especies; i++){
		cout << "\nIntroduzca el nombre de la especie: ";	
		cin >> base.especies[i].nombre;
		
		cout << "\nIntroduce la cadena de ADN: ";
		cin >> base.especies[i].ADN;
	}
	
	cout << "\nIntroduzca la cadena de ADN a comprobar en la base de datos; ";
	cin >> adn;
	
	for(int i = 0;  i < base.num_especies; i++){
		if(ComparaSecuencias(base.especies[i], adn)){
			cout << "\nEsta secuencia de ADN esta registrada en la base.\n";
			cout << "\nLa especie es: " << base.especies[i].nombre << "\n";
			comprobar = true;
		}
	}
		
	if(comprobar == false)
		cout << "\nEsta secuencia de ADN no esta registrada en la base.\n";
	
	system("pause");
}

void Ordenar(string &t){
	char aux;
	int amplitud;
		amplitud = t.size();
		
	for(int i = 0; i < amplitud; i++){
		for(int j = 0; j < amplitud - 1; j++){
			if(t[j] > t[j + 1]){
				aux = t[j];
				t[j] = t[j+1];
				t[j+1] = aux;
			}
		}
	}
};

bool CompraraSecuencias(Especie e, string s){
	bool iguales = true;
	string t1= e.ADN, t2 = s;
	int amplitud;
		amplitud = e.ADN.size();
	
	Ordenar(t1);
	Ordenar(t2);
	
	for(int i = 0; (i < amplitud)&&iguales; i++){
		if(t1[i] != t2[i])
			iguales = false;
		else
			iguales = true;
		}
	
	return iguales;
};	
