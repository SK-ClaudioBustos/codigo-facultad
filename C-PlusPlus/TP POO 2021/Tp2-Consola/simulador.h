#ifndef SIMULADOR_H
#define SIMULADOR_H
#include "mapa.h"
#include "poblacion.h"
#include "vector"
#include <iostream>
#include <time.h>
#include "poblacion_a.h"
#include "poblacion_b.h"
#include <fstream>
using namespace std;

/*
 SI DESEA SABER LAS CARACTERISTICAS DEL PROGRAMA, VAYA AL MAIN PARA OBTENER MAS INFORMACION.
 */

struct dataSimulador{
    int cantPobA;
    int cantPobB;
    int duracionTiempo;
    int diaActual;
};

struct dataPoblacion{
    int fila;
    int columna;
    int vida;
    char tipo;
};

class Simulador
{
private:
    Mapa * unMapa;
    int cantPoblacionA = 0;
    int cantPoblacionB = 0;
    vector<Poblacion*> poblacionesCiervos;
    int cantTotalPoblaciones = 0;
    int duracionTiempo = 0;
    bool recuperarSimulacion = false;
public:
    Simulador();
    //getters
    int **getMatriz();
    int getDuracionTiempo(){return duracionTiempo;}
    int getN();
    int getM();
    //setters
    void setConfiguracion(Mapa * m,int ca,int cb,int dt);
    void setPoblacionNueva(Poblacion * nuevaDeTipoA);
    void setPosicionInicialPoblaciones();
    //------------------
    void inicializacionPoblaciones();
    void crearPoblaciones();
    void movimientoDePoblaciones();
    void controlDePoblacion();
    void controlarPastizales();
    void controlarRelacionesPoblacion();
    bool verificarExistenciaArchivoConfig();
    bool verificarExistenciaSimulacionGuardada();
    //archivos
    void guardarConfiguracionIngresada();
    void guardarSimulacion(int diaActual);
    void guardarDatosPoblaciones(int dia);
    void guardarPoblaciones();
    vector<int> recuperarConfiguracionIngresada();
    void recuperarSimulacionGuardada();
    void recuperarPoblaciones();
    int recuperarDiaActual();
};

#endif // SIMULADOR_H
