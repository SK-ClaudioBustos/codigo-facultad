#ifndef ALUMNOESPECIAL_H
#define ALUMNOESPECIAL_H

/*
2. Cree una clase “Alumnos especiales” estos pueden contener “n” notas de parciales. Realice los
siguientes métodos: agregar notas, mostrar todas las notas, eliminar una nota en particular, calcular
promedio. Utilice vectores dinámicos.
*/

class AlumnoEspecial
{
    int nroNotas;
    int * notas;
public:
    AlumnoEspecial();
    void setNotas(int nota);
    void mostrarNotas();
    void eliminarNota(int nota);
    float calcularPromedio();
};

#endif // ALUMNOESPECIAL_H
