#ifndef DISCO_H
#define DISCO_H
#include "cancion.h"

class disco
{
    cancion ** canciones;
    char * nombre;
    int cant = 0;
    char * genero;
    int añoL = 0;
public:
    disco(char * nombre,char * genero,int añoL);
    void setC(cancion * nueva);
    char * getNombre();
    void showSongs();
};

#endif // DISCO_H
