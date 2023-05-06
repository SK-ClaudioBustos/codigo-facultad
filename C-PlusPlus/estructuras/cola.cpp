#include "cola.h"

cola::cola()
{

}

void cola::setCola(int dato)
{
    NC * nuevo = new NC;
    nuevo->dato = dato;
    nuevo->link = NULL;
    if(this->fondo != NULL){
        this->fondo->link = nuevo;
    }
    this->fondo = nuevo;
    if(this->frente == NULL){
        this->frente = nuevo ;
    }
}

int cola::getCola()
{
    int dato = this->frente->dato;
    NC * aux = this->frente;
    this->frente = this->frente->link;
    delete aux;
    if(frente == NULL ){
        fondo = NULL;
    }
    return dato;
}

bool cola::emptyCola()
{
    return this->frente == NULL;
}

void cola::showCola()
{
    while(!this->emptyCola()){
        std::cout<<this->getCola()<<" ";
    }
   std::cout<<std::endl;
}
