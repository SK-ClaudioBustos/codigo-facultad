#include "gestorproducto.h"
#include <iostream>
using namespace std;
GestorProducto::GestorProducto()
{

}

void GestorProducto::setP(Producto *nuevo)
{
    if(this->cantProductos < 50){
        this->productos[this->cantProductos] = nuevo;
        this->cantProductos++;
    }
}

void GestorProducto::mostrarPreciosActuales()
{
    cout << "\tMostrando Productos con precios actuales " << endl;
    for (int i = 0;i < this->cantProductos; i++){
        cout << "Producto [" << this->productos[i]->getN() << "]: " << this->productos[i]->getP() << endl;
    }
    cout << endl;
}

void GestorProducto::ajustarPrecios()
{
    for (int i = 0;i < this->cantProductos; i++){
        this->productos[i]->setAumento();
    }
}

void GestorProducto::mostrarPreciosAjustados()
{
    this->ajustarPrecios();
    cout << "\tMostrando Productos con precios ajustados " << endl;
    for (int i = 0;i < this->cantProductos; i++){
        cout << "Producto [" << this->productos[i]->getN() << "]: " << this->productos[i]->getP() << endl;
    }
    cout << endl;
}

void GestorProducto::mostrarCodigosProductos()
{
    for(int i = 0;i < this->cantProductos ; i++)
        cout << this->productos[i];
}
