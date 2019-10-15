/*Sergio Guerra Arencibia
Programa principal. Práctica 01 - IA
*/

#include<iostream>
#include<fstream>

#include"grafo.hpp"
#include "grafo_con_busqueda.hpp"


void leer_heuristica(std::vector<float> datos_heuristica, std::ifstream& fichero_heuristica){


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

    std::vector<float> heuristica;

    grafo grafo_leido(fichero_grafo);
    leer_heuristica(heuristica, fichero_heuristica);

    grafo_con_busqueda prueba(grafo_leido);




    grafo_leido.write(std::cout);




















  }
  else{
    std::cerr << "Error abriendo ficheros\n";
    return(3);
  }

 return(0);
}
