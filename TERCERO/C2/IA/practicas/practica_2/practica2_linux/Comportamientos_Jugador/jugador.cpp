#include "../Comportamientos_Jugador/jugador.hpp"
#include "motorlib/util.h"

#include <iostream>
#include <cmath>
#include <set>
#include <stack>
#include <queue>
#include <math.h>

// Este es el método principal que se piden en la practica.
// Tiene como entrada la información de los sensores y devuelve la acción a realizar.
// Para ver los distintos sensores mirar fichero "comportamiento.hpp"
Action ComportamientoJugador::think(Sensores sensores) {
	Action accion = actIDLE;

	unsigned char contenidoCasilla;

	actual.fila        = sensores.posF;
	actual.columna     = sensores.posC;
	actual.orientacion = sensores.sentido;

	cout << "Fila: " << actual.fila << endl;
	cout << "Col : " << actual.columna << endl;
	cout << "Ori : " << actual.orientacion << endl;

	// Capturo los destinos
	cout << "sensores.num_destinos : " << sensores.num_destinos << endl;
	objetivos.clear();
	for (int i=0; i<sensores.num_destinos; i++){
		estado aux;
		aux.fila = sensores.destino[2*i];
		aux.columna = sensores.destino[2*i+1];
		objetivos.push_back(aux);
	}

	Action sigAction;
	if(!hayPlan){
		hayPlan = pathFinding(sensores.nivel, actual, objetivos, plan);
	}

	//Intento Nivel 4
	/*if(sensores.nivel == 4){
		muestraMapa(sensores);

		bool es_objetivo=false;

		for(list<estado>::const_iterator it=objetivos.begin(); it!=objetivos.end() && !es_objetivo; it++){
			if((*it).fila==sensores.posF && (*it).columna==sensores.posC){
				es_objetivo=true;
				objetivos.erase(it);
			}
		}

		if((sensores.superficie[2]=='a' || sensores.terreno[2]=='M' || sensores.terreno[2]=='P') && hayPlan){
			char valor_previo;
			int col_previa;
			int fil_previa;
			switch(sensores.sentido){
				case norte:
					valor_previo=mapaResultado[sensores.posF-1][sensores.posC];

					fil_previa = sensores.posF-1;
					col_previa = sensores.posC;

					mapaResultado[sensores.posF-1][sensores.posC]='P';
					
				break;

				case sur:
					valor_previo=mapaResultado[sensores.posF+1][sensores.posC];

					fil_previa = sensores.posF + 1;
					col_previa = sensores.posC;

					mapaResultado[sensores.posF+1][sensores.posC]='P';
				break;

				case este:
					valor_previo=mapaResultado[sensores.posF][sensores.posC+1];

					fil_previa = sensores.posF;
					col_previa = sensores.posC + 1;

					mapaResultado[sensores.posF][sensores.posC+1]='P';
				break;

				case oeste:
					valor_previo=mapaResultado[sensores.posF][sensores.posC-1];

					fil_previa = sensores.posF;
					col_previa = sensores.posC - 1;

					mapaResultado[sensores.posF][sensores.posC-1]='P';
				break;
			}

			hayPlan = pathFinding(sensores.nivel, actual, objetivos, plan);

			mapaResultado[fil_previa][col_previa]=valor_previo;
		}

		if(sensores.bateria<1000 && !cargadores.empty()){
			hayPlan = pathFinding(sensores.nivel, actual, cargadores, plan);
		}

		if(sensores.terreno[2]=='A' || sensores.terreno[2]=='B'){
			hayPlan = pathFinding(sensores.nivel, actual, objetivos, plan);
		}

		
	}*/

	if(hayPlan && plan.size()>0){
		sigAction = plan.front();
		plan.erase(plan.begin());
	}

	else{
		cout << "no se pudo encontrar el plan\n";
	}

  return sigAction;
}


