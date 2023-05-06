#include "pila.h"

Pila::Pila()
{

}

void Pila::push(int n)
{
    nodo * nuevo = new nodo;
    nuevo->dato = n;
    nuevo->sig = this->puntero;
    this->puntero = nuevo;

}

int Pila::pop()
{
    int v = this->puntero->dato;
    nodo * aux = this->puntero;
    this->puntero = this->puntero->sig;
    delete aux;
    return v;
}

bool Pila::isEmpty()
{
    return this->puntero == NULL;
}
