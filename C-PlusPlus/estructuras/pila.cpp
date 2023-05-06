#include "pila.h"

pila::pila()
{

}

void pila::setPila(int dato)
{
    NP * nuevo = new NP;
    nuevo->dato = dato;
    nuevo->link = this->Pila;
    this->Pila = nuevo;
}

int pila::getPila()
{
    int dato = this->Pila->dato;
    NP * aux = this->Pila;
    Pila = Pila->link;
    delete aux;
    return dato;
}

bool pila::emptyPila()
{
    return this->Pila == NULL;
}

void pila::showPila()
{
    while(!this->emptyPila()){
        std::cout<<this->getPila()<<" ";
    }
    std::cout<<std::endl;
}
