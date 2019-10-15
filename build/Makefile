IDIR = ../include
CC=g++
CFLAGS=-I$(IDIR) -std=c++11 -g

ODIR=../src

.PHONY: all

_OBJ = nodo_arbol.o grafo.o  grafo_con_busqueda.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


all: Busqueda-A-Estrella

$(ODIR)/nodo_arbol.o: $(ODIR)/nodo_arbol.cpp $(IDIR)/nodo_arbol.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/grafo.o: $(ODIR)/grafo.cpp $(IDIR)/grafo.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/grafo_con_busqueda.o: $(ODIR)/grafo_con_busqueda.cpp $(IDIR)/grafo_con_busqueda.hpp $(IDIR)/nodo_arbol.hpp $(IDIR)/grafo.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/main.o: $(ODIR)/main.cpp $(IDIR)/grafo_con_busqueda.hpp $(IDIR)/nodo_arbol.hpp $(IDIR)/grafo.hpp
	$(CC) -c -o $@ $< $(CFLAGS)


Busqueda-A-Estrella: $(OBJ)
	$(CC)  -o $@ $^ $(CFLAGS)




.PHONY: clean

clean:
	rm -f $(ODIR)/*.o ./Busqueda_A_Estrella
