#ifndef CATALOGO_H
#define CATALOGO_H
#include "disco.h"

class catalogo
{
private:
    disco ** discos;
    char * nombre;
    char * propietario;
    int cant = 0;
public:
    catalogo(char * nombre,char * propietario);
    void setDisco(disco * nuevo);
    void eliminar(char * nombreD);
    void eliminarDisco(int posicion);
    void showDiscos();
};

#endif // CATALOGO_H
