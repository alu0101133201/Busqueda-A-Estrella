/*Sergio Guerra Arencibia
Programa principal. Práctica 01 - IA
*/

#include<iostream>
#include<fstream>
#include"grafo.hpp"

int main(int argc, char* argv[]){

  //Evaluación de parámetros suministrados
  switch(argc){
    case 1:
      std::cerr << "Parámetros inválidos, proporcione el nombre de un fichero grafo\n";
      return(1);
      break;

    case 2:
      break;

    default:
      std::cerr << "Parámetros inválidos, proporcione el nombre de un fichero grafo\n";
      return(2);
      break;
  }


  std::ifstream fichero(argv[1]);

  if(fichero.is_open()){

    grafo grafo_leido(fichero);
    grafo_leido.write(std::cout);

  }
  else{
    std::cerr << "Error abriendo el fichero\n";
    return(3);
  }

 return(0);
}
