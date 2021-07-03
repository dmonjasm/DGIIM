/*Programa que introducido un valor entero para los dias, el mes y el año, muestre en pantalla
como resultado la fecha siguiente, la fecha anterior y copie la fecha en otra variable.
*/

#include <iostream>			//Se declara la biblioteca de E/S iostream
#include <cmath> 				//Se declara la biblioteca de operaciones matematicas cmath

using namespace std;

struct fecha{
	int dia;
	int mes;
	int year;
};

int main() {
	fecha inicial, siguiente, anterior, copia;
	bool mes_impar, mes_par, diciembre, febrero1, mes_normal, mes_distinto, febrero_bisiesto, bisiesto, febrero2, febrero_nobisiesto;
	bool marzo, enero, mes_normal1, mes_distinto1, mes_par1, mes_impar1;
	
	cout << "Introduzca un valor entero para los dias: ";
	cin >> inicial.dia;
	cout << "Introduzca un valor entero para los meses: ";
	cin >> inicial.mes;
	cout << "Introduzca un valor entero para los anos: ";
	cin >> inicial.year;
	
	
	bisiesto = ((inicial.year % 4) == 0)&&(((inicial.year % 100) != 0)||((inicial.year % 400) == 0));
	mes_impar = ((1 < (inicial.dia + 1))&&((inicial.dia + 1) <= 31))&&((inicial.mes == 1)||(inicial.mes == 3)||(inicial.mes == 5)||(inicial.mes == 7)||(inicial.mes == 8)||(inicial.mes == 10)||(inicial.mes == 12));
	mes_par = ((1 < (inicial.dia + 1))&&(30 >= (inicial.dia + 1)))&&((inicial.mes == 4)||(inicial.mes == 6)||(inicial.mes == 9)||(inicial.mes == 11));
	febrero1 = (((1 < (inicial.dia + 1))&&((inicial.dia + 1) <= 29))&&(inicial.mes == 2));
	mes_normal = ((inicial.dia + 1) > 30)&&((inicial.mes == 4)||(inicial.mes == 6)||(inicial.mes == 9)||(inicial.mes == 11));
	mes_distinto = ((inicial.dia + 1) > 31)&&((inicial.mes == 1)||(inicial.mes == 3)||(inicial.mes == 5)||(inicial.mes == 7)||(inicial.mes == 8)||(inicial.mes == 10));
	diciembre = ((inicial.dia + 1) > 31)&&(inicial.mes == 12);
	febrero_bisiesto = ((inicial.dia + 1) > 29)&&(inicial.mes == 2);
	febrero2 = (((inicial.dia + 1) >= 1)&&((inicial.dia + 1) < 28))&&(inicial.mes == 2);
	febrero_nobisiesto = ((inicial.dia + 1) > 28)&&(inicial.mes == 2);
	
	
	if (bisiesto){														//Introduzco todos los condicionales que se pueden dar en caso de que el año fuese bisiesto.
		if(mes_impar){
			siguiente.dia = inicial.dia + 1;
			siguiente.mes = inicial.mes;
			siguiente.year = inicial.year;
		}
		if(mes_par){
			siguiente.dia = inicial.dia + 1;
			siguiente.mes = inicial.mes;
			siguiente.year = inicial.year;
		}
		if(febrero1){
			siguiente.dia = inicial.dia + 1;
			siguiente.mes = inicial.mes;
			siguiente.year = inicial.year;
		}
		if(diciembre){
			siguiente.dia = inicial.dia + 1 - 31;
			siguiente.mes = inicial.mes + 1 - 12;
			siguiente.year = inicial.year + 1;
		}
		if(febrero_bisiesto){
			siguiente.dia = inicial.dia + 1 - 29;
			siguiente.mes = inicial.mes + 1;
			siguiente.year = inicial.year;
		}
		if(mes_normal){
			siguiente.dia = inicial.dia + 1 - 30;
			siguiente.mes = inicial.mes + 1;
			siguiente.year = inicial.year;
		}
		if(mes_distinto){
			siguiente.dia = inicial.dia + 1 - 31;
			siguiente.mes = inicial.mes + 1;
			siguiente.year = inicial.year;
		}
		cout << "\nLa fecha siguiente es: " << siguiente.dia << "/" << siguiente.mes << "/" << siguiente.year << "\n";
		cout << "\nEl anio introducido es bisiesto.\n\n";
	}
	
	else {																				//Se declaran todas las posibles condiciones en caso de que el año no sea bisiesto
		cout << "\nEl anio introducido no es bisiesto\n";
				if(mes_impar){
					siguiente.dia = inicial.dia + 1;
					siguiente.mes = inicial.mes;
					siguiente.year = inicial.year;
		}
				if(mes_par){
					siguiente.dia = inicial.dia + 1;
					siguiente.mes = inicial.mes;
					siguiente.year = inicial.year;
		}
				if(febrero2){
					siguiente.dia = inicial.dia + 1;
					siguiente.mes = inicial.mes;
					siguiente.year = inicial.year;
		}
				if(diciembre){
					siguiente.dia = inicial.dia + 1 - 31;
					siguiente.mes = inicial.mes + 1 - 12;
					siguiente.year = inicial.year + 1;
		}
				if(febrero_nobisiesto){
					siguiente.dia = inicial.dia + 1 - 28;
					siguiente.mes = inicial.mes + 1;
					siguiente.year = inicial.year;
		}
				if(mes_normal){
					siguiente.dia = inicial.dia + 1 - 30;
					siguiente.mes = inicial.mes + 1;
					siguiente.year = inicial.year;
		}
				if(mes_distinto){
					siguiente.dia = inicial.dia + 1 - 31;
					siguiente.mes = inicial.mes + 1;
					siguiente.year = inicial.year;
		}
		cout << "\nLa fecha siguiente es: " << siguiente.dia << "/" << siguiente.mes << "/" << siguiente.year << "\n";
	}
	
	system("pause");
	
	marzo = ((inicial.dia - 1) == 0)&&(inicial.mes == 3);
	enero = ((inicial.dia - 1) == 0)&&(inicial.mes == 1);
	mes_normal1 = ((inicial.dia - 1) == 0)&&((inicial.mes == 2)||(inicial.mes == 4)||(inicial.mes == 6)||(inicial.mes == 8)||(inicial.mes == 9)||(inicial.mes == 11));
	mes_distinto1 = ((inicial.dia - 1) == 0)&&((inicial.mes == 5)||(inicial.mes == 7)||(inicial.mes == 10)||(inicial.mes == 12));
	mes_par1 = ((inicial.dia - 1) >= 1)&&((inicial.dia - 1) < 30);
	mes_impar1 = ((inicial.dia - 1) >= 1)&&((inicial.dia - 1) < 31);
	
	if (bisiesto){
		if(marzo){
			anterior.dia = inicial.dia - 1 + 29;
			anterior.mes = inicial.mes - 1;
			anterior.year = inicial.year;
		}
		if(enero){
			anterior.dia = inicial.dia - 1 + 31;
			anterior.mes = inicial.mes - 1 + 12;
			anterior.year = inicial.year - 1;
		}
		if(mes_normal1){
			anterior.dia = inicial.dia - 1 + 31;
			anterior.mes = inicial.mes - 1;
			anterior.year = inicial.year;
		}
		if(mes_distinto1){
			anterior.dia = inicial.dia - 1 + 30;
			anterior.mes = inicial.mes - 1;
			anterior.year = inicial.year;
		}
		if(mes_par1){
			anterior.dia = inicial.dia - 1;
			anterior.mes = inicial.mes;
			anterior.year = inicial.year;
		}
		if(mes_impar1){
			anterior.dia = inicial.dia - 1;
			anterior.mes = inicial.mes;
			anterior.year = inicial.year;
		}
		cout << "\nLa fecha anterior es: " << anterior.dia << "/" << anterior.mes << "/" << anterior.year << "\n";
	}
	else {
				if(marzo){
					anterior.dia = inicial.dia - 1 + 28;
					anterior.mes = inicial.mes - 1;
					anterior.year = inicial.year;
		}
				if(enero){
					anterior.dia = inicial.dia - 1 + 31;
					anterior.mes = inicial.mes - 1 + 12;
					anterior.year = inicial.year - 1;
		}
				if(mes_normal1){
					anterior.dia = inicial.dia - 1 + 31;
					anterior.mes = inicial.mes - 1;
					anterior.year = inicial.year;
		}
				if(mes_distinto1){
					anterior.dia = inicial.dia - 1 + 30;
					anterior.mes = inicial.mes - 1;
					anterior.year = inicial.year;
		}
				if(mes_par1){
					anterior.dia = inicial.dia - 1;
					anterior.mes = inicial.mes;
					anterior.year = inicial.year;
		}
				if(mes_impar1){
					anterior.dia = inicial.dia - 1;
					anterior.mes = inicial.mes;
					anterior.year = inicial.year;
		}
		cout << "\nLa fecha anterior es: " << anterior.dia << "/" << anterior.mes << "/" << anterior.year << "\n";
	}
	
	system("pause");
	
	
	copia = anterior;
	
	
	cout << "\nLa fecha copiada de una variable a otra es: " << copia.dia << "/" << copia.mes << "/" << copia.year << "\n";
			
	
system("pause");
}

		
