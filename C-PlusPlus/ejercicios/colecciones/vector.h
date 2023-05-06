#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include "coleccion.h"

class Vector : public Coleccion
{
private:
    int * vec;
public:
    Vector();
    bool agregar(int a);
    bool remover(int a);
    int getCant();
    int * get(int i);
    bool esVacio();
    ~Vector();
};

#endif // VECTOR_H
