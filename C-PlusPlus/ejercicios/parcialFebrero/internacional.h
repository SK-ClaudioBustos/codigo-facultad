#ifndef INTERNACIONAL_H
#define INTERNACIONAL_H
#include <producto.h>

class Internacional: public Producto
{
private:
    float precioAumento = 0.0;
public:
    Internacional(float precio, char * nom);
    void setAumento(float por){precioAumento = por;}
    float precioAjustado(){return precio + (precio * precioAumento);}
    void mostrar();
};

#endif // INTERNACIONAL_H
