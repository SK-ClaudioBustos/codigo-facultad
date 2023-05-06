#include "cancion.h"
#include <string.h>
cancion::cancion(char *nombre, int duracion, autor * unAutor)
{
    strcpy(this->nombre,nombre);
    this->duracion = duracion;
    this->unAutor = unAutor;
}

char *cancion::getNombre()
{
    return this->nombre;
}

char *cancion::getAutor()
{
    return this->unAutor->getNombre();
}
