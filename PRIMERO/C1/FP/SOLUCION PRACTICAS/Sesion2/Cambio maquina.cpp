/*Programa que simule el procedimiento que sigue una maquina de refrescos al dar la vuelta tras la compra de un producto
Se necesita: el precio del producto y el dinero ingresado
						prec							diner
Se obtiene: la vuelta en monedas de un euro, cincuenta, veinte, diez y cinco cent
					vuelt							euro	cincuen		veint		diez	cinc
*/

#include <iostream>		//Se declara la biblioteca iostream
#include <cmath> 			//Se declara la biblioteca de operaciones matematicas cmath


using namespace std;	


int main() {
	double prec, diner, vuelt;								//Se declaran las variables 
	int euro, cincuent, veint, diez, cinc;				//que se van a utilizar
	
	
	cout << "Introduzca el precio del producto que desea comprar: ";				//Se introduce la variable prec
	cin >> prec;
	cout << "Introduzca el importe introducido: ";										//Se introduce la variable diner
	cin >> diner;
	
	if (diner < prec){																				//Establezco que en el caso de que el precio sea mayor que el dinero introducido
			cout << "El importe introducido es menor que el precio del producto\n";			//se muestre un mensaje diciendo que el importe introducido es menor que el precio
   		system("pause");
   		return 0;
}
	
	
	vuelt = diner - prec;																						//Se declara los algoritmos con los que el ordenador
	euro = vuelt / 100;
	cincuent = ((vuelt - euro * 100) ) / 50;																//va a calcular las monedas a devolver
	veint = (((vuelt - euro * 100)) - cincuent * 50) / 20;
	diez = ((((vuelt - euro * 100)) - cincuent * 50) - veint * 20) / 10;							// teniendo en cuenta el importe introducido y el precio del producto
	cinc = (((((vuelt - euro * 100)) - cincuent * 50) - veint * 20) - diez * 10) / 5;
	
	cout << "Su cambio es de " << euro << " monedas de un euro. ";
	cout << "\nSu cambio es de " << cincuent << " monedas de cincuenta centimos.";
	cout << "\nSu cambio es de " << veint << " monedas de veinte centimos. ";
	cout << "\nSu cambio es de " << diez << " monedas de diez centimos. ";
	cout << "\nSu cambio es de " << cinc << " monedas de cinco centimos.\n ";
	
	system("pause");
	
}
