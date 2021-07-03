


#ifndef INGREDIENTE_H
#define INGREDIENTE_H

#include <iostream>
#include <string>

using namespace std;

class ingrediente{
    private:
        string nombre;		//nombre del ingredeinte
        double calorias;	//calorías del ingrediente por cada 100 gramos
        double Hc;		//Carbohidratos del ingredeinte por cada 100 gramos
        double proteinas;	//Proteinas del ingrediente por cada 100 gramos
        double grasas;		//Grasas del ingrediente por cada 100 gramos
        double fibra;		//Fibra del ingrediente por cada 100 gramos
        string tipo;		//A que grupo de alimentos pertenece el ingrediente
        
    public:
	/**
	* @brief Constructor por defecto
	*/
        ingrediente();
	/** 
	* @brief Constructor con parámetros
	* @param nombr: nombre que se le da al nuevo elemento de la clase ingrediente
	* @param cal: calorias por cada 100 gramos que se le dan al ingrediente
	* @param hc: carbohidratos por cada 100 gramos que se le dan al ingrediente
	* @param prot: proteinas por cada 100 gramos que se le dan al ingrediente
	* @param gras: grasas por cada 100 gramos que se le dan al ingrediente
	* @param fibr: fibra por cada 100 gramos que se le dan al ingrediente
	* @param tip: tipo de alimentos al que pertenecerá el ingrediente 
	*/
        ingrediente(string nombr, double cal, double hc, double prot, double gras, double fibr, string tip);
	/**
	* @brief Devuelve el nombre del ingrediente que llama a la función
	*/
        string getNombre() const;
	/**
	* @brief Devuelve las calorias por cada 100 gramos del ingrediente que llama a la función
	*/
        double getCalorias() const;
	/**
	* @brief Devuelve los carbohidratos por cada 100 gramos del ingrediente que llama a la función
	*/
        double getHc() const;
	/**
	* @brief Devuelve las proteinas por cada 100 gramos del ingrediente que llama a la función
	*/
        double getProteinas() const;
	/**
	* @brief Devuelve las grasas por cada 100 gramos del ingrediente que llama a la funcion
	*/
        double getGrasas() const;
	/**
	* @brief Devuelve la fibras por cada 100 gramos del ingrediente que llama a la funcion
	*/
        double getFibra() const;
	/**
	* @brief Devuelve el tipo de alimento del ingrediente que llama a la función
	*/
        string getTipo() const;
	/**
	* @brief Establece el nombre del ingrediente que llama a la función, siendo el nuevo nombre nombr
	* @param nombr: nuevo nombre del ingrediente
	*/
        void setNombre(string nombr);
	/**
	* @brief Establece las calorias por cada 100 gramos del ingrediente que llama a la funcion
	* @param cal: numero de calorias del ingrediente por cada 100 gramos
	*/
        void setCalorias(double cal);
	/**
	* @brief Establece los carbohidratos por cada 100 gramos del ingrediente que llama a la funcion
	* @param hc: numero de carbohidratos del ingrediente por cada 100 gramos
	*/
        void setHc(double hc);
	/**
	* @brief Establece las proteinas por cada 100 gramos del ingrediente que llama a la funcion
	* @param prot: numero de proteinas del ingrediente por cada 100 gramos
	*/
        void setProteinas(double prot);
	/**
	* @brief Establece las grasas por cada 100 gramos del ingrediente que llama a la funcion
	* @param gras: numero de grasas del ingrediente por cada 100 gramos	
	*/
        void setGrasas(double gras);
	/**
	* @brief Establece la fibra por cada 100 gramos del ingrediente que llama a la funcion
	* @param fibr: numero de fibra del ingrediente por cada 100 gramos
	*/
        void setFibra(double fibr);
	/**
	* @brief Establece al grupo de alimentos que pertenecerá el alimento
	* @tip: tipo de alimento
	*/
        void setTipo(string tip);
	/**
	* @brief Sobrecargar el operador de asignacion para la clase
	* @param original: el ingrediente que se quiere copiar
	*/
	ingrediente & operator=(const ingrediente & original);
        friend std::ostream & operator<<(std::ostream & os, const ingrediente & i);	//Función amiga
        friend std::istream & operator>>(std::istream & is, ingrediente & i);		//Función amiga
        
        
        
        
        
};

/**
* @brief Devuelve la información almacenada en un ingrediente i por medio del flujo de salida os
* @param os:flujo de salida
* @param i:ingrediente el cuya información se quiere guardar en archivo o mostrar por pantalla
*/
std::ostream & operator<<(std::ostream & os, const ingrediente & i);
/**
* @brief Toma la información por medio del flujo de entrada is y se almacena en el ingrediente i
* @param is: flujo de entrada
* @param i: ingrediente donde se almacenará la información
*/
std::istream & operator>>(std::istream & is, ingrediente & i);




#endif

