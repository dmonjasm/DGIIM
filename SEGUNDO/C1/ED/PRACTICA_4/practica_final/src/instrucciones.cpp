#include "instrucciones.h"
#include "ingrediente.h"
#include "ingredientes.h"
#include "acciones.h"
#include "receta.h"
#include "recetas.h"
#include "arbolbinario.h"
#include <stack>


pair<bool,int> instrucciones::ValidarAcciones(const string & accion) const{
    acciones::const_iterator it=acc.begin();
    bool encontrado=false;
    int operandos=-1;
    pair<bool,int> retorno;
    
    for(; it != acc.end() && !encontrado; ++it){
        if(accion == (*it).first){
            encontrado=true;
            operandos=(int)(*it).second;
        }
    }

    retorno.first=encontrado;
    retorno.second=operandos;

    return retorno;
}

int instrucciones:: obtenerOperando(const string  & accion){
    pair<bool,int> acciones_encontrada;

    acciones_encontrada=ValidarAcciones(accion);

    if(!acciones_encontrada.first){
        cerr << "No se ha encontrado la accion en el conjunto de acciones" << endl;
    }

    return acciones_encontrada.second;
}

void instrucciones::setIngredientes(const vector<string> & ingredientes_receta){
    if(ingredientes_receta.size() != 0){
        nombre_ingredientes=ingredientes_receta;
    }

    else{
        cerr << "Error no se ha pasado un conjunto vacío de ingredientes de la receta" << endl;
    }
}

bool instrucciones::ValidarIngredientes(const string & ingrediente) const{
    bool encontrado=false;

    if(nombre_ingredientes.size() != 0){
        for(int i=0; i < nombre_ingredientes.size() && !encontrado; i++){
            if(ingrediente==nombre_ingredientes[i]){
                encontrado=true;
            }
        }
    }

    else{
        cerr << "No se han registrado los ingredientes de la receta" << endl;
    }

    return encontrado;
}

