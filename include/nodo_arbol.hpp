//Declaración de la clase nodo
//Clase que implementará un nodo de un arbol
#pragma once

#include<iostream>
#include<cfloat>
#include<vector>
#include<utility>

class nodo_arbol{

 private:

    int ID;
    nodo_arbol* padre;
    float coste;
    int profundidad;

  public:

    nodo_arbol(void);
    nodo_arbol(int);
    nodo_arbol(int, nodo_arbol*,float, int);

    ~nodo_arbol();

    int get_ID(void);
    nodo_arbol* get_padre(void);
    float get_coste(void);
    int get_profundidad(void);

    void set_ID(int);
    void set_padre(nodo_arbol*);
    void set_coste(float);
    void set_profundidad(int);

};
