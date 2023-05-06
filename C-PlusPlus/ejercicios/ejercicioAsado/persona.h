#ifndef PERSONA_H
#define PERSONA_H


class Persona
{
private:
    double gasto = 0;
    char * nombre;
    double saldo = 0;
public:
    Persona();
    Persona(char * nombre);
    double getGasto();
    double getSaldo();
    void incGasto(double gasto);
    void calcularSaldo(double totalPorPer);
};

#endif // PERSONA_H
