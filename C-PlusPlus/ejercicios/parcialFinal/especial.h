#ifndef ESPECIAL_H
#define ESPECIAL_H
#include <vino.h>

class Especial: public Vino
{
public:
    Especial(int nro, char tipo, int cantLitros, int anioProduccion, float precio);
};

#endif // ESPECIAL_H
