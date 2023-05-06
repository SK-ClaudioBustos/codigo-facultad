#include <iostream>
using namespace std;
#include <alumno.h>
#include<libre.h>
#include<vocacional.h>
#include<normal.h>
#include<curso.h>
#include<alumnoespecial.h>
/*
1. Un curso esta conformado por 3 tipos de alumnos:
Alumnos normales: tienen 3 parciales y un examen final. Para aprobar el curso deben tener
un promedio de 60% en los parciales y más de 60 en el examen final.
Alumnos vocacionales: Solo realizan un examen final que se prueba con 70%
Alumnos libres: Solo realizan un examen final que se prueba con 70% y además deben
aprobar un ejercicio más.
Además se deben mantener datos de los alumnos (dni, nombre, apellido).
Realice el modelado de las clases necesarias. Teniendo en cuenta que un curso puede tener un
máximo de 30 alumnos.
Realizar un listado de los alumnos con sus condiciones (aprobado o desaprobado). Utilizando
polimorfismo.
Realice un listado de los emails otorgados por la facultad, estos se conforman con la primera letra
del nombre, el apellido y finaliza con “@uader.edu.ar”

2. Cree una clase “Alumnos especiales” estos pueden contener “n” notas de parciales. Realice los
siguientes métodos: agregar notas, mostrar todas las notas, eliminar una nota en particular, calcular
promedio. Utilice vectores dinámicos.

3. Sobre escriba el operador “<<” para que muestre los datos de un alumno.
*/

int main()
{
    Curso unCurso("POO",69);
    Normal * a1 = new Normal(7,"Claudio","Bustos",42602340);
    Libre * a2 = new Libre(5,"Jeronimo","Suquivide",343507766);
    Vocacional * a3 = new Vocacional(9,"Marcos","Miller",696996969);
    Vocacional * a4 = new Vocacional(6,"Alexis","Suarez",649449494);

    a1->setNotas(8);
    a1->setNotas(8);
    a1->setNotas(8);
    a2->setNota(7);
    unCurso.setAlumno(a1);
    unCurso.setAlumno(a2);
    unCurso.setAlumno(a3);
    unCurso.setAlumno(a4);

    unCurso.imprimirCondiciones();
    unCurso.imprimirMail();

    cout<<endl;
    cout<<a1;

    AlumnoEspecial * a5 = new AlumnoEspecial;
    a5->setNotas(7);
    a5->setNotas(7);
    a5->setNotas(8);
    a5->setNotas(9);
    a5->mostrarNotas();
    return 0;
}
