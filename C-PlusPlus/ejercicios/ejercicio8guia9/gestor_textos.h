#ifndef GESTOR_TEXTOS_H
#define GESTOR_TEXTOS_H
#include "texto.h"
#include <vector>
class gestor_textos
{
    std::vector<texto> textos;
public:
    gestor_textos();
    void setTexto(texto nuevo);
    void mostrarTextos();
};

#endif // GESTOR_TEXTOS_H
