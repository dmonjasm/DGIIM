#include <iostream>
#include <cmath>

using namespace std;

/*Clase que tiene tres variables un dia, un mes y un año, y que comprueba si la fecha es valida y muestra la fecha siguiente y la anterior */
class Fecha{
	private:
		int dia, mes, anio;
		bool bisiesto;
	
	public:
		Fecha(){
			/*Se establece un constructor que de valores inciales a las variables privadas dia mes y año */
			dia = 1;
			mes = 1;
			anio = 2000;
		}
		
		/*Se establece un funcion para que el usuario de valor a la variables privadas dia mes y año */
		void setFecha(){
			cout << "\nIntroduzca el dia el mes y el anio: ";
			cin >> dia >> mes >> anio;
			
		}
		
		int Dia(){
			return dia;
		}
		
		int Mes(){
			return mes;
		}
		
		int Anio(){
			return anio;
		}
		
		/*Se inicia una funcion tipo bool que comprueba si un año es bisiesto o no */
		bool Bisiesto (int anio){
			if((((anio % 4) == 0)&&((anio % 100) != 0))||((anio % 400) == 0))
				return true;
			else
				return false;
			}
		
		/*Funcion tipo bool que comprueba si la fecha introducida por el usuario es valida o no */	
		bool Validez(int dia, int mes , bool bisiesto){
			if(((dia <= 31)&&(dia >= 1))&&((mes == 1)||(mes == 3)||(mes == 5)||(mes == 7)||(mes == 8)||(mes == 10)||(mes == 12)))
				return true;
			else{
				if(((dia <= 30)&&(dia >= 1))&&((mes == 4)||(mes == 6)||(mes == 9)||(mes == 11)))
					return true;
				else{
					if((((dia <= 28)&&(dia >= 1))&&(mes == 2))&&(bisiesto == false))
						return true;
					else{
						if((((dia <= 29)&&(dia >= 1))&&(mes == 2))&&(bisiesto))
							return true;
						else
							return false;
						}
					}
				}
			}
		
		/*Funcion tipo void que muestre por pantalla la fecha siguiente a la introducida */
		void Siguiente(int dia, int mes, int anio, bool bisiesto){
			if(((dia < 31)&&(dia >= 1))&&((mes == 1)||(mes == 3)||(mes == 5)||(mes == 7)||(mes == 8)||(mes == 10)||(mes == 12)))
				dia++;
			else{
				if(((dia < 30)&&(dia >= 1))&&((mes == 4)||(mes == 6)||(mes == 9)||(mes == 11)))
					dia++;
				else{
					if(((dia < 28)&&(dia >= 1))&&(mes == 2)&&(bisiesto == false))
						dia++;
					else{
						if(((dia < 29)&&(dia >= 1))&&(mes == 2)&&(bisiesto))
							dia++;
						else{
							if((dia == 31)&&((mes == 1)||(mes == 3)||(mes == 5)||(mes == 7)||(mes == 8)||(mes == 10))){
								dia = 1;
								mes++;
							}
							else{
								if((dia == 30)&&((mes ==4)||(mes == 6)||(mes == 9)||(mes == 11))){
									dia = 1;
									mes++;
								}
								else{
									if((dia == 31)&&(mes == 12)){
										dia = 1;
										mes = 1;
										anio++;
									}
									else{
										if((dia == 28)&&(mes == 2)&&(bisiesto == false)){
											dia = 1;
											mes++;
										}
										else{
											if((dia == 29)&&(mes == 2)&&(bisiesto)){
												dia = 1;
												mes++;
											}
										}
									}
								}
							}
						}
					}
				}
			}
			cout << "\nLa fecha siguiente es: " << dia << "/" << mes << "/" << anio << "\n";
		}
		
		/*Funcion tipo void que muestra por pantalla la fecha anterior a la introducida or el usuario */
		void Anterior(int dia, int mes, int anio, bool bisiesto){
			if(((dia > 1)&&(dia <= 31))&&((mes == 1)||(mes ==3)||(mes ==5)||(mes == 7)||(mes == 8)||(mes == 10)||(mes == 12)))
				dia--;
			else{
				if(((dia > 1)&&(dia <= 30))&&((mes == 4)||(mes == 6)||(mes == 9)||(mes == 11)))
					dia--;
				else{
					if(((dia > 1)&&(dia <= 28))&&(mes == 2)&&(bisiesto == false))
						dia--;
					else{
						if(((dia > 1)&&(dia <= 29))&&(mes == 2)&&(bisiesto))
							dia--;
						else{
							if((dia == 1)&&(mes == 3)&&(bisiesto)){
								dia = 29;
								mes--;
							}
							else{
								if((dia == 1)&&(mes == 3)&&(bisiesto == false)){
									dia = 28;
									mes--;
								}
								else{
									if((dia == 1)&&(mes == 1)){
										dia = 31;
										mes = 12;
										anio--;
									}
									else{
										if((dia == 1)&&((mes == 2)||(mes == 4)||(mes == 6)||(mes == 8)||(mes == 9)||(mes == 11))){
											dia = 31;
											mes--;
										}
										else{
											if((dia = 1)&&((mes == 5)||(mes == 7)||(mes == 10)||(mes == 12))){
												dia = 30;
												mes--;
											}
										}
									}
								}
							}
						}
					}
				}
			}
			
			cout << "\nLa fecha anterior es: " << dia << "/" << mes << "/" << anio << "\n";
		}
	};
	
	int main() {
		Fecha inicio;
		
		inicio.setFecha();
		
		if(inicio.Validez(inicio.Dia(), inicio.Mes(), inicio.Bisiesto(inicio.Anio()))){
			inicio.Siguiente(inicio.Dia(), inicio.Mes(), inicio.Anio(), inicio.Bisiesto(inicio.Anio()));
			inicio.Anterior(inicio.Dia(), inicio.Mes(), inicio.Anio(), inicio.Bisiesto(inicio.Anio()));
		}
		
		else
			cout << "\nLa fecha introducida no es valida.\n";
												
		system("pause");
	}
							
