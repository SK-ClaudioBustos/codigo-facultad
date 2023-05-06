#ifndef TEXTO_H
#define TEXTO_H
#include <iostream>
#include <map>

class texto
{
    int cantLetras = 0;
    std::string contenido = "";
    std::map<char,int> contadorLetras;
public:
    texto(std::string c);
    void contarLetras();
    void mostrarInformacionTexto();
};

#endif // TEXTO_H
