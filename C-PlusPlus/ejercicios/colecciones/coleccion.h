#ifndef COLECCION_H
#define COLECCION_H

struct nodo {
    int dato;
    nodo *sig;
};

class Coleccion
{
protected:
    int cant = 0;
public:
    Coleccion();
    virtual bool agregar(int a) = 0;
    virtual bool remover(int a) = 0;
    virtual int getCant() = 0;
    virtual int * get(int i) = 0;
    virtual bool esVacio() = 0;
};

#endif // COLECCION_H
