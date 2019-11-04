#include "grafo_con_busqueda.hpp"


grafo_con_busqueda::grafo_con_busqueda(void){};

grafo_con_busqueda::grafo_con_busqueda(grafo grafo_parametro):
  grafo_(grafo_parametro){}


grafo_con_busqueda::~grafo_con_busqueda(){

    //Eliminamos todos los nodos. Sus referencias se encuentran en la estructura generados
    for(int i = 0; i < generados.size(); i++)
        delete generados[i];


}



int grafo_con_busqueda::get_numero_nodos(void){
  return grafo_.get_numero_nodos();
}



//Método principal del programa. Búsqueda A estrella

void grafo_con_busqueda::busqueda_A_estrella(unsigned int inicial, unsigned int final, std::vector<float> &heuristica, solucion& solucion_){

  inicial--; final-- ; //trabajamos con indices de 0 a n-1
  inspeccionados = 0;

  nodo_arbol* nodo_seleccionado = generar(inicial,nullptr, 0, 0); //Nodo inicial
  std::pair< std::list<nodo_arbol*>::iterator ,float> coste_minimo; //Estructura para la selección de nodo a analizar

  generados.push_back(nodo_seleccionado);

  //--ITERACIONES DEL ALGORITMO--------------------------------------

  while(nodo_seleccionado->get_ID() != final) {

      coste_minimo.second = FLT_MAX;
      std::vector<std::pair<unsigned int, double> > data_nodo = grafo_.get_data(nodo_seleccionado->get_ID());

      inspeccionados++;

      //Insertamos los nodos necesarios en esta iteración
      for (int i = 0; i < data_nodo.size(); i++) {

          if (!ya_insertado_en_rama(nodo_seleccionado, data_nodo[i].first)) {

              nodo_arbol *dummy = generar(data_nodo[i].first, nodo_seleccionado,
                                          (nodo_seleccionado->get_coste() + data_nodo[i].second),
                                          nodo_seleccionado->get_profundidad() + 1);

              hojas.push_back(dummy);

              generados.push_back(dummy);
          }
      }


      //Buscamos siguiente nodo a analizar
      for (std::list<nodo_arbol *>::iterator i = hojas.begin(); i != hojas.end(); i++) {

          float tmp = (*i)->get_coste() + heuristica[(*i)->get_ID()];

          if (tmp < coste_minimo.second) {
              coste_minimo.first = i;
              coste_minimo.second = tmp;
          }
      }


      nodo_seleccionado = (*coste_minimo.first);
      hojas.erase(coste_minimo.first);

  }
  //Rellenamos la estructura solución

  solucion_.coste = nodo_seleccionado->get_coste();
  solucion_.generados = generados.size();
  solucion_.inspeccionados = inspeccionados;
  solucion_.camino.resize(nodo_seleccionado->get_profundidad()+1);

  for(nodo_arbol* i = nodo_seleccionado; i != nullptr; i = i->get_padre())
      solucion_.camino[i->get_profundidad()] = i->get_ID()+1;

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
