#include "vector.h"

Vector::Vector()
{}

bool Vector::agregar(int a) {
    int * aux = new int[this->cant+1];
    for(int i = 0; i < this->cant; i++) {
        aux[i] = this->vec[i];
    }
    aux[this->cant] = a;
    delete [] this->vec;
    this->vec = aux;
    this->cant++;
    return true;
}

bool Vector::remover(int a) {
    int existe = -1;
    for(int i = 0; i < this->cant; i++) {
        if (this->vec[i] == a) {
            existe = i;
            break;
        }
    }
    if (existe == -1) return false;
    int * aux = new int[this->cant-1];
    for(int i = 0; i < existe; i++) {
        aux[i] = this->vec[i];
    }
    for(int i = existe; i < this->cant -1; i++) {
        aux[i] = this->vec[i+1];
    }
    delete [] this->vec;
    this->vec = aux;
    this->cant--;
    return true;
}

int Vector::getCant() {
    return this->cant;
}

int * Vector::get(int i) {
    if(i >= this->cant) return NULL;
    return &this->vec[i];
}

bool Vector::esVacio(){
    return this->cant == 0;
}
