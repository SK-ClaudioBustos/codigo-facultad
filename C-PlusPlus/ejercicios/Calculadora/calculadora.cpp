#include "calculadora.h"
#include <iostream>
using namespace std;
Calculadora::Calculadora()
{

}

QString Calculadora::inputNros(QString nro)
{
    this->acumulador += nro;
    return acumulador;
}

void Calculadora::setOperacion(QString ope)
{
    elemento nuevo;
    nuevo.nro = this->acumulador.toInt();
    nuevo.op = ope.toStdString()[0];
    this->numeros.push_back(nuevo);
    this->acumulador = "";
}

double Calculadora::output()
{
    double resultado = this->numeros[0].nro;
    this->setOperacion("=");
    for(auto i =this->numeros.begin();i < this->numeros.end();++i){
            if(i != this->numeros.begin()){
                if((i-1)->op ==  '*' || (i-1)->op == '/'){
                   if((i-1)->op ==  '*' )
                       resultado *= i->nro;
                   else
                       resultado /= i->nro;
                }
                else{
                    if((i-1)->op == '-')
                        resultado -= i->nro;
                    else
                        resultado += i->nro ;
                }
            }
    }
    this->numeros.clear();
    this->acumulador = "";
    return resultado;
}
