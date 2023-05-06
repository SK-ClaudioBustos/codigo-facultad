#include "nacional.h"

Nacional::Nacional(float precio, char *nombre)
{
    this->precio = precio;
    this->nombre = nombre;
}

float Nacional::precioAjustado()
{
    return this->precio + (this->precio * 0.10);
}

void Nacional::mostrar()
{
    cout<<"Precio: "<< this->precio<<" Precio Ajustado: "<< precioAjustado()<<endl;
}
