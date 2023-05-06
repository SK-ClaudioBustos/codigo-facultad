#ifndef COLA_CIRCULAR_H
#define COLA_CIRCULAR_H
#define MAX 10
struct NodoColaCircular{
    int datos[MAX];
    int frente;
    int fondo;
    bool llena;
    bool vacia;
    int cant_elementos;
};
typedef NodoColaCircular NCC;

class cola_circular
{
private:
    NCC cc;
public:
    cola_circular();
    int setColaCircular(int dato);
    int getColaCircular(int &dato);
    void showColaCircular();
};

#endif // COLA_CIRCULAR_H
