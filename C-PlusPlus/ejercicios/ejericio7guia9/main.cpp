#include <iostream>
#include "gestor_bienes.h"
#include "bien.h"
/*
7. Realice un programa que mantenga los datos de bienes de una empresa. Todo bien tiene un
código único que permite el acceso rápido y un valor determinado. El software debe permitir
cargar un bien, buscarlo por código y calcular el valor total de los bienes. Utilice Qt y stl.
 */
using namespace std;

int main()
{
    Gestor_Bienes unGestor;
    Bien b1(12345,1200.500);
    Bien b2(69,12.500);
    Bien b3(42,1444.500);
    Bien b4(445,69.69);
    Bien b5(988,42.42);
    Bien b6(101,35000.0);
    unGestor.cargarBien(b1);
    unGestor.cargarBien(b2);
    unGestor.cargarBien(b3);
    unGestor.cargarBien(b4);
    unGestor.cargarBien(b5);
    unGestor.cargarBien(b6);
    Bien aux = unGestor.buscarBien(988);
    cout << "Codigo: " << aux.getCodigo() << "    Valor: " << aux.getValor() << "\n";
    return 0;
}
