#include <iostream>
#include "gestor_textos.h"
#include "texto.h"
using namespace std;
/*
8. Realice un software que dado un texto, cuente cuantas letras hay en el texto, y cuantas
veces se repiten.
 */
int main()
{
    gestor_textos unGestor;
    texto unTexto("acacadabra");
    unTexto.contarLetras();
    unGestor.setTexto(unTexto);
    unGestor.mostrarTextos();
    return 0;
}
