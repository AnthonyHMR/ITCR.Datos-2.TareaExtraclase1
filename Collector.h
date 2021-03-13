#ifndef ITCR_DATOS_2_TAREAEXTRACLASE1_COLLECTOR_H
#define ITCR_DATOS_2_TAREAEXTRACLASE1_COLLECTOR_H

#include "ListaEnlazada.h"
#include "Nodo.h"
#include <string>

using namespace std;

class ListaEnlazada;
class Nodo;

class Collector {
public:
    Collector();
    ~Collector();
    bool isEmpty() const;
    void saveAddress(Nodo *dt);
    Nodo* getAddress();
    void printAddresses();
private:
    Nodo* header;
    Nodo* trailer;

    friend class ListaEnlazada;
};


#endif //ITCR_DATOS_2_TAREAEXTRACLASE1_COLLECTOR_H
