#include "imag.h"
#include <string.h>
#include <iostream>
Imag::Imag(char * nameImag)
{
    this->nameImag = nameImag;
}

char * Imag::escribir()
{
    char * p1 = "<img href=\"";
    char * p2 = "\" />";
    int p1l = strlen(p1);
    int p2l = strlen(p2);
    int tl = strlen(this->nameImag);
    char * aux = new char[p1l + p2l + tl];
    strcpy(aux,"");
    strcat(aux,p1);
    strcat(aux,this->nameImag);
    strcat(aux,p2);
    return aux;
}
