#include "catalogo.h"
#include <string.h>
#include <iostream>
catalogo::catalogo(char * nombre,char * propietario)
{
    strcpy(this->nombre,nombre);
    strcpy(this->propietario,propietario);
}

void catalogo::setDisco(disco *nuevo)
{
    disco ** aux = new disco*[this->cant+1];
    for(int i = 0;i<this->cant;i++)
        aux[i] = this->discos[i];
    aux[this->cant] = nuevo;
    this->discos = aux;
    this->cant++;
}

void catalogo::eliminar(char *nombreD)
{
    for(int i = 0;i < this->cant;i++){
        if(this->discos[i]->getNombre() == nombreD)
            this->eliminarDisco(i);
    }
}

void catalogo::eliminarDisco(int posicion)
{

}

void catalogo::showDiscos()
{
    std::cout<< "Mostrando catalogo: " << this->nombre << std::endl;
    std::cout<< "Propietario: " << this->propietario << std::endl;
    for(int i = 0; i<this->cant;i++){
        this->discos[i]->showSongs();
    }
    std::cout<<std::endl<<std::endl;
}
