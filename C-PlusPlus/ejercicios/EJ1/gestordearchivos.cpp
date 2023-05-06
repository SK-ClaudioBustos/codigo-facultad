#include "gestordearchivos.h"
#include<fstream>
#include <iostream>
#include <string>
GestorDeArchivos::GestorDeArchivos(){

}

void GestorDeArchivos::TotLineas(string ruta){
    int i=0;
    ifstream archi;
    archi.open(ruta);
    string aux;
    if(archi.is_open()){
        while (getline(archi,aux)) {
            i++;
        }
    }
    archi.close();
    this->TotalLineas = i;
}

void GestorDeArchivos::LectorDeArchivos(string ruta){
    ifstream file(ruta);
    string line;
    if(file.is_open()){
        while(getline(file,line)){
            this->lineas.push_back(line);
        }
        file.close();
    }
}

void GestorDeArchivos::CreadorDeArchivos(int cantidadCortes){
    if(cantidadCortes > this->TotalLineas)
        return;
    string name = "a0.txt";
    int nro = 0;
    ofstream file;
    int k = (int)this->lineas.size()/cantidadCortes;
    int inicio = 0;
    int final = k;
    do{
        file.open(name);
        if(file.is_open())
            for(int i= inicio; i < final;++i)
                file << this->lineas[i] << "\n";
        else{
            cout<<"Error\n";
            exit(1);
        }
        file.close();
        nro++;
        name = "a" + to_string(nro) +".txt";
        inicio = final;
        cantidadCortes--;
        if(cantidadCortes == 1)
              final = this->lineas.size();
        else
              final += k;
    }while(cantidadCortes > 0);
}

int GestorDeArchivos::getTotalLineas()
{
    return TotalLineas;
}
