/*Programa para, una vez dados una fecha compuesta por dia, mes y año, anuncie
en pantalla la fecha siguente, la anterior, copie una variable de tipo feche en otra
y diga si el año es bisiesto o no.
*/

#include <iostream>			//Se declara la biblioteca de E/S iostream
#include <cmath>				//Se declara la biblioteca de operaciones matematicas cmath
#include <string>				//Se declara la biblioteca de cadenas de caracteres string

using namespace std;

struct fecha{
	int dia;
	int mes;
	int year;
};

int main() {
	fecha actual, siguiente, anterior, copia;
	bool bisiesto, febrero1, febrero2, normal1;
	bool febrero_normal, febrero_bisiesto, diciembre1;
	bool marzo_normal, mes_1, mes_2, enero;
	bool error, error1, error_febrero, error_febrero2;
	string mensaje_error;
			mensaje_error = "La fecha introducida no es valida";
			
	
	bisiesto = ((actual.year % 4) == 0)&&((actual.year % 100) != 0);
	normal1 = ((1 <= actual.dia)&&(actual.dia < 31))&&((actual.mes == 1)||(actual.mes == 2)||(actual.mes == 3)||(actual.mes == 4)||(actual.mes == 5)||(actual.mes == 6)||(actual.mes == 7)||(actual.mes == 8)||(actual.mes == 9)||(actual.mes == 10)||(actual.mes == 11)||(actual.mes == 12));
	febrero1 = ((1 <= actual.dia)&&(actual.dia < 28))&&(actual.mes == 2);
	febrero2 = ((1 <= actual.dia)&&(actual.dia < 29))&&(actual.mes == 2);
	febrero_normal = ((actual.dia + 1) > 28)&&(actual.mes == 2);
	febrero_bisiesto = ((actual.dia + 1) > 29)&&(actual.mes == 2);
	diciembre1 = ((actual.dia + 1) > 31)&&(actual.mes == 12);
	marzo_normal = ((actual.dia - 1) == 0)&&(actual.mes == 3);
	mes_1 = ((actual.dia - 1) == 0)&&((actual.mes == 2)||(actual.mes == 4)||(actual.mes == 6)||(actual.mes == 7)||(actual.mes == 9)||(actual.mes == 11));
	mes_2 = ((actual.dia - 1) == 0)&&((actual.mes != 1)||(actual.mes != 2)||(actual.mes != 4)||(actual.mes != 6)||(actual.mes != 7)||(actual.mes != 9)||(actual.mes != 11));
	enero = ((actual.dia - 1) == 0)&&(actual.mes == 1);
	error = ((actual.dia < 1)||(actual.dia > 31))&&((actual.mes == 1)||(actual.mes == 3)||(actual.mes == 5)||(actual.mes == 7)||(actual.mes == 8)||(actual.mes == 10)||(actual.mes == 12));
	error1 = ((actual.dia < 1)||(actual.dia > 30))&&((actual.mes == 2)||(actual.mes == 4)||(actual.mes == 6)||(actual.mes == 9)||(actual.mes == 11));
	error_febrero = ((actual.dia < 1)||(actual.dia > 28))&&(actual.mes == 2);
	error_febrero2 = ((actual.dia < 1)||(actual.dia > 29))&&(actual.mes == 2);
	
	
	cout << "Introduzca un valor entero de días: ";
	cin >> actual.dia;
	cout << "Introduzca un valor entero de meses: ";
	cin >> actual.mes;
	cout << "Introduzca un valor entero de anos: ";
	cin >> actual.year;
	
	
	if (error){
		cout << mensaje_error;
		system("pause");
		return 0;
	}
	else {
		if (error1){
			cout << mensaje_error;
			system("pause");
			return 0;
		}
		else {
			if (error_febrero){
				cout << mensaje_error;
				system("pause");
				return 0;
			}
			else {
				if (error_febrero2){
					cout << mensaje_error;
					system("pause");
					return 0;
				}
			}
		}
	}


	if (!bisiesto){
		if (febrero_normal){
			siguiente.dia = actual.dia + 1 - 28;
			siguiente.mes = actual.mes + 1;
			siguiente.year = actual.year;
		}
		else {
			if (diciembre1){
				siguiente.dia = actual.dia + 1 - 31;
				siguiente.mes = actual.mes + 1 -12;
				siguiente.year = actual.year +1;
			}
			else {
				if (febrero1){
					siguiente.dia = actual.dia + 1;
					siguiente.mes = actual.mes;
					siguiente.year = actual.year;
			}
				else {
					if (normal1){
						siguiente.dia = actual.dia + 1;
						siguiente.mes = actual.mes;
						siguiente.year = actual.year;
					}		
					else {
						if (normal1){
							siguiente.dia = actual.dia + 1;
							siguiente.mes = actual.mes;
							siguiente.year = actual.year;
						}
				}
			}
		}
	}
}
	else {
		if (febrero_bisiesto){
			siguiente.dia = actual.dia + 1 - 29;
			siguiente.mes = actual.mes + 1;
			siguiente.year = actual.year;
		}
		else {
			if (diciembre1){
				siguiente.dia = actual.dia + 1 -31;
				siguiente.mes = actual.mes + 1 -12;
				siguiente.year = actual.year + 1;
			}
			else {
				if (normal1){
					siguiente.dia = actual.dia + 1;
					siguiente.mes = actual.mes;
					siguiente.year = actual.year;
				}
				else {
					if (normal1){
						siguiente.dia = actual.dia + 1;
						siguiente.mes = actual.mes;
						siguiente.year = actual.year;
				}
			}
		}
	}
}


	if (!bisiesto){
		if (marzo_normal){
			anterior.dia = 28;
			anterior.mes = actual.mes - 1;
			anterior.year = actual.year;
		}
		else {
			if (enero){
				anterior.dia = 31;
				anterior.mes = 12;
				anterior.year = actual.year - 1;
			}
			else {
				if (mes_1){
					anterior.dia = actual.dia - 1;
					anterior.mes = actual.mes;
					anterior.year = actual.year;
				}
				else {
					if (mes_2){
						anterior.dia = actual.dia - 1;
						anterior.mes = actual.mes;
						anterior.year = actual.year;
					}
				}
			}
		}
	}
	else {
		if (marzo_normal){
			anterior.dia = 29;
			anterior.mes = actual.mes - 1;
			anterior.year = actual.year;
		}
		else {
			if (enero){
				anterior.dia = 31;
				anterior.mes = 12;
				anterior.year = actual.year - 1;
			}
			else {
				if (mes_1){
					anterior.dia = actual.dia - 1;
					anterior.mes = actual.mes;
					anterior.year = actual.year;
				}
				else {
					if (mes_2){
						anterior.dia = actual.dia - 1;
						anterior.mes = actual.mes;
						anterior.year = actual.year;
					}
				}
			}
		}
	}
	
	
	cout << "La fecha siguiente sera: " << siguiente.dia << "/" << siguiente.mes << "/" << siguiente.year << "\n";
	cout << "La fecha anterior sera: " << anterior.dia << "/" << anterior.mes << "/" << anterior.year << "\n";
	
	
	if (bisiesto)
	cout << "El año introducido es bisiesto\n\n";
	
	
	system("pause");
	
	
}
	

		
		
		
	
	
	
	
	
