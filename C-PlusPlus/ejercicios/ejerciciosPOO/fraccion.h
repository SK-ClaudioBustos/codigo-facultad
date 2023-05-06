#ifndef FRACCION_H
#define FRACCION_H
/*
Realice una clase que represente una Fracción.
a) Un objeto fracción solo se puede construir a partir de un numerador y denominador.
b) Un objeto fracción debe poder sumar, restar, multiplicar y dividir.
c) Un objeto fracción debe poder simplificarse
*/

class Fraccion
{
private:
    int denominador;
    int numerador;
public:
    Fraccion(int n,int d);
    int getDenominador();
    int getNumerador();
    int mcd(int a,int b);
    Fraccion suma(Fraccion other);
    Fraccion resta(Fraccion other);
    Fraccion division(Fraccion other);
    Fraccion multiplicar(Fraccion other);
    void simplificar();
};

#endif // FRACCION_H
