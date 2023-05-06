#ifndef BIMAP_H
#define BIMAP_H
#include <map>

class bimap
{
    std::map<std::string,int> bm;
public:
    bimap();
    bool isValue(int);
    void set(std::string,int);
    std::string getKey(int);
    int getValue(std::string);
    void display();
};

#endif // BIMAP_H
