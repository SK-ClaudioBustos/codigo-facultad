#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include "coleccion.h"

class Lista : public Coleccion
{
protected:
    nodo * puntero = NULL;
public:
    Lista();
    bool agregar(int a);
    bool remover(int a);
    int getCant();
    int * get(int i);
    bool esVacio();
    ~Lista();
};

#endif // LISTA_H
