#ifndef BIEN_H
#define BIEN_H
class Bien
{
    int codigoUnico = -1;
    float valor = -1;
public:
    Bien(int c,float v);
    int getCodigo(){return codigoUnico;}
    float getValor(){return valor;}
};
#endif // BIEN_H