//Intento de nivel 4
void ComportamientoJugador::muestraMapa(Sensores sensores){
	int numero_casillas=0;
	int tope_bajo=-1;
	int tope_alto=1;
	estado cargador;

	mapaResultado[sensores.posF][sensores.posF] = sensores.terreno[numero_casillas];

	numero_casillas++;

	switch(sensores.sentido){
		case norte:

			for(int i=1; i <= 3; i++){
				for(int j=tope_bajo; j <= tope_alto; j++){
					mapaResultado[sensores.posF-i][sensores.posC+j]=sensores.terreno[numero_casillas];

					if(sensores.terreno[numero_casillas]=='X'){
						cargador.fila=sensores.posF-i;
						cargador.columna=sensores.posC+j;

						cargadores.push_back(cargador);
					}

					numero_casillas++;
				}

				tope_bajo--;
				tope_alto++;
			}
		break;

		case sur:

			for(int i=1; i <= 3; i++){
				for(int j=tope_bajo; j <= tope_alto; j++){
					mapaResultado[sensores.posF+i][sensores.posC+j]=sensores.terreno[numero_casillas];

					if(sensores.terreno[numero_casillas]=='X'){
						cargador.fila=sensores.posF+i;
						cargador.columna=sensores.posC+j;

						cargadores.push_back(cargador);
					}

					numero_casillas++;
				}

				tope_bajo--;
				tope_alto++;
			}
		break;

		case este:

			for(int i=1; i <= 3; i++){
				for(int j=tope_bajo; j <= tope_alto; j++){
					mapaResultado[sensores.posF+j][sensores.posC+i]=sensores.terreno[numero_casillas];

					if(sensores.terreno[numero_casillas]=='X'){
						cargador.fila=sensores.posF+j;
						cargador.columna=sensores.posC+i;

						cargadores.push_back(cargador);
					}

					numero_casillas++;
				}

				tope_bajo--;
				tope_alto++;
			}

		break;

		case oeste:

			for(int i=1; i <= 3; i++){
				for(int j=tope_bajo; j <= tope_alto; j++){
					mapaResultado[sensores.posF+j][sensores.posC-i]=sensores.terreno[numero_casillas];

					if(sensores.terreno[numero_casillas]=='X'){
						cargador.fila=sensores.posF+j;
						cargador.columna=sensores.posC-i;

						cargadores.push_back(cargador);
					}

					numero_casillas++;
				}

				tope_bajo--;
				tope_alto++;
			}
		break;
	}
}


// Llama al algoritmo de busqueda que se usara en cada comportamiento del agente
// Level representa el comportamiento en el que fue iniciado el agente.
bool ComportamientoJugador::pathFinding (int level, const estado &origen, const list<estado> &destino, list<Action> &plan){
	estado un_objetivo;

	switch (level){
		case 0: cout << "Demo\n";
						un_objetivo = objetivos.front();
						cout << "fila: " << un_objetivo.fila << " col:" << un_objetivo.columna << endl;
			      return pathFinding_Profundidad(origen,un_objetivo,plan);
						break;

		case 1: cout << "Optimo numero de acciones\n";
						un_objetivo = objetivos.front();
						cout << "fila: " << un_objetivo.fila << " col:" << un_objetivo.columna << endl;
			      return pathFinding_Anchura(origen,un_objetivo,plan);
						cout << "No implementado aun\n";
						break;

		case 2: cout << "Optimo en coste 1 Objetivo\n";
						un_objetivo = objetivos.front();
						cout << "fila: " << un_objetivo.fila << " col:" << un_objetivo.columna << endl;
			      return pathFinding_A_estrella(origen,un_objetivo,plan);
						cout << "No implementado aun\n";
						break;
		case 3: cout << "Optimo en coste 3 Objetivos\n";
						for(list<estado>::const_iterator it=objetivos.begin(); it!=objetivos.end(); it++){
							cout << "fila: " << (*it).fila << " col:" << (*it).columna << endl;
						}
					/*return pathFinding_Costo_Uniforme_Nivel3(origen, objetivos, plan);*/
					return pathFinding_A_estrella_Nivel3(origen,destino,plan);
						break;
		case 4: cout << "Algoritmo de busqueda usado en el reto\n";
						un_objetivo = objetivos.front();
						cout << "fila: " << un_objetivo.fila << " col:" << un_objetivo.columna << endl;
			      return pathFinding_A_estrella(origen,un_objetivo,plan);
						cout << "No implementado aun\n";
						break;
	}
	return false;
}


//---------------------- Implementación de la busqueda en profundidad ---------------------------

// Dado el codigo en caracter de una casilla del mapa dice si se puede
// pasar por ella sin riegos de morir o chocar.
bool EsObstaculo(unsigned char casilla){
	if (casilla=='P' or casilla=='M')
		return true;
	else
	  return false;
}


// Comprueba si la casilla que hay delante es un obstaculo. Si es un
// obstaculo devuelve true. Si no es un obstaculo, devuelve false y
// modifica st con la posición de la casilla del avance.
bool ComportamientoJugador::HayObstaculoDelante(estado &st){
	int fil=st.fila, col=st.columna;

  // calculo cual es la casilla de delante del agente
	switch (st.orientacion) {
		case 0: fil--; break;
		case 1: col++; break;
		case 2: fil++; break;
		case 3: col--; break;
	}

	// Compruebo que no me salgo fuera del rango del mapa
	if (fil<0 or fil>=mapaResultado.size()) return true;
	if (col<0 or col>=mapaResultado[0].size()) return true;

	// Miro si en esa casilla hay un obstaculo infranqueable
	if (!EsObstaculo(mapaResultado[fil][col])){
		// No hay obstaculo, actualizo el parametro st poniendo la casilla de delante.
    st.fila = fil;
		st.columna = col;
		return false;
	}
	else{
	  return true;
	}
}




struct nodo{
	estado st;
	list<Action> secuencia;
};

