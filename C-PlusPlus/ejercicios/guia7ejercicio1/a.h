#ifndef A_H
#define A_H
#include "tag.h"
#include <iostream>
class A: public Tag
{
private:
    char * link;
    char * texto;
public:
    A(char * texto,char * link);
    char * escribir();
};

#endif // A_H
