#include <iostream>
#include "cola.h"
#include "lista.h"
#include "pila.h"
#include "cola_circular.h"
#include "lista_circular.h"
using namespace std;


/*
//PILA-------------------------------------------------------------------------
struct nodoPila{
    int dato;
    nodoPila * link;
};
typedef nodoPila NP;

void setPila(NP *& pila,int dato){
    NP * nuevo=new NP;
    nuevo->dato=dato;
    nuevo->link=pila;
    pila=nuevo;
}

int getPila(NP *& pila){
    int dato=pila->dato;
    NP * aux=pila;
    pila=pila->link;
    delete aux;
    return dato;
}

bool emptyPila(NP * pila){
    return pila == NULL;
}

//COLA---------------------------------------------------------------------
struct nodoCola{
    int dato;
    nodoCola * link;
};
typedef nodoCola NC;

void setCola(NC *& frente,NC *& fondo,int dato){
    NC * nuevo = new NC;
    nuevo->dato = dato;
    nuevo->link = NULL;
    if(fondo != NULL){
        fondo->link = nuevo;
    }
    fondo=nuevo;
    if(frente == NULL){
        frente = nuevo;
    }
}

int getCola(NC *& frente,NC *& fondo){
    int dato = frente->dato;
    NC * aux = frente;
    frente = frente->link;
    delete aux;
    if(frente == NULL){
        fondo = NULL;
    }
    return dato;
}

bool emptyCola(NC * frente,NC * fondo){
    return frente == NULL;
}

//COLA CIRCULAR---------------------------------------------------------------
struct nodoColaCircular{
    int datos[MAX];
    bool vacia;
    bool llena;
    int tamanio;
    int frente;
    int fondo;
    int cant_elementos;
};
typedef nodoColaCircular NCC;

int setColaCircular(NCC & cc,int dato){
    cc.vacia = false;
    //el 10 y el 0 son valores de control;
    if(cc.llena)
        return 10;

    cc.datos[cc.fondo] = dato;
    cc.cant_elementos++;

    if(cc.fondo == cc.tamanio-1)
        cc.fondo = 0;
    else
        cc.fondo++;

    if(cc.fondo == cc.frente)
        cc.llena = true;

    return 0;
}

int getColaCircular(NCC & cc,int &dato){
    cc.llena = false;
    //20 y 0 son codigos de estado
    if(cc.vacia)
        return 20;

    dato = cc.datos[cc.frente];
    cc.cant_elementos--;
    if(cc.frente == cc.tamanio-1)
        cc.frente = 0;
    else
        cc.frente++;

    if(cc.frente == cc.fondo )
        cc.vacia = true;

    return 0;
}

//LISTA----------------------------------------------------------------------------------
struct nodoLista{
    int dato;
    nodoLista * link;
};
typedef nodoLista NL;

void setListaFondo(NL *& lista,int dato){
    NL * nuevo = new NL;
    nuevo->dato = dato;
    nuevo->link = NULL;
    if(lista == NULL){
        lista = nuevo;
    }
    else{
        NL * aux = lista;
        while(aux->link != NULL){
            aux = aux->link;
        }
        aux->link = nuevo;
    }

}

void setListaOrdenada(NL *& lista,int dato){
    NL * nuevo = new NL;
    nuevo->dato = dato;
    NL * actual = lista; NL * anterior = NULL;
    while(actual != NULL && actual->dato < dato){
        anterior = actual;
        actual = actual->link;
    }
    if(anterior == NULL){
        nuevo->link = lista;
        lista = nuevo;
    }
    else{
        nuevo->link = actual;
        anterior->link = nuevo;
    }
}

void getLista(NL * lista){
    while (lista != NULL) {
        cout<<lista->dato<<" ";
        lista = lista->link;
    }
    cout<<endl;
}

//LISTA CIRCULAR
struct NodoListaCircular{
    int dato;
    NodoListaCircular * link;
};
typedef NodoListaCircular NLC;

void setListaCircular(NLC *& lc,int dato){
    NLC * nuevo = new NLC;
    nuevo->dato = dato;
    nuevo->link = lc;
    lc = nuevo;
}

void showListaCircular(NLC * lc){
    NLC* aux=lc;
      do{
        cout<<aux->dato<<" ";
        aux = aux->link;
     }while(aux!=lc);
}

*/


int main()
{


    cout<<endl;
    return 0;
}
