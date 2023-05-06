#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <iostream>
#include <string.h>
using namespace std;

class Producto
{
protected:
    float precio = 0.0;
    char * nombre;
public:
    Producto();
    virtual float precioAjustado() = 0;
    virtual void mostrar() = 0;
    float getP(){return precio;}
    friend ostream &operator<<(ostream &os, const Producto * prod){
        os << (char)tolower(prod->nombre[0])<<(char)tolower(prod->nombre[1])<<(char)tolower(prod->nombre[2])<<"\n";
        return os;
    }
};

#endif // PRODUCTO_H
