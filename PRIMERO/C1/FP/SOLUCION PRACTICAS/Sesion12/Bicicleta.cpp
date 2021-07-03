#include <iostream>
#include <cstring>

using namespace std;

/*Clase con dos datos privados, un constructor, y metodos para devolver el valor de los datos privados, subir y bajar en uno el valor de los datos privados y
subir y bajar en dos los valores de la variable privada pinon */
class Marchas{
	private: 
		int estrella, pinon;
		
	public:
		Marchas(){				//Constructor sin parametros que inizializa las variables a uno
			estrella = 1;
			pinon = 1;
		}
		
		int Estrella(){			//Funcion para devolver el valor del dato privado estrella
			return estrella;
		}
		
		int Pinon(){				//Funcion para devolver el valor del dato privado pinon
			return pinon;
		}
		
		int Estrella_sube(){				//Funcion para aumentar en uno el vlaor del dato privado estrella siempre que tras el aumento sea menor o igual que tres
			if(!(((estrella + 1) == 3)&&(pinon <= 3))){							//Se introduce condicional para que la estrella no se cambie si el pinon es menor o igual a tres y la estrella cambiaria a tres
			if(!(((estrella + 1) == 2)&&((pinon == 1)||(pinon == 7)))){		//Si la estrella cambia a dos y el pinon es 1 o 7 no se ejecuta el cambio
			if((estrella + 1) <= 3)
			estrella++;
		}
	}
			
			return estrella;			
		}
		
		int Estrella_baja(){				//Funcion para disminuir en uno el valor del dato privado estrella siempre que tras la disminucion sea mayor o igual que 1
			if(!(((estrella - 1) == 2)&&((pinon == 1)||(pinon == 7)))){		//Si la estrella cambia a 2 y el pinon es 1 o 7 no se ejecuta el cambio
			if(!(((estrella - 1) == 1)&&(pinon >= 5))){							//Si la estrella cambia a 1 y el pinon es mayor o igual que 5 no se ejecuta el cambio
			if((estrella - 1) >= 1)
				estrella--;
			}
		}
			
			return estrella;
			}
		
		int Pinon_sube(){					//Funcion para aumentar en uno el valor del dato privado pinon siempre que tras el aumento sea mayor o igual que 7
			if (!(((pinon + 1) <= 3)&&(estrella == 3))){			//Si el pinon sube a un 3 o menos de tres y la estrella es tres no se ejecuta el cambio
			if (!(((pinon + 1) == 7)&&(estrella == 2))){			//Si el pinon sube a 7 y la estrella es dos no se ejecuta el cambio
			if (!(((pinon + 1) >= 5)&&(estrella == 1))){			//Si el pinon sube a 5 o mas y la estrella es uno no se ejecuta el cambio
			if((pinon + 1) <= 7)
			pinon++;
		}
	}
}
			
			return pinon;
		}
		
		int Pinon_baja(){					//Funcion para disminuir en uno el valor del dato privado pinon siempre que tras la disminucion sea mayor o igual que 1
			if (!(((pinon - 1) <= 3)&&(estrella == 3))){			//Si el pinon baja a tres o menos y la estrella es tres no es ejecuta el cambio
			if (!(((pinon - 1) == 1)&&(estrella == 2))){			//Si el pinon baja a 1 y la estrella es dos no se ejecuta el cambio
			if (!(((pinon - 1) >= 5)&&(estrella == 1))){			//Si el pinon baja a 5 o mas y la estrella es uno no se ejecuta el cambio
			if((pinon - 1) >= 1)
				pinon--;
			}
		}
	}
			
			return pinon;
			}
		
		int Pinon_salto(){				//Funcion para aumentar en dos el valor del dato privado pinon siempre que tras el aumento sea menor o igual que 7
			if (!(((pinon + 2) <= 3)&&(estrella == 3))){			//Si el pinon salta a tres o menos y la estrella es tres no se ejecuta el cambio
			if (!(((pinon + 2) == 7)&&(estrella == 2))){			//Si el pinon salta a siete y la estrella es dos no se ejecuta el cambio
			if (!(((pinon + 2) >= 5)&&(estrella == 1))){			//Si el pinon sube a 5 o mas y las estrella es uno no se ejecuta el cambio
			if((pinon + 2) <= 7)
			pinon = pinon + 2;
		}
	}
}
			
			return pinon;
		}
		
		int Pinon_caida(){				//Funcion para disminuir en dos el valor del dato privado pinon siempre que tras la disminucion sea mayor o igual que 1
		if (!(((pinon - 2) <= 3)&&(estrella == 3))){			//Si el pinon cae a tres o menos y la estrella es tres no se ejecuta el cambio
		if (!(((pinon - 2) == 1)&&(estrella == 2))){			//Si el pinon cae a uno y la estrella es dos no se ejecuta el cambio
		if (!(((pinon - 2) >= 5)&&(estrella == 1))){			//Si el pinon cae a 5 y la estrella es uno no se ejecuta el cambio
			if((pinon - 2) >= 1)
				pinon = pinon - 2;
			}
		}
	}
			
			return pinon;
			}
	};
	
	int main() {
		Marchas bicicleta;
		char instrucciones;
		string componente;
		string operacion;
			componente = "\nIntroduzca la componenete sobre la que quiere realizar la operacion (E = estrella/P = pinon): \n";
			operacion = "\nIntroduzca la operación que desea realizar (S = subir una posicion/B = bajar una posicon/T = subir dos posiciones/C = bajar dos posiciones(C y T solo para pinones)): \n";
			
			do{								//Bloque do-while que se ejecuta siempre que instrucciones sea distinto que '#'
				cout << componente;
				cin >> instrucciones;
				
				if(instrucciones != '#'){			//Condicional que ejecuta un bloque siempre que la instruccion introducida no sea el terminador
				switch(instrucciones){				//switch para elegir sobre que componente realizar la operacion
					case 'E':
						cout << operacion;
						cin >> instrucciones;
						
						switch(instrucciones){			//Switch para elegir la operacion a realizar sobre la componente
							case 'S':
								bicicleta.Estrella_sube();
								break;
							case 'B':
								bicicleta.Estrella_baja();
								break;
							default: 
								cout << "\nIntroduzca una operacion valida\n";			
						}
						
						break;
					
					case 'P':
						cout << operacion;
						cin >> instrucciones;
						
						switch(instrucciones){				//Swithc para elegir la operacion a realizar sobre la componente
							case'S':
								bicicleta.Pinon_sube();
								break;
							case 'B':
								bicicleta.Pinon_baja();
								break;
							case'T':
								bicicleta.Pinon_salto();
								break;
							case 'C':
								bicicleta.Pinon_caida();
								break;
							default: 
								cout << "\nIntroduzca una operacion valida\n";
						}
						
						break;
					
					default: 
						cout << "\nIntroduzca una componente valida\n";
				}
			}
		}while(instrucciones != '#');
		
		cout << "\nTras aplicar todas la operaciones las posicion de la estrella y el vector son " << bicicleta.Estrella() << " y " << bicicleta.Pinon() << " respectivamente.\n";
		
		system("pause");
	}
			


		
		
		
		
