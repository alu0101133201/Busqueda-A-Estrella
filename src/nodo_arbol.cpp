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

//getters y setters
  unsigned int nodo_arbol::get_ID(void){
    return(ID);
  }

  void nodo_arbol::set_ID(unsigned int id){
    ID=id;
  }
