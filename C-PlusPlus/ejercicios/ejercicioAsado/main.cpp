#include <iostream>
#include "persona.h"
#include "gestorcomidas.h"
/*
 Un grupo de 5 amigos se junta todos los jueves a comer un asado,
para organizar dicha cena, diferentes amigos realizan gastos,
los cuales deben ser divididos en partes iguales por los comensales.
Realice un software que permita calcular cuanto dinero debe recibir o pagar cada amigo.
*/
using namespace std;

int main()
{
    GestorComidas unGestor;
    Persona p1("emanuel");
    Persona p2("pablito");
    Persona p3("sartori");
    Persona p4("tomas");
    Persona p5("lautaro");

    p1.incGasto(400);
    p2.incGasto(44);
    p3.incGasto(222);
    p4.incGasto(0);
    p5.incGasto(0);

    Persona amigos[5];
    amigos[0] = p1;
    amigos[1] = p2;
    amigos[2] = p3;
    amigos[3] = p4;
    amigos[4] = p5;

    unGestor.setAmigos(amigos);
    unGestor.setSaldoPorPersona();
    Persona * aux = unGestor.getAmigos();

    for(int i = 0;i<5;i++){
        cout <<"Gasto: " <<aux[i].getGasto() <<endl;
        cout <<"Saldo: "<<aux[i].getSaldo() <<endl;
        cout <<endl;
    }
    return 0;
}
