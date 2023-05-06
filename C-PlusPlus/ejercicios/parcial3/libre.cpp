#include "libre.h"
#include <string.h>
Libre::Libre(int notaFinal,char * nombre,char * apellido, long dni)
{
    this->notaFinal = notaFinal;
    this->nombre = nombre;
    this->apellido = apellido;
    this->dni = dni;
}

bool Libre::verificarCondicion()
{
    return ((this->notaFinal > 7)  && (this->notaEjercicio >7));
}
