#ifndef ITCR_DATOS_2_TAREAEXTRACLASE1_NODO_H
#define ITCR_DATOS_2_TAREAEXTRACLASE1_NODO_H

#include "ListaEnlazada.h"
#include "Collector.h"
#include <string>

class ListaEnlazada;
class Collector;

class Nodo {
private:
    int data;
    Nodo *word;
    Nodo *prev;
    Nodo *next;

    friend class ListaEnlazada;
    friend class Collector;
};

#endif //ITCR_DATOS_2_TAREAEXTRACLASE1_NODO_H
