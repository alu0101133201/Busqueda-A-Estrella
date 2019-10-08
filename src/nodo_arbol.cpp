//Implementación de los métodos de la clase nodo_arbols_contiguos

#include "nodo_arbol.hpp"

//Constructores
nodo_arbol::nodo_arbol(void){}

nodo_arbol::nodo_arbol(unsigned int id):
  ID(id)
  {}

nodo_arbol::nodo_arbol(unsigned int id, nodo_arbol* padre_, unsigned int coste_,unsigned int profundidad_, float heuristica_):
  ID(id),
  padre(padre_),
  coste(coste),
  profundidad(profundidad_),
  heuristica(heuristica_){}

//Destructor
nodo_arbol::~nodo_arbol(){}

//------------MÉTODOS PÚBLICOS----------------

//getters-------

unsigned int nodo_arbol::get_ID(void){
    return(ID);
}

nodo_arbol* nodo_arbol::get_padre(void){
  return(padre);
}

unsigned int nodo_arbol::get_coste(void){
  return(coste);
}

unsigned int nodo_arbol::get_profundidad(void){
  return(profundidad);
}

float nodo_arbol::get_heuristica(void){
  return(heuristica);
}

//setters--------

void nodo_arbol::set_ID(unsigned int id){
  ID=id;
}

void nodo_arbol::set_padre(nodo_arbol* padre_){
  padre = padre_;
}

void nodo_arbol::set_coste(unsigned int coste_){
  coste = coste_;
}

void nodo_arbol::set_profundidad(unsigned int profundidad_){
  profundidad = profundidad_;
}

void nodo_arbol::set_heuristica(float heuristica_){
  heuristica = heuristica_;
}
