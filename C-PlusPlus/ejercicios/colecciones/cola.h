#ifndef COLA_H
#define COLA_H
#include <iostream>

struct nodo {
    int dato;
    nodo *sig;
};

class Cola
{
private:
    nodo * frente = NULL;
    nodo * fondo = NULL;
public:
    Cola();
    void push(int n);
    int pop();
    bool isEmpty();
};

#endif // COLA_H
