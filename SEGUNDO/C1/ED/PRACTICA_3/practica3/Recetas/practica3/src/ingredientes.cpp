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
		
		if(datos.at(mitad).getNombre()==insertar.getNombre()&&datos.at(mitad).getTipo()==insertar.getTipo()){
			salida.first=true;
			salida.second=mitad;
			
		}
		
		else{
			if(datos.at(mitad).getNombre()<insertar.getNombre())
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
        int fin = indice.size() - 1;
        int mitad = 0;
        pair<bool,int> retorno(false,0);

        while(ini <= fin){
            mitad = (ini + fin)/2;
            if(datos.at(indice.at(mitad)).getNombre() == insertar.getNombre() && datos.at(indice.at(mitad)).getTipo() == insertar.getTipo()){
                retorno.first = true;
                retorno.second = mitad;
            }
            else{
                if(datos.at(indice.at(mitad)).getTipo() < insertar.getTipo()){
                    ini = mitad + 1;
                }
                else{
                    if(datos.at(indice.at(mitad)).getTipo() > insertar.getTipo()){
                        fin = mitad - 1;
                    }
                    else{
                        if(datos.at(indice.at(mitad)).getNombre() < insertar.getNombre()){
                            ini = mitad + 1;
                        }
                        else{
                            fin = mitad - 1;
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
	int tamanio;

	if(datos.size()==0&&indice.size()==0){
		datos.insert(datos.begin(),insertado);
		indice.insert(indice.begin(),0);
	}

	else{
		posicion_datos=Buscar_nombre(insertado);
		vector<ingrediente>::iterator insertar=datos.begin();
		
		for(int i=0; i < posicion_datos.second; i++)
			++insertar;

		datos.insert(insertar,insertado);
		
		for(int i=0; i < (tamanio = indice.size()); i++){
			if(indice.at(i)>=posicion_datos.second)
				indice.at(i)++;
		}
		
		posicion_indice=Buscar_tipo(insertado);

		vector<int>::iterator insertar_indice=indice.begin();
		


		for(int i=0; i < posicion_indice.second; i++)
			++insertar_indice;

		
		indice.insert(insertar_indice, posicion_datos.second);


			
	}	
}

void ingredientes::borrar(const string & nombre){
	bool encontrado=false;
	vector<ingrediente>::iterator dato_eliminar=datos.begin();
	vector<int>::iterator indice_eliminar=indice.begin();
	int tamanio;
		
	for(int i=0; i < (tamanio = datos.size()) && !encontrado; i++){
		if(datos.at(i).getNombre()==nombre){
			for(int j=0; j < i; j++)
				++dato_eliminar;

			datos.erase(dato_eliminar);

			for (int j=0; j < (tamanio = indice.size());j++){
				if(indice.at(j)==i){
					for(int k=0; k < j; k++)
					++indice_eliminar;
				}
			}
			
			for (int j=0; j < (tamanio = indice.size()); j++){
				if(indice.at(j)>i)
					indice.at(j)--;			
			}

			indice.erase(indice_eliminar);
			encontrado=true;
		}
	}

	if(!encontrado)
		cerr << "ERROR: el nombre introducido no es encuentra en datos." << endl;	
}


void ingredientes::setIngrediente(int pos, const ingrediente & nuevo){
	string nombre=datos.at(pos).getNombre();
	this->borrar(nombre);
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
	int tamanio;
	for(int i=0; i < (tamanio = indice.size()); i++)
		os << datos[indice[i]];
}

ingrediente ingredientes::get(const string & n){
	bool encontrado=false;
	ingrediente resultado;
	int tamanio;

	for(int i=0; i < (tamanio = datos.size()) && !encontrado; i++){
		if(datos[i].getNombre()==n){
			encontrado=true;
			resultado=datos[i];
		}
	}
	
	return resultado;
}
	
vector<string> ingredientes::getTipos(){
	vector<string> tipos;
	int tamanio;
	int contador=0;

	tipos.insert(tipos.begin(),datos.at(indice.at(0)).getTipo());

	for(int i=0; i < (tamanio = indice.size()); i++){
		cout << "FUNCIONA " << i << endl;
		if(tipos.at(contador)!=datos.at(indice.at(i)).getTipo()){
			tipos.push_back(datos.at(indice.at(i)).getTipo());
			contador++;
			cout << "CONTADOR " << contador << endl;
		}
	}
	
	return tipos;
}

ingredientes ingredientes::operator=(const ingredientes & original){
	
	for(int i=0; i < original.size(); i++){
		datos.at(i)=original[i];
		indice.at(i)=original.indice.at(i);
	}

	return *this;
}

ingredientes::iterator & ingredientes::iterator::operator++(){
		++it;
		return *this;
	
}

ingredientes::iterator & ingredientes::iterator::operator--(){
		--it;
		return *this;
		
}

bool::ingredientes::iterator::operator ==(const iterator & i){
	return it==i.it;
}

bool::ingredientes::iterator::operator !=(const iterator & i){
	return it!=i.it;
}

ingredientes::const_iterator & ingredientes::const_iterator::operator++(){
		++it;
		return *this;
}

ingredientes::const_iterator & ingredientes::const_iterator::operator--(){
		--it;
		return *this;
}

bool::ingredientes::const_iterator::operator ==(const const_iterator & i){
	return it==i.it;
}

bool::ingredientes::const_iterator::operator !=(const const_iterator & i){
	return it!=i.it;
}





			
		






	
			



		

	
	
	



		
	
			

			


				
				
					





