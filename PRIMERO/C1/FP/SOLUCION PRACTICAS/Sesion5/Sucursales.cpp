/*Programa que lea desde teclado una serie de resgistros compeustos por sucursal
producto, unidades y diga cuál es la sucursal que más producto ha vendido.
*/

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
	int sucursal, producto, unidades;
	int suma1, suma2, suma3;
	string texto_sucursal, texto_producto, texto_unidades;
	
	suma1 = 0;
	suma2 = 0;
	suma3 = 0;
	
	texto_sucursal = "\nIntroduzca la sucursal (1,2 ó 3): ";
	texto_producto = "\nIntroduzca el código del producto (1,2 ó 3): ";
	texto_unidades = "\nIntroduzca las unidades vendidas: ";
	
while (sucursal != -1){				//Se inicia un bucle que ejecuta el siguiente bloque siempre que el valor de sucursal sea distitno de -1
	cout << texto_sucursal;			//Se pide un valor entero al usuario y se guarda en la variable sucursal
	cin >> sucursal;
	
	if (sucursal != -1){				//Se establece un condicional en el que si el valor de la variable sucursal es distinto de -1 
		cout << texto_producto;		//pide al usuario un numero entero que almacena en la variable producto
		cin >> producto;				//pide al usuario otro numero entero que almacena en la variable unidades
		cout << texto_unidades;
		cin >> unidades;
		
		if (sucursal == 1)					//Dentro del primer condicional se establece otro condicional en el que si el valor de sucursal es igual a uno el valor de la variable suma1
			suma1 = suma1 + unidades;		//es igual a la suma de las unidades con el anterior valor de suma1.
		if (sucursal == 2)					//Se establece otro condicional en el que si el valor de la sucursal es igual a dos el valor de la variable suma2
			suma2 = suma2 + unidades;		//es igual a la suma de las unidades con el anterior valor de suma2.
		if (sucursal == 3)					//Se establece un tercer condicional en el que si el valor de la sucursal es igual a tres el valor de la variable
			suma3 = suma3 + unidades;		//suma3 es igual que la suma de las unidades con el anterior valor de suma3.
}
	else
		sucursal = -1;			//En caso de que el condicional inicial no se cumpla el valor de sucursal es -1
	}
	
	if ((suma1 > suma2)&&(suma1 > suma3)){		//Se establece que si se cumple la condición que suma1 sea mayor que suma2 y que suma3 la sucursal sea igual a 1 
		sucursal = 1;
		cout << "SUCURSAL: " << sucursal << "\nVENTAS: " << suma1 << "\n";		//y muestre por pantalla el mensaje
	}
	
	if ((suma2 > suma1)&&(suma2 > suma3)){		//Se establece que si se cumple la condición que suma2 sea mayor que suma1 y que suma3  la sucursal sea igual a 2
		sucursal = 2;
		cout << "SUCURSAL: " << sucursal << "\nVENTAS: " << suma2 << "\n";		//y muestre por pantalla el mensaje
	}
	
	if ((suma3 > suma1)&&(suma3 > suma2)){		//Se establece que si se cumple la condición que suma3 sea mayor que suma1 y que suma2  la sucursal sea igual a 3
		sucursal = 3;
		cout << "SUCURSAL: " << sucursal << "\nVENTAS: " << suma3 << "\n";		//y muestre por pantalla el mensaje
	}
	
	system("pause");
}
	
		
		
	
