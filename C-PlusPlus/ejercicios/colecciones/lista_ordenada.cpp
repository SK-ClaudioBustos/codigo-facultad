
#include "lista_ordenada.h"

Lista_Ordenada::Lista_Ordenada()
{

}

bool Lista_Ordenada::agregar(int a)
{   nodo * actual = this->puntero;
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
