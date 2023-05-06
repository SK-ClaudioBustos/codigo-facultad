#include "gestorvinos.h"
GestorVinos::GestorVinos()
{

}

void GestorVinos::recuperarInfoVinos()
{
    VinoData aux;   Vino * ptr;
    ifstream file("vinos.dat",ios::binary|ios::in);
    while(file.eof()){
        file.read((char*)&aux,sizeof(VinoData));
        if(aux.tipo == 'M')
            ptr = new Mesa(aux.nro,aux.tipo,aux.cantidadLitros,aux.anioProduccion,120);
        if(aux.tipo == 'P')
            ptr = new Premium(aux.nro,aux.tipo,aux.cantidadLitros,aux.anioProduccion,200);
        if(aux.tipo == 'E')
            ptr = new Especial(aux.nro,aux.tipo,aux.cantidadLitros,aux.anioProduccion,320);
        this->setVino(ptr);
    }
    file.close();
}

int GestorVinos::getCantLitros(int anio)
{   int cantLitrosTotales = 0;
    int resta = 0;
    for(int i = 0; i < (int)this->vinos.size();++i){
        resta = anio - this->vinos[i]->getA();
        if(this->vinos[i]->getT() == 'M'){
            if(resta>1)
                cantLitrosTotales += this->vinos[i]->getL();
        }
        if(this->vinos[i]->getT() == 'P'){
            if(resta>2)
                cantLitrosTotales += this->vinos[i]->getL();
        }
        if(this->vinos[i]->getT() == 'E'){
            if(resta>3)
                cantLitrosTotales += this->vinos[i]->getL();
        }
    }
    return cantLitrosTotales;
}

int GestorVinos::getMontoTotalLitros(int anio)
{
        int monto = 0;
        int resta = 0;
        for(int i = 0; i < (int)this->vinos.size();++i){
            resta = anio - this->vinos[i]->getA();
            if(this->vinos[i]->getT() == 'M'){
                if(resta>1)
                    monto += this->vinos[i]->getPrecio();
            }
            if(this->vinos[i]->getT() == 'P'){
                if(resta>2)
                    monto += this->vinos[i]->getPrecio();
            }
            if(this->vinos[i]->getT() == 'E'){
                if(resta>3)
                    monto += this->vinos[i]->getPrecio();
            }
        }
        return monto;
}

void GestorVinos::crearInforme()
{
    ofstream file("informe.txt");
    int monto2020 = 0;
    int monto2021 = 0;
    int monto2022 = 0;
    int monto2023 = 0;

    int litros2020 = 0;
    int litros2021 = 0;
    int litros2022 = 0;
    int litros2023 = 0;

    for(int i = 0; i < (int)this->vinos.size();++i){
        if(this->vinos[i]->getA() == 2020){
            litros2020 += this->vinos[i]->getL();
            monto2020 += this->vinos[i]->getPrecio();
        }
        if(this->vinos[i]->getA() == 2021){
            litros2021 += this->vinos[i]->getL();
            monto2021 += this->vinos[i]->getPrecio();
        }
        if(this->vinos[i]->getA() == 2022){
            litros2022 += this->vinos[i]->getL();
            monto2022 += this->vinos[i]->getPrecio();
        }
        if(this->vinos[i]->getA() == 2023){
            litros2023 += this->vinos[i]->getL();
            monto2023 += this->vinos[i]->getPrecio();
        }
    }
    file << "2020 " << litros2020 << " " << monto2020 << "\n";
    file << "2021 " << litros2021 << " " << monto2021 << "\n";
    file << "2022 " << litros2022 << " " << monto2022 << "\n";
    file << "2023 " << litros2023 << " " << monto2023 << "\n";
    file.close();
}

map<int,int> GestorVinos::topFive()
{   //clave: año, valor: litros
    map<int,int> anios;
    int anioPivote = 0;
    int cont = 0;
    for(int j = 0; j < (int)this->vinos.size();++j){
       if(anios.count(this->vinos[j]->getA()) == 0 && cont != 5){
           anioPivote = this->vinos[j]->getA();
           for(int i = 0; i < (int)this->vinos.size();++i){
               if(this->vinos[i]->getA() == anioPivote){
                   anios[anioPivote] += this->vinos[i]->getL();
                   cont++;
               }
           }
       }
    }
    return anios;
}

void GestorVinos::getMasVinos(int anio)
{
        int cantVinos = 0;
        int resta = 0;
        for(int i = 0; i < (int)this->vinos.size();++i){
            resta = anio - this->vinos[i]->getA();
            if(this->vinos[i]->getT() == 'M'){
                if(resta>1)
                    cantVinos += 1;
            }
            if(this->vinos[i]->getT() == 'P'){
                if(resta>2)
                    cantVinos += 1;
            }
            if(this->vinos[i]->getT() == 'E'){
                if(resta>3)
                    cantVinos += 1;
            }
        }
}

void GestorVinos::betterYear()
{
    int mejorAnio = 0;
    float cantMejorAnio = 0;
    int aux = 0;
    for(int i = 0; i < (int)this->vinos.size();++i){
        aux = this->getMontoTotalLitros(this->vinos[i]->getA());
        if(aux > cantMejorAnio){
            cantMejorAnio = aux;
            mejorAnio = this->vinos[i]->getA();
        }
    }
    cout<<"El mejor Año con cantidad de vinos vendidos fue: " << mejorAnio << "\n";
}

void GestorVinos::mayorMontoVenta()
{
    int mejorAnio = 0;
    float montoMejorAnio = 0;
    int aux = 0;
    for(int i = 0; i < (int)this->vinos.size();++i){
        aux = this->getMontoTotalLitros(this->vinos[i]->getA());
        if(aux > montoMejorAnio){
            montoMejorAnio = aux;
            mejorAnio = this->vinos[i]->getA();
        }
    }
    cout<<"El mejor Año con monto de venta fue: " << mejorAnio << "\n";
}
