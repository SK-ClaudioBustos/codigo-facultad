#ifndef P_H
#define P_H
#include "tag.h"
#include <string.h>
#include <iostream>
class P: public Tag
{
private:
    char * texto;
public:
    P(char * texto);
    char * escribir();
};

#endif // P_H
