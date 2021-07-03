/* 
 * File:   receta.h
 * Author: mahotoca
 *
 * Created on 7 de noviembre de 2019, 20:28
 */

#ifndef RECETA_H
#define RECETA_H

#include <string>
#include <list>
#include <iostream>
#include "ingredientes.h"
using namespace std;

class receta{
private:
    string code;
    unsigned int plato;
    string nombre;
    list<pair<string,unsigned int>> ings;
    float calorias,Hc,grasas,proteinas,fibra;
    
public:
    /**
     @brief Constructor por defecto
     */
    receta();
    /**
     @brief Constructor con parámetros
     @param cod: Código de la receta
     @param plat:Número de plato de la receta
     @param nombr: Nombre de la receta
     @param ing: Los ingredientes que componen la receta y su cantidad 
     @param cal: Calorías de la receta 
     @param hc: hidratos de carbono de la receta
     @param gras: grasas que contiene la receta
     @param prot: proteínas que contiene la receta
     @param fibra :  cantidad de fibra que contiene la receta
     */
    receta(string cod, unsigned int plat, string nombr, list<pair<string,unsigned int>> ing, float cal, float hc, float gras, float prot, float fibr);
    /**
     * @brief Devuelve el numero de ingredientes de la receta
     * @return numero de ingredientes de la receta
     */
    int ningredientes(){return ings.size();};
    /**
     @brief Devuelve el código de la receta
     */    
    string getCode() const;
    /**
     @brief Devuelve el número del plato
     */
    unsigned int getPlato() const;
    /**
     @brief Devuelve el nombre de la receta
     */
    string getNombre() const;
    /**
     @brief Devuelve la lista de ingredientes de la receta con su respectiva cantidad
     */
    list<pair<string,unsigned int>> getIngredientes() const;
    
    /**
    * @brief Devuelve las calorias de la receta
    */
    float getCalorias() const;
    /**
    * @brief Devuelve los carbohidratos de la receta
    */
    float getHc() const;
    /**
    * @brief Devuelve las proteinas de la receta
    */
    float getProteinas() const;
    /**
    * @brief Devuelve las grasas de la receta
    */
    float getGrasas() const;
    /**
    * @brief Devuelve la fibras de la receta
    */
    float getFibra() const;
    /**
     @brief Establece el código de la receta a la que se llama
     @param cod: El código de la receta
     */
    void setCode(string code);
    /**
     @brief Establece número de plato de la receta a la que se llama
     @param plat: El número de plato de la receta
     */
    void setPlato(unsigned int plat);
    /**
     @brief Establece el nómbre de la receta a la que se llama
     @param nombr
     */
    void setNombre(string nombr);
    /**
     @brief Establece la lista de ingrediente de la receta a la que se llama
     @param ing: lista de ingredientes de la receta
     */
    void setIngredientes(list<pair<string,unsigned int>> ing);
    /**
    * @brief Establece las calorias totales de la receta que llama a la funcion
    * @param cal: numero de calorias totales de la receta
    */
    void setCalorias(float cal);
    /**
    * @brief Establece los carbohidratos totales de la receta a la  que llama a la funcion
    * @param hc: numero de carbohidratos de la receta
    */
    void setHc(float hc);
    /**
    * @brief Establece las proteinas totales de la receta a la que llama a la funcion
    * @param prot: numero de proteinas de la receta
    */
    void setProteinas(float prot);
    /**
    * @brief Establece las grasas totales de la receta a la que llama a la funcion
    * @param gras: numero de grasas de la receta	
    */
    void setGrasas(float gras);
    /**
    * @brief Establece la fibra totales de la receta a la que llama a la funcion
    * @param fibr: numero de fibra de la receta
    */
    void setFibra(float fibr);
    /**
     @brief Sobrecarga del operador de asignación
     @param original: la receta que se quiere copiar*/
    receta & operator=(const receta & original);
    
    friend std::ostream & operator<<(std::ostream & os, const receta & i);	//Función amiga
    friend std::istream & operator>>(std::istream & is, receta & i);
    
    class iterator{
    private:
        list<pair<string,unsigned int>>::iterator it;

