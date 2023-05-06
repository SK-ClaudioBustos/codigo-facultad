#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <string.h>
#include <ctype.h>
#include <iostream>
using namespace std;
class Producto
{
protected:
    double precio;
    char *  nombre;
public:
    Producto(double precio,char * nombre);
    double getP(){return precio;}
    char * getN(){return nombre;}
    virtual char * generarCodigo();
    virtual void setAumento() = 0;
    friend ostream& operator<<(std::ostream& os,Producto& obj)
    {
        os << obj.generarCodigo();
        return os;
    }
};

#endif // PRODUCTO_H
