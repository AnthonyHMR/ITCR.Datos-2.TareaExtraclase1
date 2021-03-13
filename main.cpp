#include <iostream>
#include "ListaEnlazada.h"

using namespace std;

int main() {

    ListaEnlazada l1;
    l1.addFront(5);
    l1.addFront(25);
    l1.addFront(3);
    l1.addFront(80);
    l1.removeBack();
    l1.removeBack();
    l1.removeBack();
    l1.addFront(67);

    l1.printForward();

    return 0;
}
