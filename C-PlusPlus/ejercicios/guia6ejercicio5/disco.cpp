#include "disco.h"
#include <string.h>
#include <iostream>
disco::disco(char *nombre, char * genero, int añoL)
{
    strcpy(this->nombre,nombre);
    strcpy(this->genero,genero);
    this->añoL = añoL;
}

void disco::setC(cancion *nueva)
{
    cancion ** aux = new cancion*[this->cant+1];
    for(int i = 0; i<this->cant;i++)
        aux[i] = this->canciones[i];
    aux[this->cant] = nueva;
    this->canciones = aux;
    this->cant++;
}

char *disco::getNombre()
{
    return this->nombre;
}

void disco::showSongs()
{
   std::cout<< "Nombre Disco: " << this->nombre << std::endl;
   std::cout<< "Genero: " << this->genero << std::endl;
   std::cout<< "Canciones: " << std::endl;
   for(int i = 0; i<this->cant;i++){
       std::cout<< "Nombre autor: " << this->canciones[i]->getAutor() <<" - ";
       std::cout<< "Nombre cancion: " << this->canciones[i]->getNombre() << std::endl;
   }
   std::cout<<std::endl<<std::endl;
}
