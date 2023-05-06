#include "contacto.h"

Contacto::Contacto()
{

}

void Contacto::setTelefono(long t)
{
    this->telefono = t;
}

void Contacto::setNombre(std::string nc)
{
    this->nombreCompleto = nc;
}
