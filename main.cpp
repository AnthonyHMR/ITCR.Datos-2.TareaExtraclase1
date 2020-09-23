#include <iostream>

using namespace std;

class Nodo {
private:
    int data;
    Nodo *prev;
    Nodo *next;

    friend class listaDoble;
};

class listaDoble{
public:
    listaDoble();
    ~listaDoble();
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
};

listaDoble::listaDoble(){
    header = new Nodo;
    trailer = new Nodo;
    header->next = trailer;
    trailer->prev = header;
    header->prev = NULL;
    trailer->next = NULL;
}
int listaDoble::getFront() const{
    return header->next->data;
}
int listaDoble::getBack() const{
    return trailer->prev->data;
}
void listaDoble::addFront(int dt){
    Nodo *nd = new Nodo;
    nd->data = dt;
    nd->prev = header;
    nd->next = header->next;

    header->next->prev = nd;
    header->next = nd;

}
void listaDoble::addBack(int dt){
    Nodo *nd = new Nodo;
    nd->data = dt;
    nd->prev = trailer->prev;
    nd->next = trailer;

    trailer->prev->next = nd;
    trailer->prev=nd;
}
void listaDoble::removeFront(){
    Nodo *nd = header->next->next;

    delete header->next;

    header->next = nd;
    nd->prev = header;
}
void listaDoble::removeBack(){
    Nodo *nd = trailer->prev->prev;

    delete trailer->prev;

    trailer->prev = nd;
    nd->next = trailer;
}
void listaDoble::printReverse(){
    Nodo *nd = trailer->prev;

    while(nd != header){
        cout << nd->data << " ";
        nd = nd->prev;
    }
}
void listaDoble::printForward(){
    Nodo *nd = header->next;

    while(nd != trailer){
        cout << nd->data << " ";
        nd = nd->next;
    }
}
listaDoble::~listaDoble(){
    while(header->next!=trailer){
        removeFront();
    }

    delete header;
    delete trailer;
}

int main() {

    listaDoble l1;
    l1.addFront(5);
    l1.addFront(25);
    l1.addFront(3);
    l1.addFront(80);
    l1.addBack(21);
    l1.addBack(34);

    l1.printForward();

    return 0;
}
