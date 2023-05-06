#ifndef INTERNACIONAL_H
#define INTERNACIONAL_H
#include "producto.h"
#include <string.h>
#include <ctype.h>
class Internacional: public Producto
{
private:
    int porcentaje;
public:
    Internacional(double p,char * nombre);
    void setPorcentaje(int porcentaje);
    void setAumento();
};

#endif // INTERNACIONAL_H
