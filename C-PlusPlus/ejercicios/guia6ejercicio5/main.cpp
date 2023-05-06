#include <iostream>
#include "catalogo.h"
#include "cancion.h"
#include "disco.h"
#include "autor.h"
/*
5. Deseamos diseñar un software que mantenga los catálogos de la música,
una canción tiene un autor que pudo componer varias canciones.
A la vez un disco esta compuesto por un conjunto de canciones
que no necesariamente son de un solo autor.
*/
using namespace std;

int main()
{
    catalogo unCatalogo("Heavy Metal Argentino","Claudio");
    autor * unAutor1 = new autor();
    unAutor1->setNom("V8");
    autor * unAutor2 = new autor();
    unAutor2->setNom("Hermetica");
    cancion * unaCancion1 = new cancion("Parcas Sangrientas",4,unAutor1);
    cancion * unaCancion2 = new cancion("Masa Anestesiada",5,unAutor2);
    cancion * unaCancion3 = new cancion("Destruccion",3,unAutor1);
    disco * unDisco = new disco("Variados metal","Heavy Metal",1986);
    unDisco->setC(unaCancion1);
    unDisco->setC(unaCancion2);
    unDisco->setC(unaCancion3);
    unCatalogo.setDisco(unDisco);
    unCatalogo.showDiscos();
    return 0;
}