struct ComparaEstados{
	bool operator()(const estado &a, const estado &n) const{
		if ((a.fila > n.fila) or (a.fila == n.fila and a.columna > n.columna) or
	      (a.fila == n.fila and a.columna == n.columna and a.orientacion > n.orientacion)){
				return true;
		}
		else
			return false;
	}
};


// Implementación de la busqueda en profundidad.
// Entran los puntos origen y destino y devuelve la
// secuencia de acciones en plan, una lista de acciones.
bool ComportamientoJugador::pathFinding_Profundidad(const estado &origen, const estado &destino, list<Action> &plan) {
	//Borro la lista
	cout << "Calculando plan\n";
	plan.clear();
	set<estado,ComparaEstados> Cerrados; // Lista de Cerrados
	stack<nodo> Abiertos;								 // Lista de Abiertos

  nodo current;
	current.st = origen;
	current.secuencia.empty();

	Abiertos.push(current);

  while (!Abiertos.empty() and (current.st.fila!=destino.fila or current.st.columna != destino.columna)){

		Abiertos.pop();
		Cerrados.insert(current.st);

		// Generar descendiente de girar a la derecha
		nodo hijoTurnR = current;
		hijoTurnR.st.orientacion = (hijoTurnR.st.orientacion+1)%4;
		if (Cerrados.find(hijoTurnR.st) == Cerrados.end()){
			hijoTurnR.secuencia.push_back(actTURN_R);
			Abiertos.push(hijoTurnR);

		}

		// Generar descendiente de girar a la izquierda
		nodo hijoTurnL = current;
		hijoTurnL.st.orientacion = (hijoTurnL.st.orientacion+3)%4;
		if (Cerrados.find(hijoTurnL.st) == Cerrados.end()){
			hijoTurnL.secuencia.push_back(actTURN_L);
			Abiertos.push(hijoTurnL);
		}

		// Generar descendiente de avanzar
		nodo hijoForward = current;
		if (!HayObstaculoDelante(hijoForward.st)){
			if (Cerrados.find(hijoForward.st) == Cerrados.end()){
				hijoForward.secuencia.push_back(actFORWARD);
				Abiertos.push(hijoForward);
			}
		}

		// Tomo el siguiente valor de la Abiertos
		if (!Abiertos.empty()){
			current = Abiertos.top();

			while(Cerrados.find(current.st) != Cerrados.end()){
				Abiertos.pop();
				current=Abiertos.top();
			}
		}
	}

  cout << "Terminada la busqueda\n";

	if (current.st.fila == destino.fila and current.st.columna == destino.columna){
		cout << "Cargando el plan\n";
		plan = current.secuencia;
		cout << "Longitud del plan: " << plan.size() << endl;
		PintaPlan(plan);
		// ver el plan en el mapa
		VisualizaPlan(origen, plan);
		return true;
	}
	else {
		cout << "No encontrado plan\n";
	}


	return false;
}







// Sacar por la consola la secuencia del plan obtenido
void ComportamientoJugador::PintaPlan(list<Action> plan) {
	auto it = plan.begin();
	while (it!=plan.end()){
		if (*it == actFORWARD){
			cout << "A ";
		}
		else if (*it == actTURN_R){
			cout << "D ";
		}
		else if (*it == actTURN_L){
			cout << "I ";
		}
		else {
			cout << "- ";
		}
		it++;
	}
	cout << endl;
}


// Funcion auxiliar para poner a 0 todas las casillas de una matriz
void AnularMatriz(vector<vector<unsigned char> > &m){
	for (int i=0; i<m[0].size(); i++){
		for (int j=0; j<m.size(); j++){
			m[i][j]=0;
		}
	}
}


// Pinta sobre el mapa del juego el plan obtenido
void ComportamientoJugador::VisualizaPlan(const estado &st, const list<Action> &plan){
  AnularMatriz(mapaConPlan);
	estado cst = st;

	auto it = plan.begin();
	while (it!=plan.end()){
		if (*it == actFORWARD){
			switch (cst.orientacion) {
				case 0: cst.fila--; break;
				case 1: cst.columna++; break;
				case 2: cst.fila++; break;
				case 3: cst.columna--; break;
			}
			mapaConPlan[cst.fila][cst.columna]=1;
		}
		else if (*it == actTURN_R){
			cst.orientacion = (cst.orientacion+1)%4;
		}
		else {
			cst.orientacion = (cst.orientacion+3)%4;
		}
		it++;
	}
}



int ComportamientoJugador::interact(Action accion, int valor){
  return false;
}

