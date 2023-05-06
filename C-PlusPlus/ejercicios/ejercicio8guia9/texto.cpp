#include "texto.h"

texto::texto(std::string c)
{
    this->contenido = c;
    this->cantLetras = c.size();
}

void texto::contarLetras()
{
    for(int i = 0;i <this->cantLetras;++i){
        if(this->contadorLetras.count(this->contenido[i])){
            this->contadorLetras[this->contenido[i]] += 1;
        }
        else{
            this->contadorLetras[this->contenido[i]] = 1;
        }
    }
}

void texto::mostrarInformacionTexto()
{
    std::cout <<"Mostrando Informacion del texto: " << this->contenido << std::endl;
    std::cout <<"Cantidad de letras: " << this->cantLetras << std::endl;
    std::cout <<"Mostrando Letras y cantidad de veces que se repiten: \n";
    for(auto i = this->contadorLetras.begin(); i != this->contadorLetras.end(); ++i){
        std::cout << i->first << ": " << i->second << "\n";
    }
    std::cout <<"\n";
}
