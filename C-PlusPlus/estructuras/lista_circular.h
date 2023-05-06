#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H
#include <iostream>

struct NodoListaCircular{
    int dato;
    NodoListaCircular * link;
};
typedef NodoListaCircular NLC;

class lista_circular
{
private:
    NLC * lc = NULL;
public:
    lista_circular();
    void setListaCircular(int dato);
    void showListaCircular();
};

#endif // LISTA_CIRCULAR_H
