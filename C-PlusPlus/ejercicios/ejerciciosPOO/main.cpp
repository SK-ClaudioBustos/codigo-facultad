#include <iostream>
#include "fraccion.h"
using namespace std;
/*
Ejercicio 4
Escriba 3 funciones sobrecargando el nombre intercambio(..) de modo que cada una
de ellas pueda ser invocada y produzca el intercambio de 2 datos que se pasan
como parámetros: 2 datos de tipo char, 2 datos enteros, dos arreglos de flotantes.

//muy poco util
void intercambio(char &e1,char &e2){
    char aux = e1;
    e1  = e2;
    e2  = aux;
}

void intercambio(int &e1,int &e2){
    int aux = e1;
    e1 = e2;
    e2 = aux;
}

void intercambio(float e1[],float e2[],int tam){

    float aux[tam];

    for(int i = 0; i<tam ; i++){
        aux[i] = e1[i];
    }

    for(int i = 0; i<tam ; i++){
        e1[i] = e2[i];
    }

    for(int i = 0; i<tam ; i++){
        e2[i] = aux[i];
    }

}


Ejercicio 10
Hacer un programa que calcule y muestre el total a pagar por la compra de
pantalones, se debe pedir como entrada el valor del pantalón y la cantidad de
pantalones comprados, además si se compra 5 pantalones o mas se le aplica un
descuento de 25% al monto total a pagar y si son menos de 5 pantalones el descuento
es de 10% al monto total a pagar..



float calcularPago(float val,int cant){
    float resultado = 0.0;

    if ( cant >= 5 )
        resultado = val - (val * 0.25);
    else
        resultado = val - (val * 0.10);

    return resultado;
}


float pedirValores(){
    float val = 0.0;
    cout<<"Ingrese el valor del pantalon: ";
    cin>>val;
    int cant;
    cout<<"Ingrese la cantidad de pantalones comprados";
    cin>>cant;

    return calcularPago(val,cant);
}

//Dado un valor numérico ingresado por pantalla, indicar si el número es primo o no.

bool verificarPrimo(int nro){

    if (nro%2 == 0)
        if (nro%3 == 0)
            if(nro%5 == 0)
                if(nro%7 == 0)
                    if(nro%11 == 0)
                        return false;

    return true;
}

La serie de Fibonacci se calcula de la forma siguiente:

0   1   2   3   4   5   6
1 + 1 + 2 + 3 + 5 + 8 + 13 +…

Donde cada término i se calcula sumando los 2 anteriores: ti=ti-1+ti-2, y los 2 términos
iniciales valen 1.
Escriba una función recursiva para calcular la serie de Fibonacci y luego escriba un programa
cliente que la utilice

long fibonacciIterativa(long nro)
{
    if(nro == 1 || nro == 0)
        return 1;

    long f = 0;
    long f0 = 1;
    long f1 = 1;

    for(int i = 1; i < nro ; i++){
          f = f1 + f0;
          f0 = f1;
          f1 = f;
    }
    return f;
}

Ejercicio​ 14
Escriba una función recursiva para calcular el máximo común divisor (m.c.d.)de dos números
enteros dados aplicando las propiedades recurrentes.
Si a>b, entonces m.c.d.(a,b) = m.c.d.(a-b,b)
Si a<b, entonces m.c.d.(a,b) = m.c.d.(a, b-a)
Si a=b, entonces m.c.d.(a,b) = m.c.d.(b,a)=a=b


int mcd(int a,int b){
    if(a == b)
        return a;
    else
        if(a > b)
            return mcd(a-b,b);
        else
            return mcd(a,b-a);
}



Realice una función que dado un vector dinámico de enteros, remueva la primera
coincidencia de un elemento pasado por parámetro.


bool remove(int *&vec,int tam,int element) {
    int i = -1;
    int z = 0;
    for(z = 0; z < tam; z++) {
        if(vec[z] == element){
            i = z;
            break;
        }
    }

    if(i != -1){
        int * aux = new int[tam-1];
        int x = 0;
        for(z = 0;z<tam;z++){
            if(z != i){
                aux[x] = vec[z];
                x++;
            }
        }
        delete []vec;
        vec = aux;
    }
    else
       return false;

    return true;
}



//ejercicio: hacer un programa que elimine las ocurrencias en una palabra
int contar(char * palabra){
    int cont = 0;
    while(palabra[cont] != '\0'){
        cont++;
    }
    return cont;
}


int ocurrencias(char * palabra,char c){
    int ocurrencias = 0,i = 0;
    while(palabra[i] != '\0'){
        if(palabra[i] == c){
            ocurrencias++;
        }
        i++;
    }
    return ocurrencias;
}

char * eliminar(char * palabra,char caractEliminar){
    int ocurr = ocurrencias(palabra,caractEliminar);
    char * palabraNueva;
    if(ocurr == 0)
        return palabra;
    else{
        int tam = contar(palabra);
        int z = 0;
        palabraNueva = new char[tam-ocurr];
        for(int i = 0;i < tam;i++){
            if(palabra[i] != caractEliminar){
            palabraNueva[z] = palabra[i];
            z++;
            }
        }
    }
    return palabraNueva;
}

//ejercicio:hacer un programa que al pasar un indice donde indique en que parte se cortara la palabra
char * cortar(char * p,int corte){
   int tam = contar(p);
   if(corte >= tam){
       return p;
   }
   int tamNuevo = tam - corte;
   char * aux = new char[tamNuevo];
   int j = corte;
   for(int i = 0;i < tamNuevo; i++){
       aux[i] = p[j];
       j++;
   }
   return aux;
}
*/



int main()
{
    Fraccion unaFraccion1(4,3);
    Fraccion unaFraccion2(2,4);
    Fraccion aux = unaFraccion1.suma(unaFraccion2);
    cout << aux.getNumerador() << "/" << aux.getDenominador() << endl;
    aux.simplificar();
    cout << aux.getNumerador() << "/" << aux.getDenominador() << endl;
    return 0;
}
