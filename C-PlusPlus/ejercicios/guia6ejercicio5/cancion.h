#ifndef CANCION_H
#define CANCION_H
#include "autor.h"

class cancion
{
private:
    char * nombre;
    int duracion = 0;
    autor * unAutor;
public:
    cancion(char * nombre,int duracion,autor * unAutor);
    char * getNombre();
    char * getAutor();
};

#endif // CANCION_H
