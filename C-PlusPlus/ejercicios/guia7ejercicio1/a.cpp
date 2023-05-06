#include "a.h"
#include <string.h>

A::A(char * texto,char * link)
{
     this->link = link;
     this->texto = texto;
}

char * A::escribir()
{
    char * p1 = "<a href=\"";
    char * p2 = "\">";
    char * p3 = " </a>";
    int p1l = strlen(p1);
    int p2l = strlen(p2);
    int p3l = strlen(p3);
    int t1l = strlen(this->link);
    int t2l = strlen(this->texto);
    char * aux = new char[p1l + p2l + p3l + t1l + t2l];
    strcpy(aux,"");
    strcat(aux,p1);
    strcat(aux,this->link);
    strcat(aux,p2);
    strcat(aux,this->texto);
    strcat(aux,p3);
    return aux;
}
