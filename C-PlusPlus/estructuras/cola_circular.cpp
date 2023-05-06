#include "cola_circular.h"
#include <iostream>

cola_circular::cola_circular()
{
    this->cc.fondo = 0;
    this->cc.frente = 0;
    this->cc.llena = false;
    this->cc.vacia = true;
}

int cola_circular::setColaCircular(int dato)
{
    this->cc.vacia = false;

    if(this->cc.llena)
        return 10;

    this->cc.datos[this->cc.fondo] = dato;
    this->cc.cant_elementos++;

    if(this->cc.fondo == MAX-1)
        this->cc.fondo = 0;
    else
        this->cc.fondo++;

    if(this->cc.fondo == this->cc.frente)
        this->cc.llena = true;

    return 0;
}

int cola_circular::getColaCircular(int &dato)
{
    this->cc.llena = false;

    if(this->cc.vacia)
        return 10;

    dato = this->cc.datos[this->cc.frente];
    this->cc.cant_elementos--;

    if(this->cc.frente == MAX-1)
        this->cc.frente = 0;
    else
        this->cc.frente++;

    if(this->cc.frente == this->cc.fondo)
        this->cc.vacia = true;

    return 0;
}

void cola_circular::showColaCircular()
{   int dato = 0;
    while(this->getColaCircular(dato) != 10){
         std::cout<<dato<<" ";
    }
    std::cout<<std::endl;
    if(this->getColaCircular(dato) == 10)
        std::cout<<"YA SE MOSTRARON TODOS LOS DATOS"<<std::endl;
}
