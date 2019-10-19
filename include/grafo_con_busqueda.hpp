//Clase que representa un grafo con la búsqueda A* implementada


#pragma once

#include <vector>

#include "nodo_arbol.hpp"
#include "grafo.hpp"


//------STRUCT QUE ALMACENA UNA SOLUCIÓN DE LA BÚSQUEDA


struct solucion{

  unsigned int coste;
  std::vector<unsigned int> camino;

};


//------------------------------------------------------

class grafo_con_busqueda{

  private:

    grafo grafo_;

    std::vector<unsigned int> hojas;
    //Vector que almacenará los costes mínimos a cada uno de los nodos con el fin de ahorrar meter nodos a los que se han encontrado caminos mejores.
    std::vector<unsigned int> costes_nodos_provisionales;


  public:

    grafo_con_busqueda(void);
    grafo_con_busqueda(grafo);

    ~grafo_con_busqueda();

    void busqueda_A_estrella(unsigned int, unsigned int, std::vector<float>&, solucion&);

};
