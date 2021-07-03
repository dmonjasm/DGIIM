/*Programa que lea los datos fiscales de una persona, reajuste su renta bruta según unos criterios
e imprima su renta neta final.
Se necesita: renta bruta, si el trabajador es autonomo, si es pensionista, estado civil
					renta_bruta,		autonomo						pensionista			estado_civil
Se obtiene: renta neta
					renta_neta
*/

#include <iostream>			//Se declara la biblioteca E/S iostream
#include <cmath> 				//Se declara la biblioteca de operaciones matemtacias cmath

using namespace std;

int main() {
	bool autonomo, pensionista;						//Se declaran las variables de tipo logico que usaremos para saber si una persona es o no autonomo y pensionista
	int estado_civil;										//Se declara la variable de tipo entero estado_civil y en ella asignaremos del uno al cinco los posibles estados civiles
	double renta_bruta, renta_neta, retencion;	//Se declaran las variables de tipo real para la renta bruta, la reta neta y la retencion

	
	cout << "Declare si es usted autonomo o no (1 = si/0 = no): ";																		//Se pide al usuario que declare si es autonomo indicando los posibles casos
	cin >> autonomo;			//Se guarda el valor de la variable autonomo donde 1 le da valor de verdadero y 0 de falso
	cout << "\nDeclare si es usted pensionista o no (1 = si/0 = no): ";																//Se pide al usuario que declare si es pensionista indicando los posibles casos
	cin >> pensionista;		//Se guarda el valor de la variable autonomo donde 1 le da valor de verdadero y 0 de falso
	cout << "\nDeclare su estado civil (1 = solter@/2 = casad@/3 = comprometid@/4 = divorciad@/ 5 = viud@): ";			//Se pide al usuario que declare su estado civil indicando los posibles casos
	cin >> estado_civil;		//Se guarda el valor de la variable estado civil donde anteriormente se han especificado el significado de cada valor al usuario
	cout << "\nIntroduzca su renta bruta: ";																									//Se pide al usuario que declare su renta bruta
	cin >> renta_bruta;		//Se guarda el valor de la renta bruta
	cout << "\nDeclare su retencion inicial: ";
	cin >> retencion;
	
	if (autonomo){															//Se declaran las distintas condiconales con las que se calculará el nuevo valor de la retención
		retencion = retencion - (0.03 * retencion);				//Se establece que si el usuario es autonomo se le aplique una reducción de la retención de un tres por ciento sobre la inicial
	}
	else {																	//Se establece que si el usuario no es autonomo se le apliquen las siguientes variaciones en la retencion
		if (pensionista){													//Si el usuario no es autonomo y es pensionista se aumenta su retencion en un uno por ciento sobre la inicial
			retencion = retencion + (0.01 * retencion);
		}
		else {																//Si el usuario no es autonomo y no es pensionista se aumenta su retencion en un dos por ciento sobre la inicial
			retencion = retencion + (0.02 * retencion);
			}
		}
		if (renta_bruta < 20000)									//Se establece que si la renta es inferior a 20000 se aumente la retención en un seis por cierto sobre la ya calculada hasta ahora
			retencion = retencion + (0.06 * retencion);
		else {
			if ((estado_civil == 2)&&(renta_bruta > 20000))		//Se establece que si el usuario esta casado y su renta bruta es mayor de 20000 se aumente su retencion en un ocho por cierto sobre la ya calculada hasta ahora
			retencion = retencion + (0.08 * retencion);
			else {
		if ((estado_civil == 1)&&(renta_bruta > 20000))		//Se establece que si el usuario esta soltero y su renta bruta es mayor de 2000o se aumente su retencion en un diez por ciento sobre la ya calculada hasta ahora
			retencion = retencion + (0.1 * retencion);
		}
	}
	
		renta_neta = renta_bruta - (renta_bruta * (retencion / 100));			//Se decalra el algortimo con el que se calculará la renta neta
		
		cout << "Su renta neta es: " << renta_neta << "\n\n";						//Se muestra en pantalla la renta neta del usuario en función de los datos que han sido proporcionados
		
		system("pause");
	}
	
