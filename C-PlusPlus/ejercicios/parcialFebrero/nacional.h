#ifndef NACIONAL_H
#define NACIONAL_H
#include <producto.h>

class Nacional: public Producto
{
public:
    Nacional(float precio,char * nombre);
    float precioAjustado();
    void mostrar();
};

#endif // NACIONAL_H
