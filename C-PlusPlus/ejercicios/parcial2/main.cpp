#include <iostream>
#include "gestorproducto.h"
#include "producto.h"
#include "nacional.h"
#include "internacional.h"
#include "compuesto.h"
using namespace std;
/*
Una Empresa lo contrata para diseñar un software que calcule el ajuste por inflación de
sus productos, existen 3 tipos de productos.
Nacionales: tienen un aumento de 10% de su precio.
Internacionales: tienen un aumento calculado según un % ingresado por parámetros.
Compuestos: los cuales están compuesto por un conjunto de productos (no más de 10) y
precio esta dada por la suma de precios de los productos que lo componen.
La empresa no puede tener más de 50 productos.

Realice un diseño e implementación que permita imprimir un listado de precios
actuales y otro con los precios ajustados

Realice una función que genere el código de producto el cual esta compuesto por
los 3 primeras letras del nombre del producto en minúscula. Sobrescriba el operador <<
para imprimirlo.
*/
int main()
{
    GestorProducto unGestor;
    Producto * p1 = new Nacional(14.5,"tomates");
    Producto * p2 = new Internacional(50.55,"huevos de pascua");
    Producto * p3 = new Nacional(69.5,"bananas");
    unGestor.setP(p1);
    unGestor.setP(p2);
    unGestor.setP(p3);
    unGestor.mostrarPreciosActuales();
    unGestor.mostrarPreciosAjustados();
    //unGestor.mostrarCodigosProductos();
    return 0;
}
