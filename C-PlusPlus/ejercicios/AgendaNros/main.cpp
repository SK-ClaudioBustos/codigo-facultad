#include <iostream>
#include "agenda2.h"
using namespace std;
/*
Realice un programa que al igual que una agenda, dado el nombre y apellido de la persona,
retorne su numero de teléfono.Realice en el main que permita probar la agenda.
*/
int main()
{
    Agenda2 unaAgenda;

    Contacto c1;
    c1.setNombre("Claudio Bustos");
    c1.setTelefono(12312456);

    Contacto c2;
    c2.setNombre("Alexis Andrian");
    c2.setTelefono(87637733);

    Contacto c3;
    c3.setNombre("Marcos Miller");
    c3.setTelefono(696969699);

    Contacto c4;
    c4.setNombre("Jeronimo Suquilvide");
    c4.setTelefono(424242422);

    unaAgenda.setContacto(c1);
    unaAgenda.setContacto(c2);
    unaAgenda.setContacto(c3);
    unaAgenda.setContacto(c4);

    cout << unaAgenda.buscarContacto("Claudio Bustos") << endl;
    return 0;
}
