#ifndef VINO_H
#define VINO_H


class Vino
{
protected:
    int nro;
    char tipo;
    int cantLitros;
    int anioProduccion;
    float precio;
public:
    Vino();
    char getT(){return tipo;}
    int getN(){return nro;}
    int getL(){return cantLitros;}
    int getA(){return anioProduccion;}
    float getPrecio(){return precio;};
};

#endif // VINO_H
