
#ifndef RECETAS_H
#define RECETAS_H

#include <string>
#include <map>
#include "receta.h"

using namespace std;

class recetas{
private:
    map<string,receta> datos;
   
public:
    recetas(){ };
    recetas(const recetas & copia){
        datos=copia.datos;
    };
    /**
    * @brief Devuelve el tamaño del map
    * @return numero de elemntos del map
    */
    int size(){return datos.size();};
    
    receta operator[](const string & codigo);
    
    void borrar(const string & codigo);
    
    void insertar(const pair<string, receta> & insertar);
        
    class iterator{
    private:
        map<string, receta>::iterator it;
    public:
        /**
         * @brief Constructor sin parámetros
         */
        iterator(){};
        /**
         * @brief Constructor de copia con parámetros
         * @param i: iterador el cual se copiará
         */
        iterator(const iterator & i){it==i.it;};
        /**
         * @brief Sobrecarga del operador de incremento, se incrementa la posición a la que apunta el iterador
         * @return Se devuelve una referencia a iterator
         */
        iterator & operator++(){++it;
                                return *this;};
        /**
         * @brief Sobrecarga del operador de decremento, se decrementa la posición a la que se apunta el iterador
         * @return Se devuelve una referencia a iterator
         */                        
        iterator & operator--(){--it;
                                return *this;};
        /**
         * @brief Sobrecarga del operator ==, devuelve si dos iteradores son iguales
         * @param i: iterador con el que se compara
         * @return true si son iguales, false en caso contrario
         */                        
        bool operator==(const iterator & i){return i.it==it;};
        /**
         * @brief Sobrecarga del operator !=, devuelve si dos iteradores son distintos
         * @param i: iterador con el que se va a comparar
         * @return true si son distintos, false en caso contrario
         */
        bool operator!=(const iterator & i){return i.it!=it;};
        /**
         * @brief Sobrecarga del operador *, se devuelve el pair al que apunta el iterador
         * @return Se retorna el pair que apunta el iterador
         */
        receta & operator*(){return (*it).second;};
        friend class recetas;    
    };
    
    
    class const_iterator{
    private:
        map<string, receta>::const_iterator it;
        
    public:
        /**
         * @brief Constructor sin parámetros
         */
        const_iterator(){};
        /**
         * @brief Constructor de copia
         * @param i: const_iterator que se copiará
         */
        const_iterator(const const_iterator & i){it==i.it;};
        /**
         * @brief Sobrecarga del operador de incremento, se incrementa la posición a la que apunta el iterador
         * @return Se devuelve una referencia a iterator
         */
        const_iterator & operator++(){++it;
                                       return *this;}
        /**
         * @brief Sobrecarga del operador de decremento, se decrementa la posición a la que se apunta el const_iterador
         * @return Se devuelve una referencia a const_iterator
         */ 
        const_iterator & operator--(){--it; 
                                        return *this;};
        /**
         * @brief Sobrecarga del operator !=, devuelve si dos const_iteradores son iguales
         * @param i: const_iterador con el que se va a comparar
         * @return true si son iguales, false en caso contrario
         */                               
        bool operator==(const const_iterator & i){return it==i.it;};
        /**
         * @brief Sobrecarga del operator !=, devuelve si dos const_iteradores son distintos
         * @param i: const_iterador con el que se va a comparar
         * @return true si son distintos, false en caso contrario
         */
        bool operator!=(const const_iterator & i){return it!=i.it;};
        /**
         * @brief Sobrecarga del operador *, se devuelve el pair al que apunta el const_iterador
         * @return Se retorna el pair que apunta el const_iterador
         */
        receta operator*() const{return (*it).second;};
        friend class recetas;
    };
    
    /**
     * @brief Se devuelve un iterator a la primera posicion del contenedor
     * @return iterator apuntando a la primera posición del contenedor
     */
    iterator begin(){
                    iterator i;
                    i.it=datos.begin();
                    return i;
    }
    /**
     * @brief Se devuelve un iterator a la última posicion del contenedor
     * @return iterator apuntando a la última posición del contenedor
     */
    iterator end(){
                iterator i;
                i.it=datos.end();
                return i;
    }
    
    /**
     * @brief Se devuelve un const_iterator a la primera posicion del contenedor
     * @return const_iterator apuntando a la primera posición del contenedor
     */
    const_iterator begin() const{
                    const_iterator i;
                    i.it=datos.begin();
                    return i;
    }
    /**
     * @brief Se devuelve un const_iterator a la última posicion del contenedor
     * @return const_iterator apuntando a la última posición del contenedor
     */
    const_iterator end() const{
                const_iterator i;
                i.it=datos.end();
                return i;
    }
    
    friend std::ostream & operator<<(std::ostream & os, const recetas & i);
    friend std::istream & operator >>(std::istream & is, const recetas & i);
};

std::ostream & operator<<(std::ostream & os, const recetas & i);
std::istream & operator >>(std::istream & is, recetas & i);

#endif
