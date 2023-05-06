#ifndef COLA_H
#define COLA_H
#include <iostream>

struct NodoCola{
    int dato;
    NodoCola * link;
};
typedef NodoCola NC;

class cola
{
private:
    NC * frente = NULL;
    NC * fondo = NULL;
public:
    cola();
    void setCola(int dato);
    int getCola();
    bool emptyCola();
    void showCola();
};

#endif // COLA_H