//---------------------- Implementación de la busqueda en anchura ---------------------------
// Implementación de la busqueda en anchura. Exactamente igual que la búsqueda en anchura cambiando la pila LIFO por una lista FIFO
// Entran los puntos origen y destino y devuelve la
// secuencia de acciones en plan, una lista de acciones.
bool ComportamientoJugador::pathFinding_Anchura(const estado &origen, const estado &destino, list<Action> &plan) {
	//Borro la lista
	cout << "Calculando plan\n";
	plan.clear();
	set<estado,ComparaEstados> Cerrados; // Lista de Cerrados
	queue<nodo> Abiertos;				 // Lista de Abiertos

  nodo current;
	current.st = origen;
	current.secuencia.empty();

	Abiertos.push(current);

  while (!Abiertos.empty() and (current.st.fila!=destino.fila or current.st.columna != destino.columna)){

		Abiertos.pop();
		Cerrados.insert(current.st);

		// Generar descendiente de girar a la derecha
		nodo hijoTurnR = current;
		hijoTurnR.st.orientacion = (hijoTurnR.st.orientacion+1)%4;
		if (Cerrados.find(hijoTurnR.st) == Cerrados.end()){
			hijoTurnR.secuencia.push_back(actTURN_R);
			Abiertos.push(hijoTurnR);

		}

		// Generar descendiente de girar a la izquierda
		nodo hijoTurnL = current;
		hijoTurnL.st.orientacion = (hijoTurnL.st.orientacion+3)%4;
		if (Cerrados.find(hijoTurnL.st) == Cerrados.end()){
			hijoTurnL.secuencia.push_back(actTURN_L);
			Abiertos.push(hijoTurnL);
		}

		// Generar descendiente de avanzar
		nodo hijoForward = current;
		if (!HayObstaculoDelante(hijoForward.st)){
			if (Cerrados.find(hijoForward.st) == Cerrados.end()){
				hijoForward.secuencia.push_back(actFORWARD);
				Abiertos.push(hijoForward);
			}
		}

		// Tomo el siguiente valor de la Abiertos
		if (!Abiertos.empty()){
			current = Abiertos.front();

			while(Cerrados.find(current.st) != Cerrados.end()){
				Abiertos.pop();
				current=Abiertos.front();
			}
		}
	}

  cout << "Terminada la busqueda\n";
  

	if (current.st.fila == destino.fila and current.st.columna == destino.columna){
		cout << "Cargando el plan\n";
		plan = current.secuencia;
		cout << "Longitud del plan: " << plan.size() << endl;
		PintaPlan(plan);
		// ver el plan en el mapa
		VisualizaPlan(origen, plan);
		return true;
	}
	else {
		cout << "No encontrado plan\n";
	}


	return false;
}

int CalcularCosto(const Action &a,bool &b, bool &z,const estado &padre,vector< vector< unsigned char> > mapaResultado){
	int costo_total=0;

	switch(mapaResultado[padre.fila][padre.columna]){
		case 'A':
			if(a==actFORWARD){
				if(b){
					costo_total=10;
				}

				else{
					costo_total=200;
				}
			}

			else{
				if(b){
					costo_total=5;
				}

				else{
					costo_total=500;
				}
			}
		break;

		case 'B':
			if(a==actFORWARD){
				if(z){
					costo_total=15;
				}

				else{
					costo_total=100;
				}
			}

			else{
				if(z){
					costo_total=1;
				}

				else{
					costo_total=3;
				}
			}
		break;

		case 'T':
			costo_total=2;
		break;

		case 'D':
			if(!b){
				z=true;
			}
			else{
				b=false;
				z=true;
			}

			costo_total=1;
		break;

		case 'K':
			if(!z){
				b=true;
			}
			else{
				z=false;
				b=true;
			}

			costo_total=1;
		break;

		default:
			costo_total=1;
		break;
	}

	return costo_total;
}

struct ComparaNodos{
	bool operator()(const nodo &a, const nodo &n){
		return a.st.coste>n.st.coste;
	}
};

struct ComparaEstadosCU{
	bool operator()(const estado &a, const estado &n) const{
		if((a.fila > n.fila) or (a.fila == n.fila and a.columna > n.columna) or
	      (a.fila == n.fila and a.columna == n.columna and a.orientacion > n.orientacion) or
		  (a.fila == n.fila and a.columna == n.columna and a.orientacion == n.orientacion and (a.bikini > n.bikini)) or
		  (a.fila == n.fila and a.columna == n.columna and a.orientacion == n.orientacion and a.bikini == n.bikini and a.zapatillas > n.zapatillas)){
				return true;
		}
		else
			return false;
	}
};


