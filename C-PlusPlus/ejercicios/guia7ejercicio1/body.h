#ifndef BODY_H
#define BODY_H
#include "tag.h"
#include <iostream>

class Body
{
private:
    Tag ** contenido;
    int indice = 0;
public:
    Body();
    void set(Tag *nuevo);
    friend std::ostream& operator<<(std::ostream & os,const Body & obj)
    {   std::cout << "<body>" << std::endl;
        for(int i = 0; i<obj.indice;i++){
            os << obj.contenido[i]->escribir();
            os << std::endl;
        }
        std::cout << "</body>" << std::endl << std::endl;
        return os;
    }
};

#endif // BODY_H
