#include "grafo_con_busqueda.hpp"


grafo_con_busqueda::grafo_con_busqueda(void){};

grafo_con_busqueda::grafo_con_busqueda(grafo grafo_parametro):
  grafo_(grafo_parametro),
  costes_nodos_provisionales(grafo_parametro.get_numero_nodos(),nullptr){}


grafo_con_busqueda::~grafo_con_busqueda(){}






//Método principal del programa. Búsqueda A estrella

void grafo_con_busqueda::busqueda_A_estrella(unsigned int inicial, unsigned int final, std::vector<float> &heuristica, solucion& solucion_){

  inicial--; final-- ; //trabajamos con indices de 0 a n-1

  nodo_arbol* nodo_seleccionado = generar(inicial,nullptr, 0, 0); //Nodo inicial
  std::pair< std::list<nodo_arbol*>::iterator ,float> coste_minimo; //Estructura para la selección de nodo a analizar

  costes_nodos_provisionales[inicial] = nodo_seleccionado;

  //--ITERACIONES DEL ALGORITMO--------------------------------------

  while(nodo_seleccionado->get_ID() != final){

    coste_minimo.second = FLT_MAX;
    std::vector<std::pair<unsigned int, double> > data_nodo = grafo_.get_data(nodo_seleccionado->get_ID());

    //Insertamos los nodos necesarios en esta iteración
    for(int i = 0; i < data_nodo.size() ; i++){

      if(!ya_insertado_en_rama(nodo_seleccionado, data_nodo[i].first)){

        //MEJORA: ----IF HAY UN COSTE MENOR, NO METER------------------
        nodo_arbol* dummy = generar(data_nodo[i].first, nodo_seleccionado,
                                   (nodo_seleccionado->get_coste() + data_nodo[i].second), nodo_seleccionado->get_profundidad()+1);

        hojas.push_back(dummy);

        costes_nodos_provisionales[data_nodo[i].first] = dummy ;
      }
    }

    //Buscamos siguiente nodo a analizar
    for(std::list<nodo_arbol*>::iterator i = hojas.begin(); i != hojas.end(); i++){

      float tmp = (*i)->get_coste() + heuristica[(*i)->get_ID()];

      if( tmp < coste_minimo.second){
        coste_minimo.first = i;
        coste_minimo.second = tmp;
      }
    }

    nodo_seleccionado = (*coste_minimo.first);
    hojas.erase(coste_minimo.first);


  }

}





//MÉTODOS PRIVADOS-------------------------------------

bool grafo_con_busqueda::ya_insertado_en_rama (nodo_arbol* nodo_padre, int ID){

  if(nodo_padre == nullptr)
    return false;

  if(nodo_padre->get_ID() == ID)
    return true;

  ya_insertado_en_rama(nodo_padre->get_padre(),ID);
}



nodo_arbol* grafo_con_busqueda::generar(unsigned int ID_, nodo_arbol* padre_, float coste_, int profundidad_){

  return(new nodo_arbol(ID_,padre_,coste_,profundidad_));

}
