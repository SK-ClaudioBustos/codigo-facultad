#include "agenda.h"

Agenda::Agenda()
{

}

void Agenda::setPersona(std::string nombreCompleto, long telefono)
{
    this->personas[nombreCompleto] = telefono;
}

long Agenda::getPersona(std::string nombreP)
{
    return this->personas[nombreP];
}
