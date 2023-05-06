#include "pastizal.h"

Pastizal::Pastizal()
{
    this->vida = 10;
    this->contador = 0;
    this->comido = false;
}

void Pastizal::setPosicion(int fila, int columna)
{
    this->fila = fila;
    this->columna = columna;
}

//el contador se utiliza para contar los dias de crecimiento del pastizal
void Pastizal::setContador(int cont)
{
    this->contador = cont;
}

void Pastizal::setEstado(bool est)
{
    this->comido = est;
}

void Pastizal::setVida(int vida)
{
    this->vida = vida;
}

void Pastizal::restarVida()
{
    if(vida >= 0)
        this->vida--;
}

void Pastizal::pastizalComido()
{
    this->vida = 0;
    this->comido = true;
}

bool Pastizal::crecer()
{
    if (this->contador < 5)
        this->contador++;

    if (this->contador == 5){
        this->vida = 10;
        this->contador = 0;
        this->comido = false;
        return true;
    }
    return false;
}