void instrucciones::Lee(std::istream & is, instrucciones & entrada){
    string cadena_auxiliar;
    string accion;
    string ingrediente;
    vector<int> espacios;
    pair<bool,int> operandos_accion;
    stack<ArbolBinario<string>> acumulador;
    int contador=0;
    int posicion_fijada=0;
    bool ingrediente_encontrado=false;

    while(is){
        getline(is,cadena_auxiliar);
        if(cadena_auxiliar.size()==0){
            continue;
        }

            ingrediente_encontrado=false;
            espacios.clear();

            if(cadena_auxiliar.find(" ") == -1){
                accion=cadena_auxiliar;
                operandos_accion=entrada.ValidarAcciones(accion);
                //cout << "Las cadenas auxiliares sin operandos son: " << cadena_auxiliar << endl;

                if(!operandos_accion.first){
                    cerr << "Error la accion no se encuentra en el conjunto";
                    exit(-1);
                }

                ArbolBinario<string> auxiliar(accion);
                ArbolBinario<string>::nodo it=auxiliar.getRaiz();

                if(acumulador.empty()){
                    cerr << "La pila está vacía" << endl;
                    exit(-1);
                }  

                if(operandos_accion.second==1){
                    auxiliar.Insertar_Hi(it,acumulador.top());
                    acumulador.pop();
                }  

                if(operandos_accion.second==2){
                    auxiliar.Insertar_Hd(it, acumulador.top());
                    acumulador.pop();
                
                    if(!acumulador.empty()){
                        auxiliar.Insertar_Hi(it, acumulador.top());
                        acumulador.pop();
                    }

                    else{
                        cerr << "La pila está vacía" << endl;
                        exit(-1);
                    }
                }

                acumulador.push(auxiliar);
            }

            else{
                espacios.push_back(cadena_auxiliar.find(" "));

                while(cadena_auxiliar.find(" ",espacios[espacios.size()-1]+1) != -1){
                    espacios.push_back(cadena_auxiliar.find(" ",espacios[espacios.size()-1]+1));
                }

                accion=cadena_auxiliar.substr(0,espacios[0]);

                operandos_accion=entrada.ValidarAcciones(accion);

                if(!operandos_accion.first){
                    cout << "La siguiente accion no está en la lista ->" << accion << endl;
                    cerr << "Error la acción no se ha encontrado" << endl;
                    exit(-1);
                }

                ArbolBinario<string> auxiliar_2(accion);
                ArbolBinario<string>::nodo it_2=auxiliar_2.getRaiz();

                if(operandos_accion.second==1){
                    ingrediente=cadena_auxiliar.substr(espacios[0]+1);
                    ingrediente_encontrado=entrada.ValidarIngredientes(ingrediente);

                    if(!ingrediente_encontrado){
                        cerr << "No se ha encontrado el ingrediente en la lista de ingredientes" << endl;
                        exit(-1);
                    }

                    auxiliar_2.Insertar_Hi(it_2,ingrediente);
                    acumulador.push(auxiliar_2);
                    auxiliar_2.clear();
                }

                if(operandos_accion.second==2){
                    ingrediente=cadena_auxiliar.substr(espacios[0]+1);
                    ingrediente_encontrado=entrada.ValidarIngredientes(ingrediente);

                    if(ingrediente_encontrado){
                        auxiliar_2.Insertar_Hi(it_2,acumulador.top());
                        acumulador.pop();
                        auxiliar_2.Insertar_Hd(it_2,ingrediente);
                    }

                    else{
                        for(int i=0; i < espacios.size()-1 && !ingrediente_encontrado ;i++){
                            ingrediente=cadena_auxiliar.substr(espacios[0]+1,espacios[1+i]-espacios[0]);
                            ingrediente_encontrado=entrada.ValidarIngredientes(ingrediente);

                            if(ingrediente_encontrado){
                                posicion_fijada=espacios[1+i]+1;
                            }
                        }

                        if(!ingrediente_encontrado){
                            cerr << "No se ha encontrado ningun ingrediente" << endl;
                            exit(-1);
                        }

                        auxiliar_2.Insertar_Hi(it_2,ingrediente);
                        ingrediente=cadena_auxiliar.substr(posicion_fijada);
                        ingrediente_encontrado=entrada.ValidarIngredientes(ingrediente);

                        if(!ingrediente_encontrado){
                            cerr << "El ingrediente no está en la lista" << endl;
                            exit(-1);
                        }

                        auxiliar_2.Insertar_Hd(it_2,ingrediente);

                    }
                    acumulador.push(auxiliar_2);
                }
            }       
    }

    if(acumulador.empty()){
        cerr << "La pila está vacía" << endl;
        exit(-1);
    }
    else{
        ArbolBinario<string> salida(acumulador.top());
        entrada.datos=salida;  
        acumulador.pop();
    }  
}



void instrucciones::mostarPasos(instrucciones instr, acciones acc, vector<string> ingr){
    ArbolBinario<string>::postorden_iterador iter = instr.getDatos().beginpostorden();
    string aux_ing;
    string aux_acc;

    for(; iter != instr.getDatos().endpostorden(); ++iter){
        bool es_ingrediente = false;
        string total;
        acciones::iterator iter_acc = acc.begin();
        vector<string>::iterator iter_ing = ingr.begin();
        for(;iter_ing != ingr.end();++iter_ing){
            if((*iter) == (*iter_ing)){
                aux_ing = (*iter);
                es_ingrediente = true;  
            }
        }

        if(!es_ingrediente){
            for(;iter_acc != acc.end(); ++iter_acc){
                if((*iter) == (*iter_acc).first){
                    aux_acc = (*iter);
                    total = aux_acc + " " + aux_ing;
                    cout << "\t" << total << endl;
                    aux_ing = "";
                }
            }
        }
    }
}

std::istream & operator>>(std::istream &is, instrucciones & entrada){
    entrada.Lee(is,entrada);
    return is;
}

std::ostream & operator<<(std::ostream &os, instrucciones & salida){
    salida.mostarPasos(salida,salida.getAcciones(),salida.getIngredientes());
    return os;
}

void instrucciones::setDatos(const ArbolBinario<string> & auxiliar){
    datos=auxiliar;
}

instrucciones instrucciones::Fusionar(const instrucciones & auxiliar){
    ArbolBinario<string> resultado("Acompañar");
    ArbolBinario<string> operando=auxiliar.getDatos();
    ArbolBinario<string>::nodo it=resultado.getRaiz();

    resultado.Insertar_Hi(it,datos);
    resultado.Insertar_Hd(it, operando);
    datos=resultado;
    acc=auxiliar.getAcciones();
    nombre_ingredientes=auxiliar.getIngredientes();

    return *this;    
}