//---------------------- Implementación de la busqueda con Costo Uniforme ---------------------------
// Implementación de la busqueda con Costo Uniforme.
// Entran los puntos origen y destino y devuelve la
// secuencia de acciones en plan, una lista de acciones.
bool ComportamientoJugador::pathFinding_Costo_Uniforme(const estado &origen, const estado &destino, list<Action> &plan) {
	//Borro la lista
	cout << "Calculando plan\n";
	plan.clear();
	set<estado,ComparaEstadosCU> Cerrados; // Lista de Cerrados
	priority_queue<nodo,vector<nodo>, ComparaNodos> Abiertos;				 // Lista de Abiertos

  nodo current;
	current.st = origen;
	current.secuencia.empty();
	current.st.bikini=false;
	current.st.zapatillas=false;
	current.st.coste=0;

	Abiertos.push(current);

  while (!Abiertos.empty() and (current.st.fila!=destino.fila or current.st.columna != destino.columna)){
		Abiertos.pop();
		Cerrados.insert(current.st);

		// Generar descendiente de girar a la derecha
		nodo hijoTurnR = current;
		hijoTurnR.st.orientacion = (hijoTurnR.st.orientacion+1)%4;
		if (Cerrados.find(hijoTurnR.st) == Cerrados.end()){
			hijoTurnR.secuencia.push_back(actTURN_R);
			hijoTurnR.st.coste+=CalcularCosto(actTURN_R,current.st.bikini,current.st.zapatillas,current.st,mapaResultado);
			Abiertos.push(hijoTurnR);

		}

		// Generar descendiente de girar a la izquierda
		nodo hijoTurnL = current;
		hijoTurnL.st.orientacion = (hijoTurnL.st.orientacion+3)%4;
		if (Cerrados.find(hijoTurnL.st) == Cerrados.end()){
			hijoTurnL.secuencia.push_back(actTURN_L);
			hijoTurnL.st.coste+=CalcularCosto(actTURN_L,current.st.bikini,current.st.zapatillas,current.st,mapaResultado);
			Abiertos.push(hijoTurnL);
		}

		// Generar descendiente de avanzar
		nodo hijoForward = current;
		if (!HayObstaculoDelante(hijoForward.st)){
			if (Cerrados.find(hijoForward.st) == Cerrados.end()){
				hijoForward.secuencia.push_back(actFORWARD);
				hijoForward.st.coste+=CalcularCosto(actFORWARD,current.st.bikini,current.st.zapatillas,current.st,mapaResultado);
				Abiertos.push(hijoForward);
			}
		}

		// Tomo el siguiente valor de la Abiertos
		if (!Abiertos.empty()){
			current = Abiertos.top();

			while(Cerrados.find(current.st) != Cerrados.end()){
				Abiertos.pop();
				current=Abiertos.top();
			}
		}
	}

	if(current.st.bikini||current.st.zapatillas)
		cout << "Se tiene uno de las vestimentas " << endl;

  cout << "Terminada la busqueda\n";

	if (current.st.fila == destino.fila and current.st.columna == destino.columna){
		cout << "Cargando el plan\n";
		plan = current.secuencia;
		cout << "Longitud del plan: " << plan.size() << endl;
		PintaPlan(plan);
		// ver el plan en el mapa
		VisualizaPlan(origen, plan);
		return true;
	}
	else {
		cout << "No encontrado plan\n";
	}


	return false;
}

//Funciones y estructuras necesarias para realizar el algoritmo A*

struct nodoA_estrella{
	estado st;
	list<Action> secuencia;
	//g--> no se incluye, pues se reutilizará el parámetro coste de st
	//h--> estimación del costo desde el nodo actual hasta el objetivo
	//f-->g+h
	int f, h;
};

int heuristica_A_estrella(const estado actual, const estado destino){
	int c=0, f=0;

	c=sqrt(pow((actual.columna-destino.columna), 2));
	f=sqrt(pow((actual.fila-destino.fila), 2));

	return c+f;
}

struct comparaNodosA_estrella{
	bool operator()(const nodoA_estrella &a, const nodoA_estrella &b) const{
		return a.f > b.f;
	}
};


