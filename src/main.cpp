/*Sergio Guerra Arencibia
Programa principal. Práctica 01 - IA
*/

#include<iostream>
#include<fstream>

#include "grafo.hpp"
#include "grafo_con_busqueda.hpp"


void leer_heuristica(std::vector<float>& datos_heuristica, std::ifstream& fichero_heuristica){

  int nodos;
  float tmp;

  fichero_heuristica >> nodos;
  datos_heuristica.resize(nodos);

  for(int i = 0; i < nodos; i++){

    fichero_heuristica >> tmp;
    datos_heuristica[i] = tmp;
  }

}


int main(int argc, char* argv[]){

  //Evaluación de parámetros suministrados
  switch(argc){

    case (1 || 2):
      std::cerr << "Parámetros inválidos, proporcione el nombre de un fichero grafo\n";
      return(1);
      break;

    case 3:
      break;

    default:
      std::cerr << "Parámetros inválidos, proporcione el nombre de un fichero grafo\n";
      return(2);
      break;
  }


  std::ifstream fichero_grafo(argv[1]);
  std::ifstream fichero_heuristica(argv[2]);

  if(fichero_grafo.is_open() && fichero_heuristica.is_open()){


    std::cout <<  "--PRÁCTICA 01 BÚSQUEDA A ESTRELLA - IA\n Sergio Guerra Arencibia\n";

    std::vector<float> heuristica;
    solucion solucion_;

    grafo grafo_leido(fichero_grafo);
    leer_heuristica(heuristica, fichero_heuristica);

    grafo_con_busqueda prueba(grafo_leido);


    prueba.busqueda_A_estrella(1,3,heuristica,solucion_);












  }
  else{
    std::cerr << "Error abriendo ficheros\n";
    return(3);
  }

 return(0);
}
