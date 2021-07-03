#ifndef INSTRUCCIONES_H
#define INSTRUCCIONES_H

#include "arbolbinario.h"
#include "acciones.h"
#include "ingredientes.h"
#include <string>
#include <list>
#include <stack>

class instrucciones{
    private:
        ArbolBinario<string> datos;
        acciones acc;
        vector<string> nombre_ingredientes;

    public:
        /**
         * @brief Constructor por defecto sin parámetros
        */
        instrucciones(){};
        /**
         * @brief Constructor de copia
         * @param copia, objeto de tipo ingredientes a copiar
        */
        instrucciones(const instrucciones & copia){
            datos=copia.datos;
            acc=copia.acc;
        };
        /**
         * @brief Se almacena en acc las acciones permitidas
         * @param set, lista con todas las acciones que permite el programa
        */
        void setAcciones(const acciones & set){acc=set;};
        /**
         * @brief Se almacena en nombre_ingredientes todos los ingredientes permitidos
         * @param ingredientes_receta, vector de strings con todos los nombres de los ingredientes permitidos
        */
        void setIngredientes(const vector<string> & ingredientes_receta);
        /**
         * @brief Muesta los pasos de una receta indicada cuyas instrucciones son guardadadas en un archivo de tipo instrucciones
         * @param instr El conjunto de instrucciones de la receta
         * @param acc El conjunto de acciones de la receta
         * @param ingr El nombre de los ingredientes de la receta 
         */
        void mostarPasos(instrucciones instr, acciones acc, vector<string> ingr);
        /**
         * @brief Se establece el valor privado datos a partir del parámetro auxiliar
         * @param auxiliar, arbol que se va a insertar como dato miembro
        */
        void setDatos(const ArbolBinario<string> & auxiliar);
        /**
         * @brief Se devuelve las acciones del objeto instrucciones que ha invocado a las funcion
        */
        acciones getAcciones() const{return acc;};
        /**
         * @brief Se devuelve un vector con los nombres de los ingredientes del objeto invocante de la funcion
        */
        vector<string> getIngredientes() const{return nombre_ingredientes;};
        /**
         * @brief Devuelve un objeto de tipo arbol binario
        */
        ArbolBinario<string> getDatos() const{return datos;};
        /**
         * @brief Devuelve el número de operandos de una accion dada
         * @param accion, accion cuyos operandos se quieren conocer
         * @return numero de operandos de la accion que se ha pasado como parámetro
        */
        int obtenerOperando(const string & accion);
        /**
         * @brief Comprueba si el ingrediente pasado como parámetro esta en la lista de permitidos
         * @param ingrediente, ingrediente que se quiere comprobar que sea valido
         * @return true, si el ingrediente esta en la lista de permitidos, false en caso contrario
        */
        bool ValidarIngredientes(const string & ingrediente)const;
        /**
         * @brief Comprueba si la accion pasada como parámetro está en la lista de acciones permitidas
         * @param accion, accion que se quiere comprobar si es válida
         * @return true, si la accion es válida, false en caso contrario
        */
        pair<bool,int> ValidarAcciones(const string & accion)const;
        /**
         * @brief Dados un flujo de entrada y un objeto de instrucciones modificable se almacenan los datos del flujo de entrada en el objeto
         * @param is, flujo de entrada donde se tomarán los datos
         * @param entrada, objeto donde se almacenan los datos
        */
        void Lee(std::istream & is,instrucciones & entrada );
        /**
         * @brief Función que devuelve el arbol binario asociado al objeto que invoca la función
         * @return Arbol binario del objeto que invoca la función
         */
        ArbolBinario<string> & getDatos(){return this->datos;};
        /**
         * @brief Fusiona al objeto invocante de la funcion con el objeto parámetro
         * @param auxiliar, objeto instrucciones con el que se quieren fusionar
         * @return objeto de instrucciones que es fusion de los dos.
        */
        instrucciones Fusionar(const instrucciones & auxiliar);
        /** 
         * @brief Funcion amiga, sobrecarga del operador de salida
        */
        friend std::ostream & operator<<(std::ostream & os, instrucciones & salida);
        /**
         * @brief Funcion amiga, sobrecarga del operador de entrada
        */
        friend std::istream & operator>>(std::istream & is, instrucciones & entrada);
        
        


};

std::ostream & operator<<(std::ostream & os, instrucciones & salida);
std::istream & operator>>(std::istream & is,instrucciones & entrada);

#endif
