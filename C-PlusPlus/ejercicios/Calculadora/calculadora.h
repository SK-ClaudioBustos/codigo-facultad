#ifndef CALCULADORA_H
#define CALCULADORA_H
#include <QString>
#include <vector>

struct elemento{
    int nro;
    char op = '-';
};

class Calculadora
{
private:
    QString acumulador = "";
    std::vector<elemento> numeros;
public:
    Calculadora();
    QString inputNros(QString nro);
    void setOperacion(QString ope);
    double output();
};

#endif // CALCULADORA_H
