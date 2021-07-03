 #include <iostream>
 #include <cmath>
 
 using namespace std;
 
 /*Se inicia una funcion que calcule el minimo comun multiplo de dos numeros*/
 int MCM(int a, int b){
 	int minimo;
 	int auxiliar;
 	
 	if(b < a){
 		auxiliar = b;
 		b = a;
 		a = auxiliar;
 	}
 	
 	/*Se inicia un bucle for que pruebe si alguno de los numero menores que un multiplo hasta el mayor de los dos numeros es multiplo de ambos numeros, y si lo hay lo almacena en 
 	una variable*/
 	for (int i = (a*b); i >= b; i--){
 		if (((i % a) == 0)&&((i % b) == 0))
 			minimo = i;
 		else
 			minimo = minimo;
 	}
 	
 	return minimo;
 }
 
 /*Se incia una funcion que calcule el maximo comun divisor de dos numeros */
 int MCD(int a, int b){
 	int maximo;
 	int auxiliar;
 	
 	if(a > b){
 		auxiliar = b;
 		b = a;
 		a = auxiliar;
 	}
 	
 	/*Se inicia un bucle for que calcule los divisores comunes de dos numeros desde 1 hasta el mas pequeño de los numeros y almacena el maximo en una variable */
 	for(int i = 1; i < a; i++){
 		if(((a % i) == 0)&&((b % i) == 0))
 			maximo = i;
 		}
 	
 	return maximo;
 	}
 	
 	/*Se inicia una funcion que una las dos anteriores y que les añada la propiedad de las suma, resta, division y multiplicacion. Dependiendo del valor del caracter
 	se realizará una y solo una de las operaciones anteriormente descritas*/
 	int Calculadora (int numero1, int numero2, char letra){
 		int operacion;
 		
 		/*Se inicia un switch en el que dependiendo del valor de la variable letra se realizará una operacon u otra*/
 		switch(letra){
 			case 'm':
 				operacion = MCM(numero1, numero2);
				 break;
			case 'd': 
				operacion = MCD(numero1, numero2);
				break;
			case'*':
				operacion = numero1 * numero2;
				break;
			case '+': 
				operacion = numero1 + numero2;
				break;
			case '-':
				operacion = numero1 - numero2;
				break;
			case '/': 
				operacion = numero1 / numero2;
				break;
			default: NAN;
		}
		return operacion;
	}
 	
 	int main() {
 		int numero_1, numero_2;
 		int operacion;
 		char caracter;
 		
 		cout << "Introduzca un numero: ";
 		cin >> numero_1;
 		cout << "\nIntroduzca otro numero: ";
 		cin >> numero_2;
 		cout << "\nIntroduzca un caracter para realizar una operacion (m,d,+,*,/,-): ";
 		cin >> caracter;
 		
 		operacion = Calculadora(numero_1, numero_2, caracter);
		
		
		cout << "\nEl resultado de la operacion es: " << operacion << "\n";
		
		system("pause");
	}
 		
