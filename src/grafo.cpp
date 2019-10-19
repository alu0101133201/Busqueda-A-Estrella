#include "grafo.hpp"
#include <iomanip>

grafo::grafo(void){}


grafo::grafo(std::ifstream& file){

  double costo_tmp;
  file >> numero_nodos;

  matriz.resize(numero_nodos);


  for(int i = 0; i < (numero_nodos-1); i++){
    for(int j = i+1 ; j < (numero_nodos); j++){

      file >> costo_tmp;

      if(costo_tmp > 0)
        meter_valor(i,j,costo_tmp);

    }
  }
}


grafo::grafo(const grafo &grafo_a_copiar):
  numero_nodos(grafo_a_copiar.get_numero_nodos()),
  matriz(grafo_a_copiar.get_matriz())
  {}


grafo::~grafo(){};


unsigned int grafo::get_numero_nodos(void) const{
  return numero_nodos;
}

std::vector<std::vector<std::pair<unsigned int, double> > > grafo::get_matriz(void) const{
  return(matriz);
}


std::vector<std::pair<unsigned int, double> > grafo::get_data(unsigned int nodo) const{
  return(matriz[nodo]);
}








std::ostream& grafo::write(std::ostream& os){

  for(int i = 0; i < numero_nodos; i++){

    os << "\n nodo " << i+1 << ":\t";

    for(int j = 0; j < matriz[i].size();j++){

      os << std::setw(5) << " [" << matriz[i][j].first + 1 << "," << matriz[i][j].second << "] " << "\t";

    }
    os << "\n";
  }
  os << "\n";

  return(os);
}

//Métodos privados

void grafo::meter_valor(unsigned int i, unsigned int j, double coste){

  std::pair<unsigned int, double> tmp(j,coste);
  matriz[i].push_back(tmp);

  tmp.first = i;
  matriz[j].push_back(tmp);

}
