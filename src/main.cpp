/*Sergio Guerra Arencibia
Programa principal. Práctica 01 - IA
*/

#include<iostream>
#include<string>
#include<fstream>
#include<chrono>
#include<iomanip>

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

  os << "Solución de la búsqueda A estrella\n\033[1;33mCoste:\033[0m\t";
  os << solucion_.coste;
  os << ".  \033[1;33mNodos generados:\033[0m\t " << solucion_.generados;
  os << ".  \033[1;33mNodos inspeccionados:\033[0m\t" << solucion_.inspeccionados;

  os << "\nCamino:\033[1;32m\t";
  for(int i = 0; i < solucion_.camino.size() ; i++)
    os << "(" << solucion_.camino[i] << ") ";

  os << "\033[0m\n\n";

}

bool existe_fichero(std::string& filename){
    std::ifstream fichero(filename.c_str());
    return(fichero.good());
}


void Rellenar_tabla(solucion& solucion_,std::string &nombre_grafo, grafo& grafo_, unsigned int inicial, unsigned int final){

    std::string file;

    std::cout << "Introduzca el fichero en el que quiere almacenar la solución:\t";
    std::cin >> file;

    std::ofstream fichero;

    if(!existe_fichero(file)){

        //Creamos fichero
        fichero.open(file);

        fichero << std::setw(10) << "Instancia" << std::setw(5) << "  n" << std::setw(5) << "  m";
        fichero << std::setw(5) << "  v0" << std::setw(5) << "  v1" << "    Camino";
        fichero << std::setw(35) << "\t\tDistancia" << std::setw(15) << "  Nodos generados" << std::setw(15) << "  Nodos inspeccionados\n";

        fichero.close();
    }

    fichero.open(file, std::ios::app);
    fichero  << "\n" << std::setw(10) << nombre_grafo.substr(0,nombre_grafo.length()-4);
    fichero << std::setw(5) << grafo_.get_numero_nodos() << std::setw(5) << grafo_.get_numero_aristas();
    fichero << std::setw(5) << inicial << std::setw(5) << final << "   |";

    int i;

    for(i = 0 ; i < solucion_.camino.size()-1; i++)
        fichero << solucion_.camino[i] << " -> ";
    fichero << solucion_.camino[i] << "|  ";

    fichero << std::setw(15) << solucion_.coste;
    fichero << std::setw(15) << solucion_.generados << std::setw(15) << solucion_.inspeccionados;

}

//Función que realiza la búsqueda y carga el resultado en solucion. Devuelve true si no ha habido problemas

bool Realizar_busqueda(std::ifstream& pgrafo,std::ifstream& pheuristica, solucion& solucion_,std::string &nombre_grafo){


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

            auto start = std::chrono::high_resolution_clock::now();
            grafo_A_estrella.busqueda_A_estrella(inicial, final, heuristica, solucion_);

            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start);

            int almacenar;
            std::cout << "¿Quiere almacenar el resultado?\t";
            std::cin >> almacenar;
            if(almacenar != 0)
                Rellenar_tabla(solucion_, nombre_grafo,grafo_leido, inicial, final);


            std::cout << "\nTiempo de ejecución:\033[1;32m\t" << duration.count() << "\033[0m microsegundos\n\n";

            return true;
        }
         else
             std::cout << "\nIntroduzca un nodo inicial y final válido\n";
             return false;
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

  std::string aux(argv[1]);

  if (Realizar_busqueda(fichero_grafo,fichero_heuristica,solucion_,aux) )
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

        std::string fichero,fichero_h;

        std::cout << "Introduzca el fichero con grafo a analizar:\t";
        std::cin >> fichero;
        fichero_grafo.open(fichero);


        std::cout << "Introduzca el fichero con la función heurística:\t";
        std::cin >> fichero_h;
        fichero_heuristica.open(fichero_h);

        if(Realizar_busqueda(fichero_grafo,fichero_heuristica,solucion_,fichero))
         imprimir_solucion(std::cout, solucion_);

        fichero_grafo.close();
        fichero_heuristica.close();


        std::cout << "Introduzca un 1 para realizar otra búsqueda, un 0 para salir:\t";
        std::cin >> opcion;
    }



 return(0);
}
