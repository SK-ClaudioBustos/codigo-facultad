#ifndef NORMAL_H
#define NORMAL_H
#include <alumno.h>

class Normal: public Alumno
{
private:
    int notasParciales[3];
    int indice = 0;
public:
    Normal(int notaFinal,char * nombre,char * apellido, long dni);
    void setNotas(int nota);
    bool verificarCondicion();
};

#endif // NORMAL_H
