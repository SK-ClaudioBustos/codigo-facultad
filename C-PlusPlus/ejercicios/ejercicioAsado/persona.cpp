#include "persona.h"
#include "string.h"
Persona::Persona()
{

}

Persona::Persona(char *nombre)
{
    this->nombre = new char[strlen(nombre)];
    strcpy(this->nombre,nombre);
}

double Persona::getGasto()
{
    return this->gasto;
}

double Persona::getSaldo()
{
    return this->saldo;
}

void Persona::incGasto(double gasto)
{
    this->gasto += gasto;
}

void Persona::calcularSaldo(double totalPorPer)
{
    this->saldo = this->gasto - totalPorPer;
}
