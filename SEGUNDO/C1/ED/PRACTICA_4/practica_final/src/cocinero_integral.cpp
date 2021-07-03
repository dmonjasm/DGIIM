#include "receta.h"
#include "recetas.h"
#include "acciones.h"
#include "arbolbinario.h"
#include "ingrediente.h"
#include "ingredientes.h"
#include "instrucciones.h"
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>


using namespace std;

void error(){
    cout << "Modo de ejecución: <programa> <archivo_acciones> <archivo_recetas> <archivo_ingredientes> <pathname_instrucciones>" << endl;
    exit(-1);
}

unsigned int minimo(int a, int b){
    unsigned int minimo;

    if(a <= b){
        minimo = a;
    }
    else{
        minimo = b;
    }

    return minimo;
}

void mostrarRecetas(recetas rec){
        recetas::iterator it=rec.begin();

        for(;it != rec.end(); ++it){
            cout << "\033[34m CODE: \033[0m" << (*it).getCode() << "\033[34m \tNOMBRE: \033[0m" << (*it).getNombre() << "\033[34m \tPLATO: \033[0m" << (*it).getPlato() << endl;
        }

    }

receta buscarReceta(string codigo,recetas rec, ingredientes ingr){
    receta buscada;
    buscada = rec[codigo];
    buscada.setNutricion(ingr);
    buscada.setCode(codigo);
    
    return buscada;
}

void mostrarRecetaCodigo(receta buscada){
    cout << "\033[34mCODIGO:\033[0m" << buscada.getCode() << "\033[34m RECETA:\033[0m" << buscada.getNombre() << "\033[34m PLATO:\033[0m" << buscada.getPlato() << endl;
    cout << endl << "\033[1;4mIngredientes:\033[0m" << endl;
    for(receta::iterator it=buscada.begin(); it != buscada.end(); ++it){
        cout << "\t" << (*it).first << " " << (*it).second << endl;
    }

    cout << endl << "\033[1;4mInformación nutricional:\033[0m " << endl;
    cout << "\t" << "Calorias:" << buscada.getCalorias() << endl;
    cout << "\t" << "Hidratos de Carbono:" << buscada.getHc() << endl;
    cout << "\t" << "Grasas:" << buscada.getGrasas() << endl;
    cout << "\t" << "Proteinas:" << buscada.getProteinas() << endl;
    cout << "\t" << "Fibra:" << buscada.getFibra() << endl;

    }

receta recetaFusion(string code_1, string code_2, recetas recet, ingredientes ingr,receta buscada1, receta buscada2){
    receta fusion;

    string code_fusion = "F_" + code_1 + "_" + code_2;
    string nombre_fusion = buscada1.getNombre() + " y " + buscada2.getNombre();
    int plato_fusion = minimo(buscada1.getPlato(),buscada2.getPlato());


    list<pair<string,unsigned int>> ingredientes_fusion;
    
    list<pair<string,unsigned int>> ingr_rec_1 = buscada1.getIngredientes();
    list<pair<string,unsigned int>> ingr_rec_2 = buscada2.getIngredientes();

    list<pair<string,unsigned int>>::iterator iterador;
    list<pair<string,unsigned int>>::iterator it;
    list<pair<string,unsigned int>> auxiliar;

    ingredientes_fusion = ingr_rec_1;

    for(it = ingredientes_fusion.begin(); it != ingredientes_fusion.end(); ++it){
        for(iterador = ingr_rec_2.begin(); iterador != ingr_rec_2.end(); ++iterador){
            if((*it).first == (*iterador).first){
                (*it).second = (*it).second + (*iterador).second;
                auxiliar.push_back(*iterador);
            }
        }
    }
    
    for(it = auxiliar.begin(); it != auxiliar.end(); ++it){
        ingr_rec_2.remove(*it);
    }

    for(iterador = ingr_rec_2.begin(); iterador != ingr_rec_2.end(); ++iterador){
        ingredientes_fusion.push_back(*iterador);
    }
    fusion.setCode(code_fusion);
    fusion.setPlato(plato_fusion); 
    fusion.setNombre(nombre_fusion);
    fusion.setIngredientes(ingredientes_fusion);
    fusion.setCalorias(buscada1.getCalorias() + buscada2.getCalorias());
    fusion.setHc(buscada1.getHc() + buscada2.getHc());
    fusion.setGrasas(buscada1.getGrasas() + buscada2.getGrasas());
    fusion.setProteinas(buscada1.getProteinas() + buscada2.getProteinas());
    fusion.setFibra(buscada1.getFibra() + buscada2.getFibra());

    return fusion;
    }

