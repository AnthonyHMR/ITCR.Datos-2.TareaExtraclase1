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

bool Collector::isEmpty() const {
    if (header->next->word==NULL) {
        cout << "true" << endl;
        return true;
    }else {
        cout << "false" << endl;
        return false;
    }
}

void Collector::saveAddress(Nodo *wd) {
    Nodo *nd = new Nodo;
    nd->word = wd;
    nd->prev = header;
    nd->next = header->next;

    header->next->prev = nd;
    header->next = nd;
}

int Collector::setAddress() {
    return 0;
}


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

