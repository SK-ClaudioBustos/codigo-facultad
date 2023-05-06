#include "fraccion.h"

Fraccion::Fraccion(int n, int d)
{
    this->denominador = d;
    this->numerador = n;
}

int Fraccion::mcd(int a,int b){
    if(a == b)
        return a;
    else
        if(a > b)
            return mcd(a-b,b);
        else
            return mcd(a,b-a);
}

int Fraccion::getDenominador()
{
    return this->denominador;
}

int Fraccion::getNumerador()
{
    return this->numerador;
}

Fraccion Fraccion::suma(Fraccion other)
{   int d = 0; int n = 0;
    if(this->denominador == other.getDenominador()){
        n = this->numerador + other.getNumerador();
        d = this->denominador;}
    else{
        int mcd = this->mcd(this->denominador,other.denominador);
        d = mcd;
        n = this->denominador*d + other.getDenominador()*d;
    }
    Fraccion nuevo(n,d);
    return nuevo;

}

Fraccion Fraccion::resta(Fraccion other)
{
    int d = 0; int n = 0;
        if(this->denominador == other.getDenominador()){
            n = this->numerador - other.getNumerador();
            d = this->denominador;}
        else{
            int mcd = this->mcd(this->denominador,other.denominador);
            d = mcd;
            n = this->denominador*d - other.getDenominador()*d;
        }
        Fraccion nuevo(n,d);
        return nuevo;
}

Fraccion Fraccion::division(Fraccion other)
{   Fraccion nuevo(this->numerador * other.getDenominador(),this->denominador * other.getNumerador());
    return nuevo;
}

Fraccion Fraccion::multiplicar(Fraccion other)
{
    Fraccion nuevo(this->numerador * other.getNumerador(),this->denominador * other.getDenominador());
    return nuevo;
}

void Fraccion::simplificar()
{   int i = 2;
    while(i != 10){
        if((this->numerador%i == 0) && (this->numerador%i == 0)){
            this->denominador/=i;
            this->numerador/=i;
            i--;
        }
        i++;
    }
}
