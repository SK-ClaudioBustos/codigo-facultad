#include "body.h"

Body::Body()
{

}

void Body::set(Tag *nuevo)
{
    Tag ** aux = new Tag*[this->indice+1];
    for(int i = 0; i<this->indice;i++){
        aux[i] = this->contenido[i];
    }
    aux[this->indice] = nuevo;
    //delete this->indice
    this->contenido = aux;
    this->indice++;
}

