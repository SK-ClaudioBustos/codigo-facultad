#include <iostream>
#include "gestordearchivos.h"
using namespace std;
/*
1. Realice un procedimiento que tome un archivo de texto y lo corte en n archivos de texto (donde n debe ser pasado por
parámetros) Por ejemplo dado un archivo de 6 líneas y un n=2, el procedimiento debe retornar 2 archivos, el primero
con las 3 primeras líneas y el otro con las restantes
*/
int main()
{

    GestorDeArchivos unGestor;
    unGestor.TotLineas("file.txt");
    unGestor.LectorDeArchivos("file.txt");
    unGestor.CreadorDeArchivos(2);
    return 0;
}
