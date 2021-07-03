/*Progarama para calcular el area de un triangulo a partir de la medida de los lados en 
cm y del angulo que forman en grados
Se necesidta: el angulo y el valor de los dos catetos.
						ang									a  b
Se obtiene: el area del triangulo
					A
*/

#include <iostream> 			//Se declara la biblioteca iostream
#include <cmath> 				//Se declara la biblioteca de operaciones matematicas cmath	

using namespace std;

int main() {
	double cateto_a,cateto_b;			//Se declaran las variables de los catetos a y b en centimetros
	double ang;				//Se declara las variable del angulo en grados
	double Area;				//Se declara la variable del area en cm^2
	double radian;				//Se declara el paso de grados a radianes
	
	
	
	cout << "Introduzca el valor del cateto a en centimetros: ";							//Se pide al usuario que introduzca un valor para el cateto a
	cin >> cateto_a;
	cout << "Introduzca el valor del cateto b en centimetros: ";							//Se pide al usuario que introduzca un valor para el cateto b
	cin >> cateto_b;
	cout << "Introduzca el valor del angulo que forman ambos catetos en grados: ";	//Se pide al usuario que introduzca un valor par el angulo
	cin >> ang;
	
	radian = (ang * M_PI / 180);			//Se declara el algoritmo para pasar de grados a radianes
	Area = (cateto_a * cateto_b * sin(radian)) / 2;			//Se declara el algoritmo que se usara para calcular el area
	
	
	cout << "El valor del area del triangulo en centimetros cuadrados es: " << Area << "\n\n";			//Se muestra en pantalla el resultado del area
	
	system("pause");
}
