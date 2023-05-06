#include "normal.h"
#include <string.h>
Normal::Normal(int notaFinal,char * nombre,char * apellido, long dni)
{
    this->notaFinal = notaFinal;
    this->nombre = nombre;
    this->apellido = apellido;
    this->dni = dni;
}

void Normal::setNotas(int nota)
{
    if(indice < 3){
        this->notasParciales[indice] = nota;
        this->indice++;
    }
}

//las notas se dan de 1 a 10
bool Normal::verificarCondicion(){
    int sumaNotas = 0;
    sumaNotas += this->notasParciales[0];
    sumaNotas += this->notasParciales[1];
    sumaNotas += this->notasParciales[2];
    float promedioNotas = sumaNotas/3;
    return ((promedioNotas > 6) && (this->notaFinal > 6));
}
