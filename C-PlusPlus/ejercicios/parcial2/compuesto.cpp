#include "compuesto.h"

Compuesto::Compuesto(double p, char *nombre):Producto(p,nombre)
{
    this->cant = 0;
}

void Compuesto::setP(Producto *nuevo)
{
    if(cant != 10){
        this->arrayProductos[this->cant] = nuevo;
        this->cant++;
    }
}

void Compuesto::sumarPrecios()
{
    double acumulador = 0.0;
    for(int i = 0;i < this->cant;i++)
        acumulador += this->arrayProductos[i]->getP();
    this->precio = acumulador;
}

void Compuesto::setAumento()
{
    for(int i = 0;i <this->cant ;i++)
        this->arrayProductos[i]->setAumento();
}

char * Compuesto::generarCodigo()
{
    cout << "\tMostrando productos de " << this->nombre << endl;
    for(int i = 0;i < this->cant;i++)
       cout << this->arrayProductos[i]->generarCodigo() << endl;

}
