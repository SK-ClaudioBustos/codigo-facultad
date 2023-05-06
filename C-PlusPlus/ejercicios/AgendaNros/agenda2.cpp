#include "agenda2.h"

Agenda2::Agenda2()
{

}

void Agenda2::setContacto(Contacto nuevo)
{
    this->contactos.push_back(nuevo);
}

long Agenda2::buscarContacto(std::string nc)
{
    long nro = 0;
    for(auto i = this->contactos.begin(); i != this->contactos.end(); ++i)
        if(nc == i->getN())
           nro = i->getT();
    return nro;
}
