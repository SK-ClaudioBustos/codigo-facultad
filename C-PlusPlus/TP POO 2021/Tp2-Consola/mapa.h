#ifndef MAPA_H
#define MAPA_H
#include "pastizal.h"
#include <vector>
#include <iostream>
#include <time.h>
#include <fstream>
using namespace std;
struct dataMapa{
    int n;
    int m;
    int cantPastizales;
};

struct dataPastizal{
    int fila;
    int columna;
    int vida;
    int contador;
    bool comido;
};

//para entender de una manera mas sencilla como se crea el mapa(matriz),
//dirigase a la funcion llamaraFuncionesMapa()
class Mapa
{
    int ** mapa = NULL;
    int n = 0;
    int m = 0;
    vector<Pastizal> pastizales;
    int cantPastizales = 0;
    bool pastizalesRecuperados = false;
public:
    Mapa();
    Mapa(int n, int m,int cantP);
    void generarMatriz();
    void cargarMontaniasMesetas();
    void generarMontaniasInternas();
    void validarAreasCerradas();
    void setPastizal(Pastizal nuevo);
    void generarPastizales();
    void revisarPastizales();
    void pastizalComido(int fila,int columna);
    void llamarFuncionesMapa();
    //getters
    int ** getMatriz(){return this->mapa;}
    int getN(){return n;}
    int getM(){return m;}
    int getCantidadPastizales(){return cantPastizales;}
    //archivos
    void guardarConfiguracionMapa();
    int guardarPastizales();
    void recuperarSimulacionGuardada();
    void recuperarTrazadoMapa();
};

#endif // MAPA_H