    public:
        /**
        * @brief Constructor sin parámetros
        */
        inline iterator(){};	//
        /**
        * @brief Constructor de copia
        * @param i:se copia en el iterador que llama a la función el iterador i
        */
        inline iterator(const iterator & i){it = i.it;};		//
        /**
        * @brief Se apunta el iterador que invoca la función a la posición siguiente a la que apunta en el momento de la llamada
        * @return iterador que apunta a la siguiente posicion que se pide
        */
        iterator & operator++();		//
        /**
        * @brief Se apunta el iterador que invoca la función a la posición anterior a la que se apunta en el momento de la llamada
        * @return iterador que apunta a la posición anterior que el original
        */
        iterator & operator--();		//
        /** 
        * @brief Se sobrecargar el operador de comparación para comprobar si dos iteradores son iguales
        * @param i: iterador con el que se quiere comparar
        * @return true si son iguales, false si no lo son
        */
        bool operator==(const iterator & i){return it==i.it;};	//
        /**
        * @brief sobrecarga del operador distinto para comprobar si dos iteradores son distintos
        * @param i:iterador con el que se comparará
        * @return true si son distintos, false si no lo son
        */
        bool operator!=(const iterator & i){return it!=i.it;};	//
        /**
        * @brief Sobrecarga del operador *, se devuelve el contenido a donde apunta el iterador invocante de la llamada
        * @return se devuelve la lista de ingredientes contenida en la posicion a la que se llama
        */
        pair<string, unsigned int> & operator*() const{return *it;};	//
        friend class receta;
    };

    class const_iterator{
    private:
        list<pair<string,unsigned int>>::const_iterator it;

    public:
       /**
        * @brief Constructor sin parámetros
        */
        inline const_iterator(){};  
        /**
        * @brief Constructor de copia
        * @param i:se copia en el iterador que llama a la función el iterador i
        */
        inline const_iterator(const const_iterator & i){it=i.it;};  
        /**
        * @brief Sobrecarga del operador *, se devuelve el contenido a donde apunta el iterador invocante de la llamada
        * @return se devuelve el ingrediente contenido en la posicion a la que se llama
        */
        pair<string, unsigned int> operator* () const {return *it;};		   
        /**
        * @brief Se apunta el iterador que invoca la función a la posición siguiente a la que apunta en el momento de la llamada
        * @return iterador que apunta a la siguiente posicion que se pide
        */
        const_iterator & operator++();		   
        /**
        * @brief Se apunta el iterador que invoca la función a la posición anterior a la que se apunta en el momento de la llamada
        * @return iterador que apunta a la posición anterior que el original
        */
        const_iterator & operator--();		   
        /**
        * @brief sobrecarga del operador distinto para comprobar si dos iteradores son distintos
        * @param i:iterador con el que se comparará
        * @return true si son distintos, false si no lo son
        */
        bool operator==(const const_iterator & i){return it==i.it;}; 
        /**
        * @brief Sobrecarga del operador *, se devuelve el contenido a donde apunta el iterador invocante de la llamada
        * @return se devuelve la lista de ingredientes contenida en la posicion a la que se llama
        */
        bool operator!= (const const_iterator & i){return it!=i.it;};
        friend class receta; 
    };
    
    iterator begin(){       iterator i;
                            i.it = ings.begin();
                            return i;};
    
    iterator end(){         iterator i;
                            i.it = ings.end();
                            return i;};
                                
    const_iterator begin() const{   const_iterator i;
                                    i.it=ings.begin();
                                    return i;};

    const_iterator end() const{ const_iterator i;
                                    i.it=ings.end();
                                    return i;};
    
};

/**
 * @brief Devuelve la información almacenada en una receta r por medio del flujo de salida os
 * @param os: flujo de salida
 * @param r: receta a devolver
 */
std::ostream & operator<<(std::ostream & os, const receta & r);
/**
 * @brief Toma la información por medio del flujo de entrada is para almacenarla en una receta r
 * @param is: flujo de entrada
 * @param r: receta a almacenar
 */
std::istream & operator>>(std::istream & is, receta & r);


#endif /* RECETA_H */