#include "lista.h"

Lista::Lista()
{

}

bool Lista::agregar(int a) {
    nodo * aux = this->puntero;
    nodo * auxAnt = NULL;
    while (aux != NULL) {
        auxAnt = aux;
        aux = aux->sig;
    }
    nodo * nuevo = new nodo;
    nuevo->dato = a;
    nuevo->sig = NULL;
    if (auxAnt != NULL) auxAnt->sig = nuevo;
            else this->puntero = nuevo;
    this->cant++;
    return true;
}

bool Lista::remover(int a){

    nodo *aux = this->puntero;
    nodo *ant = NULL;
    while (aux!= NULL) {
        if (aux->dato == a) {
            break;
        }
        ant = aux;
        aux = aux->sig;
    }
    if (aux == NULL) {
        return false;
    } else {
        if (ant == NULL) {
            this->puntero = aux->sig;
        } else {
            ant->sig = aux->sig;
        }
        delete aux;
        this->cant--;
    }
    return true;
}

int Lista::getCant() {
    return this->cant;
}

int * Lista::get(int index){
    if (index >= this->cant) return NULL;
    nodo *aux = this->puntero;
    int i = 0;
    while (aux!= NULL) {
        if (i == index) {
            return &aux->dato;
        }
        aux = aux->sig;
        i++;
    }
}

bool Lista::esVacio() {
    return this->puntero == NULL;
}

Lista::~Lista() {
    nodo * aux = this->puntero;
    nodo * ant = NULL;
    while (aux!= NULL) {
        ant = aux->sig;
        delete aux;
        aux = ant;
    }
}
