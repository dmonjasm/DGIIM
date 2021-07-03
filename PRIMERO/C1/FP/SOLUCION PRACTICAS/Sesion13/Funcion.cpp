#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

int Funcion(int i, int d, int e){
	int medio;
	int absoluto = abs(i - d);
	
	medio = (i + d) / 2;
	
	if(absoluto < e)
		return absoluto;
		
	else{
	if((((medio + 2) > 0)&&((d + 2) > 0))||(((medio + 2) < 0)&&((d + 2)< 0)))
		return Funcion(i, medio, e);
		
	else{
	if((((medio + 2) > 0)&&((i + 2) > 0))||(((medio + 2) < 0)&&((i + 2)< 0)))
		return Funcion(medio, d, e);
	}
}
		
}

int main() {
	int extremo_inferior;
	int extremo_superior;
	int constante, raiz;
	
	cout << "\nIntroduzca el extremo inferior del intervalo: ";
	cin >> extremo_inferior;
	
	cout << "\nIntroduzca el extremo superior del intervalo: ";
	cin >> extremo_superior;
	
	cout << "\nIntroduzca la constante epsilon: ";
	cin >> constante;
	
	raiz = Funcion(extremo_inferior, extremo_superior, constante);
	
	cout << "\nLa raiz de la función definida en el intervalo [i,d] es: " << raiz << "\n";
	
	system("pause");
}
	
	
