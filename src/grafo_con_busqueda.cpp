#include "grafo_con_busqueda.hpp"


grafo_con_busqueda::grafo_con_busqueda(void){};

grafo_con_busqueda::grafo_con_busqueda(grafo grafo_parametro):
  grafo_(grafo_parametro),
  costes_nodos_provisionales(grafo_parametro.get_numero_nodos(),-1){}


grafo_con_busqueda::~grafo_con_busqueda(){}

void grafo_con_busqueda::busqueda_A_estrella(unsigned int inicial, unsigned int final, std::vector<float> &heuristica, solucion& solucion_){

//----------------------------------------------------------------------------------------------
  std::cout << "Dentro del método busqueda_A_estrella.\n";

  grafo_.write(std::cout);

  for(int i = 0; i < heuristica.size(); i++){
    std::cout << heuristica[i] << "\t";
  }

  std::cout << "\n";

//----------------------------------------------------------------------------------------------



  //trabajamos con indices de 0 a n-1
  inicial--; final--;

  //Creamos nodo inicial
  nodo_arbol* nodo_seleccionado = new nodo_arbol(inicial, nullptr, 0, 0);



  solucion_.camino.push_back(inicial+1);
  hojas.push_back(inicial);


  //--ITERACIONES DEL ALGORITMO

  while(nodo_seleccionado->get_ID() != final){

    nodo_seleccionado->set_visitado(true);
    //eliminar nodo seleccionado

    //Buscamos sus sucesores. Recorremos el vector correspondiente de la matriz de
    //incidencia y vamos metiendo los hijos en el vector hojas.
    std::vector<std::pair<unsigned int, double> > data_nodo = grafo_.get_data(nodo_seleccionado->get_ID());

    for(int i = 0; i < data_nodo.size() ; i++){

      //IF ESTÁN EN EL CAMINO, NO METER
      //IF HAY UN COSTE MENOR, NO METER
      hojas.push_back(data_nodo[i].first);

    }

  }
}
