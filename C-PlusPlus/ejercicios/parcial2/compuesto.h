#ifndef COMPUESTO_H
#define COMPUESTO_H
#include "producto.h"

class Compuesto: public Producto
{
private:
    Producto * arrayProductos[10];
    int cant;
public:
    Compuesto(double p,char * nombre);
    void setP(Producto *nuevo);
    void sumarPrecios();
    char * generarCodigo();
    void setAumento();
};

#endif // COMPUESTO_H
