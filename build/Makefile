IDIR = ../include
CC=g++
CFLAGS=-I$(IDIR) -std=c++11 -g

ODIR=../src

.PHONY: all

_OBJ = nodo_arbol.o grafo.o Arbol.o A_.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


all: Busqueda-A-Estrella

$(ODIR)/nodo_arbol.o: $(ODIR)/nodo_arbol.cpp $(IDIR)/nodo_arbol.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/grafo.o: $(ODIR)/grafo.cpp $(IDIR)/grafo.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/Arbol.o: $(ODIR)/Arbol.cpp $(IDIR)/Arbol.hpp $(IDIR)/nodo_arbol.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/A_.o: $(ODIR)/A_.cpp $(IDIR)/A_.hpp $(IDIR)/Arbol.hpp $(IDIR)/nodo_arbol.hpp $(IDIR)/grafo.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/main.o: $(ODIR)/main.cpp $(IDIR)/A_.hpp $(IDIR)/Arbol.hpp $(IDIR)/nodo_arbol.hpp $(IDIR)/grafo.hpp 
	$(CC) -c -o $@ $< $(CFLAGS)


Busqueda-A-Estrella: $(OBJ)
	$(CC)  -o $@ $^ $(CFLAGS)




.PHONY: clean

clean:
	rm -f $(ODIR)/*.o ./Busqueda_A_Estrella
