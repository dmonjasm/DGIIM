#ifndef COMPORTAMIENTOJUGADOR_H
#define COMPORTAMIENTOJUGADOR_H

#include "comportamientos/comportamiento.hpp"

#include <list>
#include <queue>

struct estado {
  int fila;
  int columna;
  int orientacion;
  bool bikini=false;
	bool zapatillas=false;
  int coste=0;
  vector<bool> objetivos_visitados;
};

class ComportamientoJugador : public Comportamiento {
  public:
    ComportamientoJugador(unsigned int size) : Comportamiento(size) {
    }
    ComportamientoJugador(std::vector< std::vector< unsigned char> > mapaR) : Comportamiento(mapaR) {
      hayPlan=false;
    }
    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
    ~ComportamientoJugador(){}

    Action think(Sensores sensores);
    int interact(Action accion, int valor);
    void VisualizaPlan(const estado &st, const list<Action> &plan);
    ComportamientoJugador * clone(){return new ComportamientoJugador(*this);}

  private:
    // Declarar Variables de Estado
    estado actual;
    list<estado> objetivos;
    list<Action> plan;
    bool hayPlan;
    list<estado> cargadores;

    // Métodos privados de la clase
    bool pathFinding(int level, const estado &origen, const list<estado> &destino, list<Action> &plan);
    bool pathFinding_Profundidad(const estado &origen, const estado &destino, list<Action> &plan);
    bool pathFinding_Anchura(const estado &origen, const estado &destino, list<Action> &plan);
    bool pathFinding_Costo_Uniforme(const estado &origen, const estado &destino, list<Action> &plan);
    bool pathFinding_A_estrella(const estado &origen, const estado &destino, list<Action> &plan);
    bool pathFinding_Costo_Uniforme_Nivel3(const estado &origen, const list<estado> &destino, list<Action> &plan);
    bool pathFinding_A_estrella_Nivel3(const estado &origen, const list<estado> &destino, list<Action> &plan);


    void PintaPlan(list<Action> plan);
    bool HayObstaculoDelante(estado &st);
    void muestraMapa(Sensores sensores);
};

#endif
