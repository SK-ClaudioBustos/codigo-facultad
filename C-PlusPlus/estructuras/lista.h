#ifndef LISTA_H
#define LISTA_H
#include <iostream>

struct NodoLista{
    int dato;
    NodoLista * link;
};
typedef NodoLista NL;

class lista
{
private:
    NL * Lista = NULL;
public:
    lista();
    void setListaFondo(int dato);
    void setListaOrdenada(int dato);
    void getLista();
};

#endif // LISTA_H
