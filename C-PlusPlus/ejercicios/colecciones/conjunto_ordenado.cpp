#include "conjunto_ordenado.h"

Conjunto_Ordenado::Conjunto_Ordenado()
{

}

bool Conjunto_Ordenado::agregarOrdenado(int a)
{
    if (this->contiene(a)) return false;

    nodo * actual = this->puntero;
    nodo * anterior = NULL;
    nodo * nuevo = new nodo;
    nuevo->dato = a;
    while(actual != NULL && actual->dato<a){
         anterior = actual;
         actual = actual->sig;
    }
    if(anterior == NULL){
         nuevo->sig = this->puntero;
         this->puntero = nuevo;
    }
    else{
         anterior->sig = nuevo;
         nuevo->sig = actual;
    }
    this->cant++;
    return true;
}
