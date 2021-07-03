#include <iostream>
#include <cmath>

using namespace std;

	bool Amigos(int entero1, int entero2){
		
		int suma_entero1, suma_entero2;
		bool amigos;
		
		for(int i = 1; i < entero1; i++){
			if(entero1 % i == 0)
				suma_entero1 += i;
			}
		
		for (int i = 1; i < entero2; i++){
			if(entero2 % i == 0)
			suma_entero2 += i;
		}
		
		if ((suma_entero1 == entero2) && (suma_entero2 == entero1))
			amigos = true;
		else
			amigos = false;
		
		return amigos;
	}

int main() {
	int extremo, inferior, cambio;
	bool amigos = true;
	
	cout << "Introduce dos numeros: ";
	cin >> extremo >> inferior;
	
	if (extremo < inferior){
		cambio = inferior;
		inferior = extremo;
		extremo = cambio;
	}
	
	int contador = extremo;
	
	while(contador > inferior){
		for(int i = inferior; i < contador; i++){
			amigos = Amigos(i, contador);
			if(amigos)
				cout << i << " | " << contador;
			}
			contador--;
		}
	
	system("pause");
	}
	

