#include <iostream>

using namespace std;


void funcion(int &entero, int minimo=2);

int main() {
	int entero=10;
	int minimo=5;
	
	funcion(entero);
	
	cout << entero << endl;
	
	funcion(entero,minimo);
	
	cout << entero << endl;
	
	return 0;
}

void funcion(int &entero, int minimo){
	entero+=minimo;
}
	
