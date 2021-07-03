#include <iostream>
#include <cmath>

using namespace std;

/*Se define una funcion que calcule cada digito del numero introducido y los almacene en un vector, de derecha a izquierda */
void Inverso(int a){
	const int LONGITUD = 200;
	int vector[LONGITUD];
	int contador = 0;	
	
	do{
		vector[contador] = a % 10;			//Se van calculando los digitos del numero empezando por la derecha (unidades)
		contador++;		
		a = a / 10;								//Se almacenan en el vector
	}while(a > 0);
	
	for(int i = 0; i < contador; i++){			//Se muestra el vector sin espacios, dando lugar al numero inverso
		cout << vector[i];
	}
	
}

int main() {
	int entero;
	
	cout << "Introduzca un numero entero: ";
	cin >> entero;
	
	cout << "\nEl inverso del entero es: ";
	Inverso(entero);
	
	cout << "\n";
	system("pause");
}
		
