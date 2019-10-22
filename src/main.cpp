/*Sergio Guerra Arencibia
Programa principal. Práctica 01 - IA
*/

#include<iostream>
#include<string>
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
  solucion_.camino.clear();
}





void imprimir_solucion(std::ostream& os, solucion& solucion_){

  os << "Solución de la búsqueda A estrella\nCoste:\t";
  os << solucion_.coste;

  os << "\nCamino:\t";
  for(int i = 0; i < solucion_.camino.size() ; i++)
    os << "(" << solucion_.camino[i] << ") ";

  os << "\n\n";

}

//Función que realiza la búsqueda y carga el resultado en solucion. Devuelve true si no ha habido problemas

bool Realizar_busqueda(std::ifstream& pgrafo,std::ifstream& pheuristica, solucion& solucion_){


    if(pgrafo.is_open() && pheuristica.is_open()) {

        int inicial, final;
        inicializar_solucion(solucion_);

        std::vector<float> heuristica;
        grafo grafo_leido(pgrafo);

       leer_heuristica(heuristica, pheuristica);
       grafo_con_busqueda grafo_A_estrella(grafo_leido);


        std::cout << "Introduzca el nodo inicial y el final:\t";
        std::cin >> inicial >> final;

        if ((inicial > 0 && inicial <= grafo_A_estrella.get_numero_nodos()) && (final > 0 && final <= grafo_A_estrella.get_numero_nodos())){

            grafo_A_estrella.busqueda_A_estrella(inicial, final, heuristica, solucion_);
            return true;
        }
         else
             std::cout << "\nIntroduzca un nodo inicial y final válido\n";
         }
    else{

        std::cerr << "Error abriendo ficheros\n";
        return false;
    }

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

  solucion solucion_;
  int opcion;

  std::cout << "--PRÁCTICA 01 BÚSQUEDA A ESTRELLA - IA\n Sergio Guerra Arencibia\n";

  if (Realizar_busqueda(fichero_grafo,fichero_heuristica,solucion_) )
     imprimir_solucion(std::cout, solucion_);


  fichero_grafo.close();
  fichero_heuristica.close();

    std::cout << "Introduzca un 1 para realizar otra búsqueda, un 0 para salir:\t";
    std::cin >> opcion;

   if(opcion == 0)
       return 0;

   //---------------------------------------------------------------------------------------------------

    std::cout << "\n---FASE DE INTRODUCCIÓN MANUAL DE FICHEROS\n";

    while (opcion != 0) {

        std::string fichero;

        std::cout << "Introduzca el fichero con grafo a analizar:\t";
        std::cin >> fichero;
        fichero_grafo.open(fichero);


        std::cout << "Introduzca el fichero con la función heurística:\t";
        std::cin >> fichero;
        fichero_heuristica.open(fichero);


        Realizar_busqueda(fichero_grafo,fichero_heuristica,solucion_);
         imprimir_solucion(std::cout, solucion_);

        fichero_grafo.close();
        fichero_heuristica.close();


        std::cout << "Introduzca un 1 para realizar otra búsqueda, un 0 para salir:\t";
        std::cin >> opcion;
    }



 return(0);
}
