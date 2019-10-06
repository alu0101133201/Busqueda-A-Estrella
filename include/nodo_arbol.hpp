//Declaración de la clase nodo
//Clase que implementará un nodo de un arbol

#include<iostream>
#include<vector>
#include<utility>

class nodo_arbol{

private:

    unsigned int ID;
    nodo_arbol* padre;
    unsigned int coste;
    unsigned int profundidad;
    float heuristica;

  public:

    nodo_arbol(void);
    nodo_arbol(unsigned int);
    nodo_arbol(unsigned int, nodo_arbol*,unsigned int, unsigned int, float);

    ~nodo_arbol();

    unsigned int get_ID(void);
    nodo_arbol* get_padre(void);
    unsigned int get_coste(void);
    unsigned int get_profundida(void);
    float get_heuristica(void);


    void set_ID(unsigned int);
    void set_padre(nodo_arbol*);
    void set_coste(unsigned int);
    void set_profundida(unsigned int);
    void set_heuristica(float);


};
