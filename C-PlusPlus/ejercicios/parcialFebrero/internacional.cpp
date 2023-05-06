#include "internacional.h"

Internacional::Internacional(float precio, char * nom)
{
    this->precio = precio;
    nombre = nom;
}

void Internacional::mostrar()
{
    cout<<"Precio: "<< this->precio<<" Precio Ajustado: "<< precioAjustado()<<endl;
}
