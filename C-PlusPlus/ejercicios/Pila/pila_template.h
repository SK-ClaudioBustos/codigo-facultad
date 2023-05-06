#ifndef PILA_TEMPLATE_H
#define PILA_TEMPLATE_H
#include <iostream>

template <class T>
class Pila_Template
{
private:
    T * pila=NULL;
    int cantidad = 0;
public:
    Pila_Template();
    void push(T);
    T pop();
    bool empty();
};

#endif // PILA_TEMPLATE_H
