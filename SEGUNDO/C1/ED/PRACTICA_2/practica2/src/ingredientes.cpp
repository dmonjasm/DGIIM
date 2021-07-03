#include "ingredientes.h"
#include <iostream>
#include <string>

using namespace std;

ingredientes::ingredientes(){
}
	
pair<bool,int> ingredientes::Buscar_nombre(const ingrediente & insertar){
	int inf=0;
	int sup=datos.size()-1;
	int mitad=0;
	pair<bool,int> salida(false,0);
	
	while(inf <= sup && !salida.first){
		mitad=(inf+sup)/2;
		
		if(datos[mitad].getNombre()==insertar.getNombre()&&datos[mitad].getTipo()==insertar.getTipo()){
			salida.first=true;
			salida.second=mitad;
			
		}
		
		else{
			if(datos[mitad].getNombre()<insertar.getNombre())
				inf=mitad+1;
			else
				sup=mitad-1;

			salida.second=inf;
		}

		
	}

	return salida;
}

pair <bool,int> ingredientes::Buscar_tipo(const ingrediente & insertar){
	int ini = 0;
        int final = indice.size() - 1;
        int mitad = (ini + final)/2;
        pair<bool,int> retorno;
        
        while(ini <= final){
            mitad = (ini + final)/2;
            if(datos[indice[mitad]].getNombre() == insertar.getNombre() && datos[indice[mitad]].getTipo() == insertar.getTipo()){
                retorno.first = true;
                retorno.second = mitad;
            }
            else{
                if(datos[indice[mitad]].getTipo() < insertar.getTipo()){
                    ini = mitad + 1;
                }
                else{
                    if(datos[indice[mitad]].getTipo() > insertar.getTipo()){
                        final = mitad - 1;
                    }
                    else{
                        if(datos[indice[mitad]].getNombre() < insertar.getNombre()){
                            ini = mitad + 1;
                        }
                        else{
                            final = mitad - 1;
                        }
                    }
                }
                retorno.first = false;
                retorno.second = ini;
                
            }
        }

        return retorno;
}

void ingredientes::Insertar(const ingrediente & insertado){
	pair<bool,int> posicion_datos;
	pair<bool,int> posicion_indice;

	if(datos.size()==0&&indice.size()==0){
		datos.Insertar(insertado,0);
		indice.Insertar(0,0);
	}

	else{
		posicion_datos=Buscar_nombre(insertado);

		if(!posicion_datos.first){
			datos.Insertar(insertado,posicion_datos.second);

			for(int i=0 ; i < indice.size(); i++)
				if(indice[i] >= posicion_datos.second)
					indice[i]++;

			posicion_indice=Buscar_tipo(insertado);
			indice.Insertar(posicion_datos.second,posicion_indice.second);
		}	
	}	
}

void ingredientes::borrar(const string & nombre){
	bool encontrado=false;
		
	for(int i=0; i < datos.size() && !encontrado; i++){
		if(datos[i].getNombre()==nombre){
			datos.Borrar(i);
			for (int j=0; j < indice.size();j++){
				if(indice[j]>i)
					indice[j]--;
				else if(indice[j]==i)
					indice.Borrar(j);
			}
			encontrado=true;
		}
	}

	if(!encontrado)
		cerr << "ERROR: el nombre introducido no es encuentra en datos." << endl;	
}


void ingredientes::setIngrediente(int pos, const ingrediente & nuevo){
	datos.Borrar(pos);
	this->Insertar(nuevo);
}

ingredientes ingredientes::getIngredienteTipo(const string & tipo){
	ingredientes resultado;
	string comparacion;

	for(int i=0; i < this->size(); i++){

		comparacion=datos[i].getTipo();
		comparacion.pop_back();
		
		if(comparacion==tipo){
			resultado.Insertar(datos[i]);
		}
	}

	
	return resultado;
}

std::ostream& operator<<(std::ostream &os,const ingredientes & i){
	int tamano=i.size();
	for(int j=0; j < tamano;j++)
		os << i.datos[j];
	return os;
}

std::istream & operator>>(std::istream &is, ingredientes & i){
	string linea;
	getline(is,linea);

	ingrediente aux;

	while(!is.eof()){
		is >> aux;
		if(!is.eof())
			i.Insertar(aux);
	}
	
	return is;
}

void ingredientes::ImprimirPorTipo(std::ostream &os){
	for(int i=0; i < indice.size(); i++)
		os << datos[indice[i]];
}

ingrediente ingredientes::get(const string & n){
	bool encontrado=false;
	ingrediente resultado;

	for(int i=0; i < datos.size() && !encontrado; i++){
		if(datos[i].getNombre()==n){
			encontrado=true;
			resultado=datos[i];
		}
	}
	
	return resultado;
}
	
VD<string> ingredientes::getTipos(){
	VD<string> tipos;
	string fijado;

	int contador=0;

	tipos.Insertar(datos[indice[0]].getTipo(),contador);

	for(int i=0; i < indice.size(); i++){
		if(tipos[contador]!=datos[indice[i]].getTipo()){
			contador++;
			tipos.Insertar(datos[indice[i]].getTipo(),contador);
		}
	}
	
	return tipos;
}

ingredientes ingredientes::operator=(const ingredientes & original){
	
	for(int i=0; i < original.size(); i++)
		datos[i]=original[i];

	return *this;
}




			
		






	
			



		

	
	
	



		
	
			

			


				
				
					





