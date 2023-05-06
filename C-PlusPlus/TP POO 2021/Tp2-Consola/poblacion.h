#ifndef POBLACION_H
#define POBLACION_H


class Poblacion
{
protected:
    int fila;
    int columna;
    int vida;
    bool estado;
public:
    Poblacion();
    void setPosicionActual(int fila,int columna);
    virtual char getTipo() = 0;
    int getV(){return vida;}
    int getF(){return fila;}
    int getC(){return columna;}
    void restarVida();
    void setVida(int v);
    bool getEstado();
};

#endif // POBLACION_H
