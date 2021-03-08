#ifndef ITCR_DATOS_2_TAREAEXTRACLASE1_NODO_H
#define ITCR_DATOS_2_TAREAEXTRACLASE1_NODO_H

#include "ListaEnlazada.h"

class ListaEnlazada;

class Nodo {
private:
    int data;
    Nodo *prev;
    Nodo *next;

    friend class ListaEnlazada;
};

#endif //ITCR_DATOS_2_TAREAEXTRACLASE1_NODO_H
