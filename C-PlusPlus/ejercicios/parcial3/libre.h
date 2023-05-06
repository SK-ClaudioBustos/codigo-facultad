#ifndef LIBRE_H
#define LIBRE_H
#include<alumno.h>

class Libre: public Alumno
{
private:
    int notaEjercicio;
public:
    Libre(int notaFinal,char * nombre,char * apellido, long dni);
    void setNota(int nota){notaEjercicio = nota;}
    bool verificarCondicion();
};

#endif // LIBRE_H
