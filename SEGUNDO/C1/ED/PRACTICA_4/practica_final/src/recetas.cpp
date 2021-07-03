
#include "recetas.h"
#include "receta.h"
#include <string>
#include <map>

receta recetas::operator [](const string& codigo){
    map<string,receta>::iterator i;
    receta error;
    i=datos.find(codigo);
    
    if(i == datos.end()){
        error.setNombre("Undefined");
        return error; 
    }
    
    else
        return (*i).second;
}

void recetas::borrar(const string& codigo){
    map<string,receta>::iterator i;
 
    i=datos.find(codigo);
    
    if(i != datos.end())
        datos.erase(i);
}

void recetas::insertar(const pair<string,receta> & insertar){
    datos.insert(insertar);
}

std::istream & operator>>(std::istream & is,recetas & i){
    receta aux;
    pair<string,receta> auxiliar;
    
    if(is){
        
        while(!is.eof()){
            if(is){
                is >> aux;
                auxiliar.second= aux;
                auxiliar.first=aux.getCode();
                i.insertar(auxiliar);
            }
            
        }
    }
    
    return is;
}

std::ostream & operator<<(std::ostream & os, const recetas & i){
    recetas::const_iterator it;
    
    for(it = i.begin(); it != i.end(); ++it)
        os << *it << endl;
    
    return os;
}
