#ifndef COMPUESTO_H
#define COMPUESTO_H
#include <producto.h>
#include <vector>

class Compuesto: public Producto
{
private:
    vector<Producto*> conjuntoP;
public:
    Compuesto(char * nombre);
    float precioAjustado();
    void setProducto(Producto *nuevo);
    void mostrar();
};

#endif // COMPUESTO_H
