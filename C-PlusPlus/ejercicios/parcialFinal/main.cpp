#include <iostream>
#include "gestorvinos.h"
#include "vino.h"
#include "mesa.h"
#include "premium.h"
#include "especial.h"
#include <map>
using namespace std;

int main()
{
    GestorVinos unGestor;
    Vino * v1 = new Mesa(12,'M',1500,2020,120);
    Vino * v2 = new Premium(12,'P',2000,2022,200);
    Vino * v3 = new Premium(12,'P',2000,2022,200);
    Vino * v4 = new Especial(12,'E',1500,2020,320);

    unGestor.setVino(v1);
    unGestor.setVino(v2);
    unGestor.setVino(v3);
    unGestor.setVino(v4);

    map<int,int> aux =  unGestor.topFive();

   for(auto i = aux.begin();i != aux.end();++i){
        cout << i->first << " " << i->second << "\n";
   }

    return 0;
}
