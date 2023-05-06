#include "alumnoespecial.h"
#include <iostream>
using namespace std;
AlumnoEspecial::AlumnoEspecial()
{
    this->nroNotas = 0;
    this->notas = new int[0];
}

void AlumnoEspecial::setNotas(int nota)
{
    int * aux = new int[this->nroNotas+1];
    for(int i = 0; i < this->nroNotas;++i)
        aux[i] = this->notas[i];
    aux[this->nroNotas] = nota;
    this->notas = aux;
    this->nroNotas++;
}

void AlumnoEspecial::mostrarNotas()
{
    cout<<"MOSTRANDO NOTAS ALUMNO ESPECIAL\n";
    for(int i = 0; i < this->nroNotas; ++i){
        cout<<"Nota "<<i+1<<": "<<this->notas[i]<<"\n";
    }
    cout<<endl;
}

void AlumnoEspecial::eliminarNota(int nota)
{
    int * aux = new int[this->nroNotas-1];
    for(int i = 0; i < this->nroNotas;++i){
        if(this->notas[i] != nota)
            aux[i] = this->notas[i];
    }
    this->notas = aux;
    this->nroNotas--;
}

float AlumnoEspecial::calcularPromedio()
{
    int acum = 0;
    for(int i = 0; i < this->nroNotas; ++i){
        acum += this->notas[i];
    }
    return acum / this->nroNotas;
}
