#include <iostream>
#include <cmath>

using namespace std;

int MCM(int a, int b){
	bool no_mcm;
	int minimo;
	if(a > b){
	for(int i = b; (i <= (a * b))&&(no_mcm); i++){
		if(((a % i) == 0)&&((b % i) == 0)){
			no_mcm = false;
			minimo = i;
		}	
		else
			no_mcm = true;
		}
		return minimo;
	}
	else{
		for(int i = a; (i <= (a * b))&&(no_mcm); i++){
		if(((a % i) == 0)&&((b % i) == 0)){
			no_mcm = false;
			minimo = i;
		}			
		else
			no_mcm = true;
		}
		return minimo;
	}
}

int main(){
	int un_numero, otro_numero;
	int minimo_comun;
	
	cout << "\nIntroduzca dos numeros: ";
	cin >> un_numero >> otro_numero;
	
	minimo_comun = MCM(un_numero, otro_numero);
	
	cout << "\nEl minimo comun multiplo es: " << minimo_comun << "\n";
	
	system("pause");
}

	
	

		
		
	
	
		
	
	
