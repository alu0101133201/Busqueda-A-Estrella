//Implementación de los métodos de la clase nodo_arbols_contiguos

#include "nodo_arbol.hpp"

//Constructores
nodo_arbol::nodo_arbol(void):
  ID(-1),
  padre(nullptr),
  coste(FLT_MAX),
  profundidad(-1){}

nodo_arbol::nodo_arbol(int id):
  ID(id),
  padre(nullptr),
  coste(FLT_MAX),
  profundidad(-1){}

nodo_arbol::nodo_arbol(int id, nodo_arbol* padre_, float coste_,int profundidad_):
  ID(id),
  padre(padre_),
  coste(coste_),
  profundidad(profundidad_){}

//Destructor
nodo_arbol::~nodo_arbol(){}

//------------MÉTODOS PÚBLICOS----------------

//getters-------

int nodo_arbol::get_ID(void){
    return(ID);
}

nodo_arbol* nodo_arbol::get_padre(void){
  return(padre);
}

float nodo_arbol::get_coste(void){
  return(coste);
}

int nodo_arbol::get_profundidad(void){
  return(profundidad);
}


//setters--------

void nodo_arbol::set_ID(int id){
  ID=id;
}

void nodo_arbol::set_padre(nodo_arbol* padre_){
  padre = padre_;
}

void nodo_arbol::set_coste(float coste_){
  coste = coste_;
}

void nodo_arbol::set_profundidad(int profundidad_){
  profundidad = profundidad_;
}
