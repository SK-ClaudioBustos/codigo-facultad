#ifndef MESA_H
#define MESA_H
#include <vino.h>

class Mesa: public Vino
{
public:
    Mesa(int nro, char tipo, int cantLitros, int anioProduccion, float precio);
};

#endif // MESA_H
