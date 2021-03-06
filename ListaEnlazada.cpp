#include <string>
#include <iostream>
#include "ListaEnlazada.h"

using namespace std;

ListaEnlazada::ListaEnlazada(){
    header = new Nodo;
    trailer = new Nodo;
    header->next = trailer;
    trailer->prev = header;
    header->prev = NULL;
    trailer->next = NULL;
    c1 = new Collector;
}

//Obtiene la cabeza de la lista
/**
 *@brief getFront
 */
int ListaEnlazada::getFront() const{
    return header->next->data;
}

//Obtiene la cola de la lista
/**
 *@brief getBack
 */
int ListaEnlazada::getBack() const{
    return trailer->prev->data;
}

//Anade un Nodo al frente de la lista
/**
 *@brief addFront
 *@param dt
 */
void ListaEnlazada::addFront(int dt){
    if (c1->isEmpty()){
        Nodo *nd = new Nodo;
        nd->data = dt;
        nd->prev = header;
        nd->next = header->next;

        header->next->prev = nd;
        header->next = nd;
    }else{
        Nodo *nd = c1->getAddress();
        nd->data = dt;
        nd->prev = header;
        nd->next = header->next;

        header->next->prev = nd;
        header->next = nd;
    }

}

//Anade un nodo atras de la lista
/**
 *@brief addBack
 *@param dt
 */
void ListaEnlazada::addBack(int dt){
    Nodo *nd = new Nodo;
    nd->data = dt;
    nd->prev = trailer->prev;
    nd->next = trailer;

    trailer->prev->next = nd;
    trailer->prev=nd;
}

//Elimina el nodo del frente
/**
 *@brief removeFront
 */
void ListaEnlazada::removeFront(){
    Nodo *nd = header->next->next;

    delete header->next;

    header->next = nd;
    nd->prev = header;
}

//Elimina el nodo de atras y llama la funcion saveAddress() de la clase Collector para guardar la direccion a borrar
/**
 *@brief removeBack
 */
void ListaEnlazada::removeBack(){
    Nodo *nd = trailer->prev->prev;

    c1->saveAddress(trailer->prev);
    c1->printAddresses();

    delete trailer->prev;

    trailer->prev = nd;
    nd->next = trailer;
}

//Imprime la lista al reves
/**
 *@brief printReverse
 */
void ListaEnlazada::printReverse(){
    Nodo *nd = trailer->prev;

    while(nd != header){
        cout << nd->data << " ";
        nd = nd->prev;
    }
}

//Imprime la lista desde el frente
/**
 *@brief printForward
 */
void ListaEnlazada::printForward(){
    Nodo *nd = header->next;

    while(nd != trailer){
        cout << nd->data << " ";
        nd = nd->next;
    }
}


ListaEnlazada::~ListaEnlazada(){
    while(header->next!=trailer){
        removeFront();
    }

    delete header;
    delete trailer;
}

