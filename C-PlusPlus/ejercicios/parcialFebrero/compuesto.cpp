#include "compuesto.h"

Compuesto::Compuesto(char *nombre)
{
    this->nombre = nombre;
}

float Compuesto::precioAjustado()
{
    float acum = 0.0;
    for(int i = 0; i <(int)conjuntoP.size();++i){
        acum += this->conjuntoP[i]->precioAjustado();}
    return acum;
}

void Compuesto::setProducto(Producto * nuevo)
{
    if(this->conjuntoP.size() <=10)
        conjuntoP.push_back(nuevo);
}

void Compuesto::mostrar()
{
    cout<<"Producto Compuesto: \n";
    for(int i = 0; i <(int)conjuntoP.size();++i){
        this->conjuntoP[i]->mostrar();
    }
    cout<<"Precio total P.C. = "<<precioAjustado()<<endl;
}
