#include "receta.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;

receta::receta(){
    list<pair<string,unsigned int>> nuevo;
    code = "";
    plato = 0;
    nombre = "";
    ings=nuevo; //No estoy seguro
    calorias = 0, Hc = 0, grasas = 0, proteinas = 0, fibra = 0;          
}

receta::receta(string cod, unsigned int plat, string nombr, list<pair<string,unsigned int> > ing, float cal, float hc, float gras, float prot, float fibr){
    code = cod;
    plato = plat;
    nombre = nombr;
    ings = ing;
    calorias = cal, Hc = hc, grasas = gras, proteinas = prot, fibra = fibr;
}

string receta::getCode() const{
    return code;
}

unsigned int receta::getPlato() const{
    return plato;
}

string receta::getNombre() const{
    return nombre;
}

list<pair<string,unsigned int>> receta::getIngredientes() const{
    return ings;
}

float receta::getCalorias() const{
    return calorias;
}

float receta::getHc() const{
    return Hc;
}

float receta::getProteinas() const{
    return proteinas;
}

float receta::getGrasas() const{
    return grasas;
}

float receta::getFibra() const{
    return fibra;
}

void receta::setCode(string cod){
    code = cod;
}

void receta::setPlato(unsigned int plat){
    plato=plat;
}

void receta::setNombre(string nombr){
    this->nombre = nombr;
}

void receta::setIngredientes(list<pair<string,unsigned int> > ing){
    ings = ing;
}

void receta::setCalorias(float cal){
    calorias = cal;
}

void receta::setHc(float hc){
    Hc=hc;
}

void receta::setProteinas(float prot){
    proteinas=prot;
}

void receta::setGrasas(float gras){
    grasas = gras;
}

void receta::setFibra(float fibr){
    fibra = fibr;
}

receta & receta::operator =(const receta& original){
    code = original.code;
    plato = original.plato;
    nombre = original.nombre;
    ings = original.ings;
    calorias = original.calorias;
    Hc = original.Hc;
    proteinas = original.proteinas;
    grasas = original.grasas;
    fibra = original.fibra;
    
    return *this;
}

receta::iterator & receta::iterator::operator ++(){
    ++it;
    return *this;
}

receta::iterator & receta::iterator::operator --(){
    --it;
    return *this;
}

receta::const_iterator & receta::const_iterator::operator ++(){
    ++it;
    return *this;
}

receta::const_iterator & receta::const_iterator::operator --(){
    --it;
    return *this;
}



std::ostream & operator<<(std::ostream &os, const receta &r){
    list<pair<string,unsigned int>>::const_iterator salida;
    os << r.code << ";" << r.plato << ";" << r.nombre;
    
    for(salida = r.ings.begin(); salida != r.ings.end(); salida++)
        os << ";" << (*salida).first << " " << (*salida).second;
    
    return os;
        
}

std::istream& operator>>(istream& is, receta& entrada){
    list<pair<string, unsigned int>> lista_auxiliar;
    pair<string, unsigned int> insertar;
    string cadena_auxiliar;
    string cadena_entrada;
    vector<int> puntos_coma;
    vector<int> espacios;
    string delim=";";
    int pos_ini=0;
    int tamanio;
    
    getline(is,cadena_entrada);
    
    if(is && cadena_entrada.size() != 0){
        
        if(cadena_entrada.at(cadena_entrada.size()-1) == ' ')
            cadena_entrada.pop_back();
        
        while(cadena_entrada.find(delim,pos_ini)!= string::npos){
            pos_ini=cadena_entrada.find(delim,pos_ini);
            puntos_coma.push_back(pos_ini);
            pos_ini++;
        }
        
        pos_ini=0;
        
        for(int i=0; i <= (tamanio = puntos_coma.size()); i++){
            if(i==0)
                entrada.setCode(cadena_entrada.substr(0,puntos_coma[i]));
         	
            if(i==1)
                entrada.setPlato(stoi(cadena_entrada.substr(puntos_coma[i-1]+1,puntos_coma[i]-puntos_coma[i]-1),nullptr));
            
            if(i==2)
                entrada.setNombre(cadena_entrada.substr(puntos_coma[i-1]+1,puntos_coma[i]-puntos_coma[i-1]-1));
            
            if(i>2){
                if(i==(tamanio = puntos_coma.size()))
                    cadena_auxiliar=cadena_entrada.substr(puntos_coma[i-1]+1);
                else                    
                    cadena_auxiliar=cadena_entrada.substr(puntos_coma[i-1]+1,puntos_coma[i]-puntos_coma[i-1]-1);
                
                while(cadena_auxiliar.find(" ",pos_ini) != string::npos){
                    pos_ini=cadena_auxiliar.find(" ",pos_ini);
                    espacios.push_back(pos_ini);
                    pos_ini++;
                }
                
                insertar.first=cadena_auxiliar.substr(0,espacios[(espacios.size()-1)]);                
                insertar.second=stoi(cadena_auxiliar.substr(espacios[espacios.size()-1]+1),nullptr);
                lista_auxiliar.push_back(insertar);
                
                pos_ini=0;
                espacios.clear();                
            }
        }
        entrada.setIngredientes(lista_auxiliar);
        return is;
        
        
        
    }
}
