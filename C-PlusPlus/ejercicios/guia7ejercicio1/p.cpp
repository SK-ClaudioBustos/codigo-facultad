#include "p.h"

P::P(char * texto)
{
    this->texto = texto;
}

char * P::escribir()
{
    char * p1 = "<p> ";
    char * p2 = " </p>";
    int p1l = strlen(p1);
    int p2l = strlen(p2);
    int tl = strlen(this->texto);
    char * aux = new char[p1l + p2l + tl];
    strcpy(aux,"");
    strcat(aux,p1);
    strcat(aux,this->texto);
    strcat(aux,p2);
    return aux;
}

