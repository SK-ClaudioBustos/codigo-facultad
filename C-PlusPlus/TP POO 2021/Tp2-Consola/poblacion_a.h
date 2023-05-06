#ifndef POBLACION_A_H
#define POBLACION_A_H
#include "poblacion.h"

class Poblacion_A: public Poblacion
{
public:
    Poblacion_A();
    char getTipo(){return 'A';}
};

#endif // POBLACION_A_H
