#include "gestor_bienes.h"

Gestor_Bienes::Gestor_Bienes()
{

}

void Gestor_Bienes::cargarBien(Bien nuevo)
{
    this->bienes.push_back(nuevo);
}

bool Gestor_Bienes::validarBusqueda(int codigo)
{
    for(int i = 0; i < (int)this->bienes.size(); i++){
        if(this->bienes[i].getCodigo() == codigo)
            return true;
    }
    return false;
}

Bien Gestor_Bienes::buscarBien(int codigo)
{
    for(int i = 0; i < (int)this->bienes.size(); i++){
        if(this->bienes[i].getCodigo() == codigo)
            return this->bienes[i];
    }
}

float Gestor_Bienes::calcularValorTotal()
{
    float total = 0.0;
    for(auto i = this->bienes.begin(); i != this->bienes.end(); ++i){
        total += i->getValor();
    }
    return total;
}
