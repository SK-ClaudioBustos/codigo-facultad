#include "internacional.h"

Internacional::Internacional(double p,char * nombre):Producto(p,nombre)
{

}

void Internacional::setPorcentaje(int porcentaje)
{
    this->porcentaje = porcentaje;
}

void Internacional::setAumento()
{
    double aumento = this->precio *(this->porcentaje/100);
    this->precio += aumento;
}
