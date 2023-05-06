#ifndef GESTOR_BIENES_H
#define GESTOR_BIENES_H
#include <vector>
#include "bien.h"
class Gestor_Bienes
{
    std::vector <Bien> bienes;
public:
    Gestor_Bienes();
    void cargarBien(Bien nuevo);
    bool validarBusqueda(int codigo);
    Bien buscarBien(int codigo);
    float calcularValorTotal();
};

#endif // GESTOR_BIENES_H
