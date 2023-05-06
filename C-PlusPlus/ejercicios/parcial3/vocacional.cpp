#include "vocacional.h"
#include <string.h>
Vocacional::Vocacional(int notaFinal,char * nombre,char * apellido, long dni)
{
    this->notaFinal = notaFinal;
    this->nombre = nombre;
    this->apellido = apellido;
    this->dni = dni;
}


bool Vocacional::verificarCondicion(){
    return this->notaFinal > 7;
}
