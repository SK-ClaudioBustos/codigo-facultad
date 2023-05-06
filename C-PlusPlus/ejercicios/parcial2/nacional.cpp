#include "nacional.h"

Nacional::Nacional(double p,char * nombre):Producto(p,nombre)
{

}

void Nacional::setAumento()
{
    double aumento = this->precio * 0.10;
    this->precio += aumento;
}

