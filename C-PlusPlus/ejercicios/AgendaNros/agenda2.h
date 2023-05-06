#ifndef AGENDA2_H
#define AGENDA2_H
#include <vector>
#include "contacto.h"
class Agenda2
{
private:
    std::vector <Contacto> contactos;
public:
    Agenda2();
    void setContacto(Contacto nuevo);
    long buscarContacto(std::string nc);
};

#endif // AGENDA2_H
