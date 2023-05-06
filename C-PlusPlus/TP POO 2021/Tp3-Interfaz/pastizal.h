#ifndef PASTIZAL_H
#define PASTIZAL_H


class Pastizal
{
private:
    int fila;
    int columna;
    int vida;
    int contador;
    bool comido;
public:
    Pastizal();
    int getVida(){return this->vida;};
    int getF(){return fila;};
    int getC(){return columna;};
    bool getEstadoComido(){return comido;}
    int getContador(){return contador;}
    bool crecer();
    void restarVida();   
    void pastizalComido();
    void setPosicion(int fila,int columna);
    void setContador(int cont);
    void setEstado(bool est);
    void setVida(int vida);
};

#endif // PASTIZAL_H
