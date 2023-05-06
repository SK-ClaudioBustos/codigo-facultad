#include "conjunto.h"

Conjunto::Conjunto()
{

}


bool Conjunto::agregar(int a) {
    if (this->contiene(a)) return false;
    Lista::agregar(a);
}

bool Conjunto::contiene(int a) {
    nodo *aux = this->puntero;
    while (aux!= NULL) {
        if (aux->dato == a) {
            return true;
        }
        aux = aux->sig;
    }
    return false;
}
