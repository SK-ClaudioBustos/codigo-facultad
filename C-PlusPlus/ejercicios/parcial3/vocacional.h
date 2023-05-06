#ifndef VOCACIONAL_H
#define VOCACIONAL_H
#include <alumno.h>

class Vocacional: public Alumno
{
public:
    Vocacional(int notaFinal,char * nombre,char * apellido, long dni);
    bool verificarCondicion();
};

#endif // VOCACIONAL_H