int main(int argc, char * argv[]){

    if(argc < 5){
        error();
    }

    acciones all_acciones;
    ingredientes all_ingredientes;
    recetas all_recetas;
    vector<string> all_nombres;
    instrucciones all_instrucciones;
    string nf=argv[1];
    ifstream entrada(nf);
    string path_instrucciones=argv[4];

    if(!entrada){
        cerr << "error al abrir el archivo de acciones" << endl;
        exit(-1);
    }

    entrada >> all_acciones;

    entrada.close();
    nf=argv[2];

    entrada.open(nf);
    if(!entrada){
        cerr << "error al abrir el archivo de recetas" << endl;
        exit(-1);
    }

    entrada >> all_recetas;
    entrada.close();

    nf=argv[3];

    entrada.open(nf);

    if(!entrada){
        cerr << "error al abrir el archivo de ingredientes" << endl;
        exit(-1);
    }

    entrada >> all_ingredientes;

    entrada.close();

    all_nombres=all_ingredientes.getNombreIngredientes();
    mostrarRecetas(all_recetas);

    string codigo;
    

    cout << "Introduzca el código de una receta: " << endl;
    cin >> codigo;

    receta buscada = buscarReceta(codigo,all_recetas,all_ingredientes);
    mostrarRecetaCodigo(buscada);

    string path_receta_principal=path_instrucciones + codigo + "m.txt";

    nf=path_receta_principal;
    entrada.open(nf);

    if(!entrada){
        cerr << "Error al abrir el archivo con las instrucciones" << endl;
    }

    all_instrucciones.setAcciones(all_acciones);
    all_instrucciones.setIngredientes(all_nombres);
    
    entrada >> all_instrucciones;

    entrada.close();

    cout << endl << "\033[1;4mPasos a seguir:\033[0m" << endl;

    cout << all_instrucciones;

    string code_1;
    string code_2;

    cout << endl << "\033[1;4;91mSe quiere hacer una receta fusión. Se necesitan dos recetas.\033[0m" << endl;
    cout << "Introduzca el código de la primera receta: " << endl;
    cin >> code_1;
    cout << "Introduzca el código de la segunda receta: " << endl;
    cin >> code_2;
    
    receta buscada1 = buscarReceta(code_1,all_recetas,all_ingredientes);
    receta buscada2 = buscarReceta(code_2,all_recetas,all_ingredientes);

    receta fusion = recetaFusion(code_1,code_2,all_recetas,all_ingredientes,buscada1,buscada2);
   
    mostrarRecetaCodigo(fusion);

    string path_instr_fus_1 = path_instrucciones + code_1 + "m.txt";
    instrucciones auxiliar_1;
    nf=path_instr_fus_1;
    entrada.open(nf);
    auxiliar_1.setAcciones(all_acciones);
    auxiliar_1.setIngredientes(all_nombres);
    
    entrada >> auxiliar_1;

    entrada.close();

    cout << endl << "\033[1;4mPasos a seguir:\033[0m" << endl;

    string path_instr_fus_2 = path_instrucciones + code_2 + "m.txt";
    instrucciones auxiliar_2;
    nf=path_instr_fus_2;
    entrada.open(nf);
    auxiliar_2.setAcciones(all_acciones);
    auxiliar_2.setIngredientes(all_nombres);
    
    entrada >> auxiliar_2;
    
    entrada.close();

    auxiliar_1.Fusionar(auxiliar_2);

    //mostrarPasos(auxiliar_1,all_acciones,all_ingredientes);

    cout << auxiliar_1;

    return 0;
}