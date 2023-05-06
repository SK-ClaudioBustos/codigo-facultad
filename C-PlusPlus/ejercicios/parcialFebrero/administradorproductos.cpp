#include "administradorproductos.h"

AdministradorProductos::AdministradorProductos()
{

}

void AdministradorProductos::setProducto(Producto *nuevo, int cant)
{
    if(this->contador<=50){
        contador += cant;
        productos.push_back(nuevo);
    }
}

void AdministradorProductos::mostrarProductos()
{
    for(int i = 0; i < (int)productos.size(); ++i)
        productos[i]->mostrar();
}

void AdministradorProductos::mostrarCodigo()
{
    for(int i = 0; i < (int)productos.size(); ++i)
        cout<<productos[i];
}
