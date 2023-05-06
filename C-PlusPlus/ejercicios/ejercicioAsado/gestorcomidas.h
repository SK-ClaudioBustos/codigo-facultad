#ifndef GESTORCOMIDAS_H
#define GESTORCOMIDAS_H
#include "persona.h"


class GestorComidas
{
private:
    Persona amigos[5];
public:
    GestorComidas();
    double calcularTotal();
    double totalPorPersona();
    void setSaldoPorPersona();
    void setAmigos(Persona amigos[5]);
    Persona * getAmigos();
};

#endif // GESTORCOMIDAS_H
