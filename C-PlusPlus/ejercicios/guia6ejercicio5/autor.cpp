#include "autor.h"
#include <string.h>

autor::autor()
{

}

void autor::setNom(char *nombre)
{
    strcpy(this->nombre,nombre);
}

void autor::setC(cancion *nueva)
{
    cancion ** aux = new cancion*[this->indice+1];
    for(int i = 0; i<this->indice;i++)
        aux[i] = this->canciones[i];
    aux[this->indice] = nueva;
    this->canciones = aux;
    this->indice++;
}

char *autor::getNombre()
{
    return this->nombre;
}
