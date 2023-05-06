#ifndef AUTOR_H
#define AUTOR_H
#include "cancion.h"

class autor
{
private:
    char * nombre;
    cancion ** canciones;
    int indice;
public:
    autor();
    void setNom(char * nombre);
    void setC(cancion * nueva);
    char * getNombre();
};

#endif // AUTOR_H
