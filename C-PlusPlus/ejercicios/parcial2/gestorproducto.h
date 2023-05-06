#ifndef GESTORPRODUCTO_H
#define GESTORPRODUCTO_H
#include "producto.h"

class GestorProducto
{
private:
    Producto * productos[50];
    int cantProductos = 0;
public:
    GestorProducto();
    void setP(Producto * nuevo);
    void mostrarPreciosActuales();
    void ajustarPrecios();
    void mostrarPreciosAjustados();
    void mostrarCodigosProductos();
};

#endif // GESTORPRODUCTO_H
