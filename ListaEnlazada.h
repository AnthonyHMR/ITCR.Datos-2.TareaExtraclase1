#ifndef ITCR_DATOS_2_TAREAEXTRACLASE1_LISTAENLAZADA_H
#define ITCR_DATOS_2_TAREAEXTRACLASE1_LISTAENLAZADA_H

#include "Nodo.h"
#include "Collector.h"

class Nodo;
class Collector;

class ListaEnlazada{
public:
    ListaEnlazada();
    ~ListaEnlazada();
    bool isEmpty() const;
    int getFront() const;
    int getBack() const;
    void addFront(int dt);
    void addBack(int dt);
    void removeFront();
    void removeBack();
    void printReverse();
    void printForward();
private:
    Nodo *header;
    Nodo *trailer;
    Collector *c1;
};


#endif //ITCR_DATOS_2_TAREAEXTRACLASE1_LISTAENLAZADA_H
