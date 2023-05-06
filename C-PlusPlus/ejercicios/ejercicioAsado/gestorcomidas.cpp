#include "gestorcomidas.h"

GestorComidas::GestorComidas()
{

}

double GestorComidas::calcularTotal()
{
    double total = 0;
    for(int i = 0;i < 5; i++){
        total += this->amigos[i].getGasto();
    }
    return total;
}

double GestorComidas::totalPorPersona()
{
    return this->calcularTotal()/5;
}

void GestorComidas::setSaldoPorPersona()
{
    double spp = this->totalPorPersona();
    for(int i = 0; i<5;i++){
        this->amigos[i].calcularSaldo(spp);
    }
}

void GestorComidas::setAmigos(Persona amigos[])
{
    for(int i = 0; i < 5;i++){
        this->amigos[i] = amigos[i];
    }
}

Persona *GestorComidas::getAmigos()
{
    return this->amigos;
}
