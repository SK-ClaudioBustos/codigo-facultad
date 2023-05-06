#ifndef GESTORDEARCHIVOS_H
#define GESTORDEARCHIVOS_H
#include<iostream>
#include <vector>
using namespace std;
/*
1. Realice un procedimiento que tome un archivo de texto y lo corte en n archivos de texto (donde n debe ser pasado por
parámetros) Por ejemplo dado un archivo de 6 líneas y un n=2, el procedimiento debe retornar 2 archivos, el primero
con las 3 primeras líneas y el otro con las restantes
*/

class GestorDeArchivos
{
private:
    int TotalLineas = 0;
    vector<string> lineas;
public:
    GestorDeArchivos();
    void TotLineas(string ruta);
    void LectorDeArchivos(string ruta);
    void CreadorDeArchivos(int cantidadCortes);
    int getTotalLineas();
};

#endif // GESTORDEARCHIVOS_H
