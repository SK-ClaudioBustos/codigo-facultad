#ifndef CONJUNTO_H
#define CONJUNTO_H
#include "lista.h"


class Conjunto : public Lista
{
public:
    Conjunto();
    bool agregar(int a);
    bool contiene(int a);
};

#endif // CONJUNTO_H