//---------------------- Implementación de la busqueda con A*---------------------------
// Implementación de la busqueda con A*. Se ha utilizado como heurística la distancia manhatann. Se ha incluido para ello la biblioteca math.h para hacer el cálculo de valores absolutos.
// Entran los puntos origen y destino y devuelve la
// secuencia de acciones en plan, una lista de acciones.
bool ComportamientoJugador::pathFinding_A_estrella(const estado &origen, const estado &destino, list<Action> &plan){
	//Borro la lista
	cout << "Calculando plan\n";
	plan.clear();
	set<estado,ComparaEstadosCU> Cerrados; // Lista de Cerrados
	priority_queue<nodoA_estrella,vector<nodoA_estrella>, comparaNodosA_estrella> Abiertos;				 // Lista de Abiertos

	nodoA_estrella current;
	current.st = origen;
	current.secuencia.empty();
	current.st.bikini=false;
	current.st.zapatillas=false;
	current.st.coste=0;
	current.h=heuristica_A_estrella(current.st, destino);
	current.f=current.h+current.st.coste;

	Abiertos.push(current);

	while (!Abiertos.empty() and (current.st.fila!=destino.fila or current.st.columna != destino.columna)){
		Abiertos.pop();
		Cerrados.insert(current.st);

		// Generar descendiente de girar a la derecha
		nodoA_estrella hijoTurnR = current;
		hijoTurnR.st.orientacion = (hijoTurnR.st.orientacion+1)%4;
		if (Cerrados.find(hijoTurnR.st) == Cerrados.end()){
			hijoTurnR.secuencia.push_back(actTURN_R);
			hijoTurnR.st.coste+=CalcularCosto(actTURN_R,current.st.bikini,current.st.zapatillas,current.st,mapaResultado);
			hijoTurnR.h=heuristica_A_estrella(hijoTurnR.st, destino);
			hijoTurnR.f=hijoTurnR.h+hijoTurnR.st.coste;
			Abiertos.push(hijoTurnR);

		}

		// Generar descendiente de girar a la izquierda
		nodoA_estrella hijoTurnL = current;
		hijoTurnL.st.orientacion = (hijoTurnL.st.orientacion+3)%4;
		if (Cerrados.find(hijoTurnL.st) == Cerrados.end()){
			hijoTurnL.secuencia.push_back(actTURN_L);
			hijoTurnL.st.coste+=CalcularCosto(actTURN_L,current.st.bikini,current.st.zapatillas,current.st,mapaResultado);
			hijoTurnL.h=heuristica_A_estrella(hijoTurnL.st, destino);
			hijoTurnL.f=hijoTurnL.h+hijoTurnL.st.coste;
			Abiertos.push(hijoTurnL);
		}

		// Generar descendiente de avanzar
		nodoA_estrella hijoForward = current;
		if (!HayObstaculoDelante(hijoForward.st)){
			if (Cerrados.find(hijoForward.st) == Cerrados.end()){
				hijoForward.secuencia.push_back(actFORWARD);
				hijoForward.st.coste+=CalcularCosto(actFORWARD,current.st.bikini,current.st.zapatillas,current.st,mapaResultado);
				hijoForward.h=heuristica_A_estrella(hijoForward.st, destino);
				hijoForward.f=hijoForward.h+hijoForward.st.coste;
				Abiertos.push(hijoForward);
			}
		}

		// Tomo el siguiente valor de la Abiertos
		if (!Abiertos.empty()){
			current = Abiertos.top();

			while(Cerrados.find(current.st) != Cerrados.end()){
				Abiertos.pop();
				current=Abiertos.top();
			}
		}
	}

	if(current.st.bikini||current.st.zapatillas)
		cout << "Se tiene uno de las vestimentas " << endl;

  cout << "Terminada la busqueda\n";

	if (current.st.fila == destino.fila and current.st.columna == destino.columna){
		cout << "Cargando el plan\n";
		plan = current.secuencia;
		cout << "Longitud del plan: " << plan.size() << endl;
		PintaPlan(plan);
		// ver el plan en el mapa
		VisualizaPlan(origen, plan);
		return true;
	}
	else {
		cout << "No encontrado plan\n";
	}

	return false;
}

struct ComparaEstadosCU_Nivel3{
	bool operator()(const estado &a, const estado &n) const{
		if((a.fila > n.fila) or (a.fila == n.fila and a.columna > n.columna) or
	      (a.fila == n.fila and a.columna == n.columna and a.orientacion > n.orientacion) or
		  (a.fila == n.fila and a.columna == n.columna and a.orientacion == n.orientacion and (a.bikini > n.bikini)) or
		  (a.fila == n.fila and a.columna == n.columna and a.orientacion == n.orientacion and a.bikini == n.bikini and a.zapatillas > n.zapatillas) or
		  (a.fila == n.fila and a.columna == n.columna and a.orientacion == n.orientacion and a.bikini == n.bikini and a.zapatillas == n.zapatillas and a.objetivos_visitados[0]>n.objetivos_visitados[0]) or
		  (a.fila == n.fila and a.columna == n.columna and a.orientacion == n.orientacion and a.bikini == n.bikini and a.zapatillas == n.zapatillas and a.objetivos_visitados[0]==n.objetivos_visitados[0] and a.objetivos_visitados[1]>n.objetivos_visitados[1]) or
		  (a.fila == n.fila and a.columna == n.columna and a.orientacion == n.orientacion and a.bikini == n.bikini and a.zapatillas == n.zapatillas and a.objetivos_visitados[0]==n.objetivos_visitados[0] and a.objetivos_visitados[1]==n.objetivos_visitados[1]) and a.objetivos_visitados[2]>n.objetivos_visitados[2]){
			return true;
		}
		else
			return false;
	}
};

