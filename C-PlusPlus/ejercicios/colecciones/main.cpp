#include <iostream>
#include "lista.h"
#include "vector.h"
#include "conjunto.h"
#include "lista_ordenada.h"
using namespace std;

int main()
{
    Coleccion * c = new Lista_Ordenada();

    c->agregar(4);
    c->agregar(55);
    c->agregar(43);
    c->agregar(78);
    c->agregar(88);

    for (int i = 0; i<c->getCant(); i++) {
        cout << *c->get(i) << "  ";
    }
    cout << endl;
    return 0;
}
