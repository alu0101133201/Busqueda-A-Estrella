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

void inicializar_solucion(solucion& solucion_){
  solucion_.coste = 0;
}



int main(int argc, char* argv[]){

  //Evaluación de parámetros suministrados
  switch(argc){

    case (1 || 2):
      std::cerr << "Parámetros inválidos, proporcione el nombre de un fichero grafo y heurística\n";
      return(1);
      break;

    case 3:
      break;

    default:
      std::cerr << "Parámetros inválidos, demasiados elementos suministrados\n";
      return(2);
      break;
  }


  std::ifstream fichero_grafo(argv[1]);
  std::ifstream fichero_heuristica(argv[2]);

  if(fichero_grafo.is_open() && fichero_heuristica.is_open()) {


      std::cout << "--PRÁCTICA 01 BÚSQUEDA A ESTRELLA - IA\n Sergio Guerra Arencibia\n";

      std::vector<float> heuristica;
      int opcion;
      solucion solucion_;

      grafo grafo_leido(fichero_grafo);
      leer_heuristica(heuristica, fichero_heuristica);

      grafo_con_busqueda prueba(grafo_leido);
      int inicial, final;

      inicializar_solucion(solucion_);

      std::cout << "Introduzca el nodo inicial y el final:\t";
      std::cin >> inicial >> final;

      if ((inicial > 0 && inicial <= prueba.get_numero_nodos()) && (final > 0 && final <= prueba.get_numero_nodos()))
          prueba.busqueda_A_estrella(1, 9, heuristica, solucion_);
      else
          std::cout << "\nIntroduzca un nodo inicial y final válido\n";

      std::cout << "Introduzca un 1 para realizar otra búsqueda, un 0 para salir:\t";
      std::cin >> opcion;


      while (opcion != 0) {

          inicializar_solucion(solucion_);

          /*  std::cout << "Introduzca el fichero con grafo a analizar:\t";
              std::cout << "Introduzca el fichero con la función heurística:\t";
      */

          std::cout << "Introduzca el nodo inicial y el final:\t";
          std::cin >> inicial >> final;

          if ((inicial > 0 && inicial <= prueba.get_numero_nodos()) &&
              (final > 0 && final <= prueba.get_numero_nodos())) {

              prueba.busqueda_A_estrella(1, 9, heuristica, solucion_);


          } else
              std::cout << "\nIntroduzca un nodo inicial y final válido\n";


          std::cout << "Introduzca un 1 para realizar otra búsqueda, un 0 para salir:\t";
          std::cin >> opcion;
      }
  }


      else{
          std::cerr << "Error abriendo ficheros\n";
          return (3);
      }

 return(0);
}
