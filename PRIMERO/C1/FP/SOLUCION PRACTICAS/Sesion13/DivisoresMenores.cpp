#include <iostream>

using namespace std;

/*Se inicia una función de tipo int que calcule los divisores propios del numero introducido que sean menores que el tope introducido */
int divisoresMenores(int n, int k){
	bool no_divisible = true;
	int num_divisores = 0;
	int numero;
	
	if(n == 1){							//Si el numero es uno el unico divisor es uno y por tanto devuelve 1
		num_divisores = 1;
		return num_divisores;
	}
	
	else{			//Si el numero es distinto de uno se prueban uno a uno los numeros menores que el tope hasta encontrar un divisor propio
	for(int i = k; (i > 1)&&(no_divisible); i--){
		if(((n % i) == 0)&&(i < k)){
			no_divisible = false;
			numero = n / i;
	}
		else	
			no_divisible = true;
}
	if(no_divisible == false)			//Si se encuentra un divisor propio se divide el numero entre dicho divisor y se aumenta el numero de divisores en uno
		num_divisores++;

		
	else{								//Si no se encuentra divisores implica que el numero es primo y por tanto el unico divisor del numereo que sea menor que el tope seran 
		num_divisores = 0;		// 1 ya que tendria que ser el tope mayor que el numero
		numero = 1;
	}

	num_divisores = num_divisores + divisoresMenores(numero ,k);		//Calculamos el numero total de divisores mediante la suma del numero de divisores y la aplicación de la función
																							//al numero entre el divisor propio encontrado y usando el mismo tope
	return num_divisores;
}
}


int main() {
	int numero, tope;
	int numero_divisores;
	
	cout << "\nIntroduzca el numero cuyos divisores quiere calcular: ";
	cin >> numero;
	
	cout << "\nIntroduzca el tope a partir del cual los divisores tienen que ser menores: ";
	cin >> tope;
	
	numero_divisores = divisoresMenores(numero, tope);
	
	cout << "\nEl numero de divisores del n menores que el tope k es: " << numero_divisores << "\n";
	
	system("pause");
	
}
