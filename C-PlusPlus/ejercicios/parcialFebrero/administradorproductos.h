#ifndef ADMINISTRADORPRODUCTOS_H
#define ADMINISTRADORPRODUCTOS_H
#include <producto.h>
#include <vector>

class AdministradorProductos
{
private:
    vector<Producto *> productos;
    int contador = 0;
public:
    AdministradorProductos();
    void setProducto(Producto * nuevo,int cant=1);
    void mostrarProductos();
    void mostrarCodigo();
};

#endif // ADMINISTRADORPRODUCTOS_H
