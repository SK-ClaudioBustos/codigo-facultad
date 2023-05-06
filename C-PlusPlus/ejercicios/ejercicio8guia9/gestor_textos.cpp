#include "gestor_textos.h"
#include <iostream>
gestor_textos::gestor_textos()
{

}

void gestor_textos::setTexto(texto nuevo)
{
    this->textos.push_back(nuevo);
}

void gestor_textos::mostrarTextos()
{
    std::cout<< "Mostrando Informacion de textos" << std::endl << std::endl;
    for(auto i = this->textos.begin();i != this->textos.end(); ++i){
        i->mostrarInformacionTexto();
    }
}
