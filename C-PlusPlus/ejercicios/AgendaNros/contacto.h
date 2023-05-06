#ifndef CONTACTO_H
#define CONTACTO_H
#include <iostream>

class Contacto
{
private:
    std::string nombreCompleto;
    long telefono;
public:
    Contacto();
    void setTelefono(long t);
    void setNombre(std::string nc);
    std::string getN(){return nombreCompleto;}
    long getT(){return telefono;}
};
#endif // CONTACTO_H
