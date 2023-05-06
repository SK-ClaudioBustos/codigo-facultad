#include "cola.h"

Cola::Cola()
{

}

void Cola::push(int n)
{
    nodo * nuevo = new nodo;
    nuevo->dato = n;
    nuevo->sig = NULL;
    if(this->fondo != NULL)
        this->fondo->sig = nuevo;
    this->fondo = nuevo;
    if(this->frente == NULL)
        this->frente = nuevo;
}

int Cola::pop()
{
    int n = this->frente->dato;
    nodo * aux = this->frente;
    this->frente = this->frente->sig;
    delete aux;
    if(this->frente == NULL)
        this->fondo = NULL;
    return n;
}

bool Cola::isEmpty()
{
    return this->fondo == this->frente;
}
