#include <iostream>
#include <cmath>

using namespace std;

/*Funcion tipo bool que devuelva con true si la fecha es valida o con false si no lo es*/
bool Fecha (int dia, int mes, int anio){
	bool valida = true;
	
	if(anio < 0 || anio > 9999)		//Se comprueba que el año sea valido
		valida = false;
		
	else{
		if(mes < 1 || mes > 12)			//Se comprueba que el mes sea valido
			valida = false;
		else{
			if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){			//Se comprueba que lo meses de 31 dias sean validos
				if(dia < 1 || dia > 31)
					valida = false;
				}
			else{
				if(mes == 4 || mes == 6 || mes == 9 || mes == 11){			//Se comprueba que los meses de 30 dias sean validos
					if(dia < 1 || dia > 30)
						valida = false;
					}
				else{
					if((((anio % 4) == 0)&&((anio % 100) != 0))||((anio % 400)==0)){			//Se comprueba que en los anios bisiestos febrero tenga 29 dias
						if(mes == 2){
							if(dia < 1 || dia > 29)
								valida = false;
							}
					}
					else{
						if(mes == 2){
							if(dia < 1 || dia > 28)			//Se comprueba que en los años no bisiestos febrero tenga 28 dias
								valida = false;
							}
					}
				}
			}
		}
	}
	return valida;
}

int main() {
	bool validez;
	int dia, mes, anio;
	
	cout << "\nIntroduzca una fecha: ";
	cin >> dia >> mes >> anio;
	
	validez = Fecha(dia, mes, anio);
	
	if(validez)
		cout << "\nLa fecha introducida es valida\n";
	else
		cout << "\nLa fecha introducida no es valida\n";
		
	system("pause");
}
	

