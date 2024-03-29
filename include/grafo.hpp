//Clase que almacena un grafo mediante su matriz de adyacencia
#pragma once

#include<vector>
#include<iostream>
#include<utility>
#include<fstream>

class grafo{

   private:

      std::vector<std::vector<std::pair<unsigned int, double> > > matriz;
      unsigned int numero_nodos;
      unsigned int numero_aristas;

      //Método privado que introduce el dato en la posicion recibida y en su inversa
      void meter_valor(unsigned int, unsigned int, double);

   public:

     grafo(void);
     grafo(std::ifstream&);
     grafo(const grafo&);

     ~grafo();

     unsigned int get_numero_nodos() const;
     unsigned int get_numero_aristas() const;
     std::vector<std::vector<std::pair<unsigned int,double> > > get_matriz() const;

     std::vector<std::pair<unsigned int, double> > get_data(unsigned int) const;

     std::ostream& write(std::ostream&);

};
