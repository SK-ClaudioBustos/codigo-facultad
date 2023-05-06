#ifndef PILA_H
#define PILA_H
#include <iostream>

struct nodo {
    int dato;
    nodo *sig;
};

class Pila
{
private:
    nodo * puntero = NULL;
    int cant = 0;
public:
    Pila();
    void push(int n);
    int pop();
    bool isEmpty();
};

#endif // PILA_H
