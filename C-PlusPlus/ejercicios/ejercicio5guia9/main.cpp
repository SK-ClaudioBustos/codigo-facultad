#include <iostream>
#include "bimap.h"
/*
5. Realice una clase template que modele un bimap (un mapa que permita utilizar la key para
llegar al valor o el valor para llegar a la key) utilice stl. Tenga en cuenta que tanto el valor
como la key van a tener que ser únicos.
*/
using namespace std;

int main()
{
    bimap unBM;
    unBM.set("claudio",20);
    unBM.set("marcos",40);
    unBM.set("claudio",30);
    unBM.set("angelina",20);
    cout << unBM.getKey(40) <<"\n";
    cout << unBM.getValue("claudio") <<"\n";
    //unBM.display();
    return 0;
}
