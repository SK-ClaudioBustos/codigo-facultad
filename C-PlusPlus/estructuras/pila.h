#ifndef PILA_H
#define PILA_H
#include <iostream>
struct NodoPila{
    int dato;
    NodoPila * link;
};
typedef NodoPila NP;

class pila
{
private:
    NP * Pila = NULL;
public:
    pila();
    void setPila(int dato);
    int getPila();
    bool emptyPila();
    void showPila();
};

#endif // PILA_H
