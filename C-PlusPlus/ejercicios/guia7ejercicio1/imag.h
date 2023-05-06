#ifndef IMAG_H
#define IMAG_H
#include "tag.h"

class Imag: public Tag
{
private:
    char * nameImag;
public:
    Imag(char * nameImag);
    char * escribir();
};

#endif // IMAG_H
