//Clase que representa un grafo con la búsqueda A* implementada


#pragma once

#include <vector>
#include <iomanip>
#include <list>

#include "nodo_arbol.hpp"
#include "grafo.hpp"


//------STRUCT QUE ALMACENA UNA SOLUCIÓN DE LA BÚSQUEDA


struct solucion{

  unsigned int coste;
  std::vector<unsigned int> camino;
  unsigned int generados;
  unsigned int inspeccionados;

};


//------------------------------------------------------

class grafo_con_busqueda{

  private:

    grafo grafo_;

    std::list<nodo_arbol*> hojas;
    std::vector<nodo_arbol*> generados;

    unsigned int inspeccionados;


    bool ya_insertado_en_rama(nodo_arbol*, int);
    nodo_arbol* generar(unsigned int, nodo_arbol*, float, int);

  public:

    grafo_con_busqueda(void);
    grafo_con_busqueda(grafo);

    ~grafo_con_busqueda();

    int get_numero_nodos();

    void busqueda_A_estrella(unsigned int, unsigned int, std::vector<float>&, solucion&);

};
