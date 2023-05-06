#ifndef ALUMNO_H
#define ALUMNO_H
#include <iostream>
using namespace std;

class Alumno
{
protected:
    int notaFinal;
    char * nombre;
    char * apellido;
    long dni;
public:
    Alumno();
    virtual bool verificarCondicion() = 0;
    char * getNombre(){return nombre;}
    friend ostream & operator<<(ostream & os,Alumno *  alumn){
        os << "Nombre: "<< alumn->nombre <<" Apellido: "<< alumn->apellido <<" DNI: "<< alumn->dni << "\n";
        return os;
    }
};

#endif // ALUMNO_H
