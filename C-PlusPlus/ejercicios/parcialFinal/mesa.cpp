#include "mesa.h"

Mesa::Mesa(int nro, char tipo, int cantLitros, int anioProduccion, float precio)
{
    this->nro = nro;
    this->tipo = tipo;
    this->cantLitros = cantLitros;
    this->anioProduccion = anioProduccion;
    this->precio = precio;
}
