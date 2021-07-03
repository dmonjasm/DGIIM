/*Progama que incluya una variable edad y otra variable ingresos y en el que si la persona es un jubilado
con ingresos infeririores a 300 euros suba suba su salario un 5% y lo muestre por pantalla.
Se necesita: edad e ingresos
					edad  ingresos
Se obtiene: subida de salario o un mensaje de no aplicable.
				salario_final 			mensaje
*/

#include <iostream>			//Se incluye la biblioteca de E/S iostream
#include <cmath>				//Se incluye la biblioteca de operaciones matematicas cmath
#include <string> 			//Se incluye la biblioteca de cadenas de caracteres string

using namespace std;

int main() {
	int edad;
	double ingresos, operacion, salario_final;
	string mensaje, salario;
	bool jubilado;
	
	cout << "Introduzca la edad de la persona: ";			//Pido al usuario la edad de la persona en numero enteros
	cin >> edad;			//Guardo la edad de la persona en la variable int edad
	cout << "Introduzca los ingresos de la persona: ";		//Pido al usuario los ingresos de la persona en numero real
	cin >> ingresos;		//Gurado los ingresos de la persona en la variable double edad
	
		jubilado = (edad > 65)&&(ingresos < 300);			//Establezco la condicion que dira si la persona es jubilada o no
		mensaje = "No es aplicable la subida";				//Establezco el mensaje que se mostrará si la persona no cumple los requisitos para la subida
		salario = "El salario de la persona es: ";		//Establezco el mensaje por el cual devolvera la maquina el resultado
		operacion = (ingresos / 100) * 5;					//Establezco la operacion en caso de que la persona cumpla los requisitos para la subida
	

	
	if (jubilado){														//Establezco la estructura condicional if - else que combina E/S con cómputos
		salario_final = (operacion) + ingresos;
		cout << "\n" << salario << salario_final << "\n\n";
	}
	else {
		salario_final = ingresos;
		cout << "\n" << mensaje << "\n";
		cout << salario << salario_final << "\n\n";
	}
	
	system("pause");			//Pauso el sistema
	
	if (jubilado){													//Establezco la estructura condicional if - else separando E/S y computos
		salario_final = (operacion) + ingresos;
	}
	else 
		salario_final = ingresos;
	
	if (jubilado)
		cout << "\n" << salario << salario_final << "\n";
	else {
		cout << "\n" << mensaje << "\n";
		cout << salario << salario_final << "\n\n";
	}
		
	system("pause");			//Pauso el sistema	
}
			
