#include "lista.h"

lista::lista()
{

}

void lista::setListaFondo(int dato)
{
    NL * nuevo = new NL;
    nuevo->dato = dato;
    nuevo->link = NULL;
    if(this->Lista == NULL){
        this->Lista = nuevo;
    }
    else{
        NL * aux = this->Lista;
        while (aux->link != NULL) {
            aux = aux->link;
        }
        aux->link = nuevo;
    }
}

void lista::setListaOrdenada(int dato)
{
    NL * nuevo = new NL;
    nuevo->dato = dato;
    NL * actual = this->Lista;  NL * anterior = NULL;
    while (actual != NULL && actual->dato < dato) {
        anterior = actual;
        actual = actual->link;
    }
    if(anterior == NULL){
        nuevo->link = this->Lista;
        this->Lista = nuevo;
    }
    else{
        nuevo->link = actual;
        anterior->link = nuevo;
    }
}

void lista::getLista()
{
    NL * aux = this->Lista;
    while(aux != NULL){
        std::cout<<aux->dato<<" ";
        aux = aux->link;
    }
    std::cout<<std::endl;
}
