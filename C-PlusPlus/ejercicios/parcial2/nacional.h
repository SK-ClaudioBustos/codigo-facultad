#ifndef NACIONAL_H
#define NACIONAL_H
#include "producto.h"

class Nacional: public Producto
{
public:
    Nacional(double p,char * nombre);
    void setAumento();
};

#endif // NACIONAL_H
