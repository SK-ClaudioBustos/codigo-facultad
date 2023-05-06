#ifndef CURSO_H
#define CURSO_H
#include <vector>
#include <alumno.h>
#include <iostream>
using namespace std;
class Curso
{
private:
    vector<Alumno*> alumnos;
    char * nombre;
    int id;
public:
    Curso(char * nombre,int id);
    void setAlumno(Alumno * nuevo);
    void imprimirCondiciones();
    void imprimirMail();
};

#endif // CURSO_H
