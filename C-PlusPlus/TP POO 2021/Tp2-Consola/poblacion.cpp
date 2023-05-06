#include "poblacion.h"

Poblacion::Poblacion()
{
    this->vida = 3;
    this->estado = true;
}

void Poblacion::setPosicionActual(int fila, int columna)
{
    this->fila = fila;
    this->columna = columna;

}

void Poblacion::restarVida()
{
    if(this->vida >= 0)
        this->vida--;
    if(this->vida == 0)
        this->estado = false;
}

void Poblacion::setVida(int v)
{
    this->vida = v;
}

bool Poblacion::getEstado()
{
    return this->estado;
}

