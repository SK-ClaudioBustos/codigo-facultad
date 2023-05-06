#include "lista_circular.h"

lista_circular::lista_circular()
{

}

void lista_circular::setListaCircular(int dato)
{
    NLC * nuevo = new NLC;
    nuevo->dato = dato;
    nuevo->link = this->lc;
    this->lc = nuevo;
}

void lista_circular::showListaCircular()
{
    NLC * aux = this->lc;
    while(aux->link != this->lc){
        std::cout<<aux->dato<<"  ";
        aux = aux->link;
    }
    std::cout<<std::endl;
}
