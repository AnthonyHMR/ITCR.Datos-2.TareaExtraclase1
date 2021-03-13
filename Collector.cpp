#include <string>
#include <iostream>
#include "Collector.h"
#include "ListaEnlazada.h"
#include "Nodo.h"

Collector::Collector(){
    header = new Nodo;
    trailer = new Nodo;
    header->next = trailer;
    trailer->prev = header;
    header->prev = NULL;
    trailer->next = NULL;
}

//Revisa si la lista está vacía
/**
 *@brief isEmpty
 *@return bool
 */
bool Collector::isEmpty() const {
    bool empty = true;
    Nodo *nd = header->next;
    while (nd!=trailer) {
        empty = false;
        nd = nd->next;
    }
    if (empty){
        cout << "true" << endl;
        return true;
    }else {
        cout << "false" << endl;
        return false;
    }
}

//Guarda la dirección de memoria borrada
/**
 *@brief saveAddress
 *@param wd
 */
void Collector::saveAddress(Nodo *wd) {
    Nodo *nd = new Nodo;
    nd->word = wd;
    nd->prev = header;
    nd->next = header->next;

    header->next->prev = nd;
    header->next = nd;
}

//Brinda una dirección de memoria en la lista
/**
 *@brief getAddress
 *@return nd2
 */
Nodo* Collector::getAddress() {
    Nodo *nd = trailer->prev->prev;
    Nodo *nd2 = trailer->prev->word;

    delete trailer->prev;

    trailer->prev = nd;
    nd->next = trailer;

    return nd2;
}

//Imprime las direcciones contenidas en la lista
void Collector::printAddresses() {
    Nodo *nd = header->next;

    while(nd != trailer){
        cout << nd->word<< " ";
        nd = nd->next;
    }
}

Collector::~Collector(){
    while(header->next!=trailer){
        Nodo *nd = header->next->next;

        delete header->next;

        header->next = nd;
        nd->prev = header;
    }

    delete header;
    delete trailer;
}