//---------------------- Implementación de la busqueda con Costo Uniforme nivel 3---------------------------
// Implementación de la busqueda con Costo Uniforme.
// Entran los puntos origen y destino y devuelve la
// secuencia de acciones en plan, una lista de acciones.
bool ComportamientoJugador::pathFinding_Costo_Uniforme_Nivel3(const estado &origen, const list<estado> &destino, list<Action> &plan) {
	//Borro la lista
	cout << "Calculando plan\n";
	plan.clear();
	set<estado,ComparaEstadosCU_Nivel3> Cerrados; // Lista de Cerrados
	priority_queue<nodo,vector<nodo>, ComparaNodos> Abiertos;				 // Lista de Abiertos
	vector<estado> destinos;

	for(list<estado>::const_iterator it=destino.begin(); it != destino.end(); it++){
		destinos.push_back((*it));		
	}

  nodo current;
	current.st = origen;
	current.secuencia.empty();
	current.st.bikini=false;
	current.st.zapatillas=false;
	current.st.coste=0;

	for(int i=0; i < destino.size(); i++){
		current.st.objetivos_visitados.push_back(false);
	}

	Abiertos.push(current);

  while (!Abiertos.empty() and (!current.st.objetivos_visitados[0] or !current.st.objetivos_visitados[1] or !current.st.objetivos_visitados[2])){
		Abiertos.pop();
		Cerrados.insert(current.st);

		// Generar descendiente de girar a la derecha
		nodo hijoTurnR = current;
		hijoTurnR.st.orientacion = (hijoTurnR.st.orientacion+1)%4;
		if (Cerrados.find(hijoTurnR.st) == Cerrados.end()){
			hijoTurnR.secuencia.push_back(actTURN_R);
			hijoTurnR.st.coste+=CalcularCosto(actTURN_R,current.st.bikini,current.st.zapatillas,current.st,mapaResultado);

			for(int i=0; i < destinos.size();i++){
				if(destinos[i].fila==hijoTurnR.st.fila && destinos[i].columna==hijoTurnR.st.columna){
					hijoTurnR.st.objetivos_visitados[i]=true;
				}
				
			}

			Abiertos.push(hijoTurnR);

		}

		// Generar descendiente de girar a la izquierda
		nodo hijoTurnL = current;
		hijoTurnL.st.orientacion = (hijoTurnL.st.orientacion+3)%4;
		if (Cerrados.find(hijoTurnL.st) == Cerrados.end()){
			hijoTurnL.secuencia.push_back(actTURN_L);
			hijoTurnL.st.coste+=CalcularCosto(actTURN_L,current.st.bikini,current.st.zapatillas,current.st,mapaResultado);

			for(int i=0; i < destinos.size();i++){
				if(destinos[i].fila==hijoTurnL.st.fila && destinos[i].columna==hijoTurnL.st.columna){
					hijoTurnL.st.objetivos_visitados[i]=true;
				}
				
			}

			Abiertos.push(hijoTurnL);
		}

		// Generar descendiente de avanzar
		nodo hijoForward = current;
		if (!HayObstaculoDelante(hijoForward.st)){
			if (Cerrados.find(hijoForward.st) == Cerrados.end()){
				hijoForward.secuencia.push_back(actFORWARD);
				hijoForward.st.coste+=CalcularCosto(actFORWARD,current.st.bikini,current.st.zapatillas,current.st,mapaResultado);

				for(int i=0; i < destinos.size();i++){
					if(destinos[i].fila==hijoForward.st.fila && destinos[i].columna==hijoForward.st.columna){
						hijoForward.st.objetivos_visitados[i]=true;
					}
					
				}

				Abiertos.push(hijoForward);
			}
		}

		// Tomo el siguiente valor de la Abiertos
		if (!Abiertos.empty()){
			current = Abiertos.top();

			while(Cerrados.find(current.st) != Cerrados.end()){
				Abiertos.pop();
				current=Abiertos.top();
			}
		}
	}

	if(current.st.bikini||current.st.zapatillas)
		cout << "Se tiene uno de las vestimentas " << endl;

  cout << "Terminada la busqueda\n";

	if (current.st.objetivos_visitados[0] and current.st.objetivos_visitados[1] and current.st.objetivos_visitados[2]){
		cout << "Cargando el plan\n";
		plan = current.secuencia;
		cout << "Longitud del plan: " << plan.size() << endl;
		PintaPlan(plan);
		// ver el plan en el mapa
		VisualizaPlan(origen, plan);
		return true;
	}
	else {
		cout << "No encontrado plan\n";
	}


	return false;
}

