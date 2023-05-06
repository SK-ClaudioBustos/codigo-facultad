#ifndef GESTORVINOS_H
#define GESTORVINOS_H
#include "vino.h"
#include <vector>
using namespace std;
#include <iostream>
#include <fstream>
#include "mesa.h"
#include <premium.h>
#include <especial.h>
#include <map>
#include <algorithm>

struct VinoData{
    int nro;
    char tipo;
    int cantidadLitros;
    int anioProduccion;
};

class GestorVinos
{
private:
    vector<Vino*> vinos;
public:
    GestorVinos();
    void setVino(Vino * nuevo){vinos.push_back(nuevo);};
    void recuperarInfoVinos();
    int getCantLitros(int anio);
    int getMontoTotalLitros(int anio);
    void crearInforme();
    map<int, int> topFive();
    void getMasVinos(int anio);
    void betterYear();
    void mayorMontoVenta();
};

#endif // GESTORVINOS_H
