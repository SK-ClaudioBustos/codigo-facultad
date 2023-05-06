#include "bimap.h"
#include <iostream>
bimap::bimap()
{

}

bool bimap::isValue(int value)
{
    for(auto i = this->bm.begin(); i != this->bm.end(); ++i){
        if(i->second == value)
            return true;
    }
    return false;
}

void bimap::set(std::string k, int v)
{
    if(this->bm.count(k) == 0 && !this->isValue(v)){
           this->bm[k] = v;
    }
}

std::string bimap::getKey(int v)
{
    for(auto i = this->bm.begin(); i != this->bm.end(); ++i){
        if(i->second == v)
            return i->first;
    }
    return "no encontrado";
}

int bimap::getValue(std::string k)
{
    if(this->bm.count(k))
        return this->bm[k];
    return NULL;
}

void bimap::display()
{
    for(auto i = this->bm.begin();i != this->bm.end();++i){
        std::cout << "Clave: " << i->first << "     Valor: " << i->second << "\n";
    }
}