int heuristica_A_estrella_Nivel3(const estado actual, const list<estado> destino){
	vector<int> c;
	vector<int> f;
	int min_col=0;
	int min_fil=0;

	for(list<estado>::const_iterator it=destino.begin(); it != destino.end(); it++){
		c.push_back(sqrt(pow((actual.columna-(*it).columna), 2)));
		f.push_back(sqrt(pow((actual.fila-(*it).fila), 2)));
	}

	min_col=c[0];
	min_fil=f[0];
	for(int i=1; i < c.size(); i++){
		if(c[i]<min_col)
			min_col=c[i];

		if(f[i]<min_fil)
			min_fil=f[i];
	}

	return min_col+min_fil;
}
//---------------------- Implementación de la busqueda con A* nivel 3---------------------------
// Implementación de la busqueda con A*. Se ha utilizado como heurística la distancia manhatann. Se ha incluido para ello la biblioteca math.h para hacer el cálculo de valores absolutos.
// Entran los puntos origen y destino y devuelve la
// secuencia de acciones en plan, una lista de acciones.
bool ComportamientoJugador::pathFinding_A_estrella_Nivel3(const estado &origen, const list<estado> &destino, list<Action> &plan){
	//Borro la lista
	cout << "Calculando plan\n";
	plan.clear();
	set<estado,ComparaEstadosCU_Nivel3> Cerrados; // Lista de Cerrados
	priority_queue<nodoA_estrella,vector<nodoA_estrella>, comparaNodosA_estrella> Abiertos;				 // Lista de Abiertos
	vector<estado> destinos;

	for(list<estado>::const_iterator it=destino.begin(); it != destino.end(); it++){
		destinos.push_back((*it));		
	}

	nodoA_estrella current;
	current.st = origen;
	current.secuencia.empty();
	current.st.bikini=false;
	current.st.zapatillas=false;
	current.st.coste=0;
	current.h=heuristica_A_estrella_Nivel3(current.st, destino);
	current.f=current.h+current.st.coste;

	for(int i=0; i < destino.size(); i++){
		current.st.objetivos_visitados.push_back(false);
	}

	Abiertos.push(current);

	while (!Abiertos.empty() and (!current.st.objetivos_visitados[0] or !current.st.objetivos_visitados[1] or !current.st.objetivos_visitados[2])){
		Abiertos.pop();
		Cerrados.insert(current.st);

		// Generar descendiente de girar a la derecha
		nodoA_estrella hijoTurnR = current;
		hijoTurnR.st.orientacion = (hijoTurnR.st.orientacion+1)%4;
		if (Cerrados.find(hijoTurnR.st) == Cerrados.end()){
			hijoTurnR.secuencia.push_back(actTURN_R);
			hijoTurnR.st.coste+=CalcularCosto(actTURN_R,current.st.bikini,current.st.zapatillas,current.st,mapaResultado);
			hijoTurnR.h=heuristica_A_estrella_Nivel3(hijoTurnR.st, destino);
			hijoTurnR.f=hijoTurnR.h+hijoTurnR.st.coste;

			for(int i=0; i < destinos.size();i++){
				if(destinos[i].fila==hijoTurnR.st.fila && destinos[i].columna==hijoTurnR.st.columna){
					hijoTurnR.st.objetivos_visitados[i]=true;
				}
				
			}

			Abiertos.push(hijoTurnR);

		}

		// Generar descendiente de girar a la izquierda
		nodoA_estrella hijoTurnL = current;
		hijoTurnL.st.orientacion = (hijoTurnL.st.orientacion+3)%4;
		if (Cerrados.find(hijoTurnL.st) == Cerrados.end()){
			hijoTurnL.secuencia.push_back(actTURN_L);
			hijoTurnL.st.coste+=CalcularCosto(actTURN_L,current.st.bikini,current.st.zapatillas,current.st,mapaResultado);
			hijoTurnL.h=heuristica_A_estrella_Nivel3(hijoTurnL.st, destino);
			hijoTurnL.f=hijoTurnL.h+hijoTurnL.st.coste;

			for(int i=0; i < destinos.size();i++){
				if(destinos[i].fila==hijoTurnL.st.fila && destinos[i].columna==hijoTurnL.st.columna){
					hijoTurnL.st.objetivos_visitados[i]=true;
				}
				
			}

			Abiertos.push(hijoTurnL);
		}

		// Generar descendiente de avanzar
		nodoA_estrella hijoForward = current;
		if (!HayObstaculoDelante(hijoForward.st)){
			if (Cerrados.find(hijoForward.st) == Cerrados.end()){
				hijoForward.secuencia.push_back(actFORWARD);
				hijoForward.st.coste+=CalcularCosto(actFORWARD,current.st.bikini,current.st.zapatillas,current.st,mapaResultado);
				hijoForward.h=heuristica_A_estrella_Nivel3(hijoForward.st, destino);
				hijoForward.f=hijoForward.h+hijoForward.st.coste;

				for(int i=0; i < destinos.size();i++){
					if(destinos[i].fila==hijoForward.st.fila && destinos[i].columna==hijoForward.st.columna){
						hijoForward.st.objetivos_visitados[i]=true;
					}
					
				}

				Abiertos.push(hijoForward);
			}
		}

		// Tomo el siguiente valor de la Abiertos
		if (!Abiertos.empty()){
			current = Abiertos.top();

			while(Cerrados.find(current.st) != Cerrados.end()){
				Abiertos.pop();
				current=Abiertos.top();
			}
		}
	}

	if(current.st.bikini||current.st.zapatillas)
		cout << "Se tiene uno de las vestimentas " << endl;

  cout << "Terminada la busqueda\n";

	if (current.st.objetivos_visitados[0] and current.st.objetivos_visitados[1] and current.st.objetivos_visitados[2]){
		cout << "Cargando el plan\n";
		plan = current.secuencia;
		cout << "Longitud del plan: " << plan.size() << endl;
		PintaPlan(plan);
		// ver el plan en el mapa
		VisualizaPlan(origen, plan);
		return true;
	}
	else {
		cout << "No encontrado plan\n";
	}

	return false;
}
