#include "producto.h"
#include <string.h>
#include <ctype.h>
Producto::Producto(double precio, char *  nombre)
{
    this->precio = precio;
    this->nombre = nombre;
}

char *  Producto::generarCodigo()
{   char * aux;
    strncpy(aux,this->nombre,3);
    aux[3] = '\0';
    int i = 0;
    while(aux[i]){
        aux[i] = tolower(aux[i]);
    }
    return aux;
}
