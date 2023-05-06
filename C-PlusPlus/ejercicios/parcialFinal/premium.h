#ifndef PREMIUM_H
#define PREMIUM_H
#include <vino.h>

class Premium: public Vino
{
public:
    Premium(int nro, char tipo, int cantLitros, int anioProduccion, float precio);
};

#endif // PREMIUM_H
