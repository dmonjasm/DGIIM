
#include "ingrediente.h"
#include <iostream>
#include <string>


using namespace std;

ingrediente::ingrediente(){
    nombre = "";
    calorias = 0;
    Hc = 0;
    proteinas = 0;
    grasas = 0;
    fibra = 0;
    tipo = "";

}

ingrediente::ingrediente(string nombr, double cal, double hc, double prot, double gras, double fibr, string tip){
    nombre = nombr;
    calorias = cal;
    Hc = hc;
    proteinas = prot;
    grasas = gras;
    fibra = fibr;
    tipo = tip;
}

string ingrediente::getNombre() const{
    return nombre;
}

double ingrediente::getCalorias() const{
    return calorias;
}

double ingrediente::getHc() const{
    return Hc;
}

double ingrediente::getProteinas () const{
    return proteinas;
}

double ingrediente::getGrasas() const{
    return grasas;
}

double ingrediente::getFibra() const{
    return fibra;
}

string ingrediente::getTipo() const{
    return tipo;
}

void ingrediente::setNombre(string nombr){
    nombre = nombr;
}

void ingrediente::setCalorias(double cal){
    calorias = cal;
}

void ingrediente::setHc(double hc){
    Hc= hc;
}

void ingrediente::setProteinas(double prot){
    proteinas = prot;
}

void ingrediente::setGrasas(double gras){
    grasas = gras;
}

void ingrediente::setFibra(double fibr){
    fibra = fibr;
}

void ingrediente::setTipo(string tip){
    tipo = tip;
}


std::ostream & operator<<(std::ostream &os, const ingrediente & i){
    os << i.getNombre() << ";" << i.getCalorias() << ";" << i.getHc() << ";" << i.getProteinas() << ";" << i.getGrasas() << ";" <<  i.getFibra() << ";" << i.getTipo() << endl;
    
    return os;
}

std::istream & operator>>(std::istream &is, ingrediente & entrada){
    string cadena;
    string delim=";";
    int punt_com[6];
    int pos_ini=0;
    int contador=0;
    
    getline(is,cadena);
    if(is){
    
        for(int i=0; i < 6; i++){
            punt_com[i]=0;
        }
    
    
    
        while(cadena.find(delim,pos_ini)!=std::string::npos){
            pos_ini=cadena.find(delim,pos_ini);
            punt_com[contador]=pos_ini;
            contador++;
            pos_ini++;
        }
    
        for(int i=0; i <= 6; i++){
            if(i==0)
                entrada.nombre=cadena.substr(0,punt_com[i]);
            if(i==1)
                entrada.calorias=atof(cadena.substr(punt_com[i-1]+1,punt_com[i]-punt_com[i-1]-1).c_str());
            if(i==2)
                entrada.Hc=atof(cadena.substr(punt_com[i-1]+1,punt_com[i]-punt_com[i-1]-1).c_str());
            if(i==3)
                entrada.proteinas=atof(cadena.substr(punt_com[i-1]+1,punt_com[i]-punt_com[i-1]-1).c_str());
            if(i==4)
                entrada.grasas=atof(cadena.substr(punt_com[i-1]+1,punt_com[i]-punt_com[i-1]-1).c_str());
            if(i==5)
                entrada.fibra=atof(cadena.substr(punt_com[i-1]+1,punt_com[i]-punt_com[i-1]-1).c_str());
            if(i==6)
                entrada.tipo=cadena.substr(punt_com[i-1]+1); 
        }
    }

	return is;
    
}

ingrediente & ingrediente::operator=(const ingrediente & original){
	nombre=original.nombre;
	calorias=original.calorias;
	Hc=original.Hc;
	proteinas=original.proteinas;
	grasas=original.grasas;
	fibra=original.fibra;
	tipo=original.tipo;
        
        return *this;
}


