#include "pila_template.h"
template<class T>
Pila_Template<T>::Pila_Template()
{

}

template<class T>
void Pila_Template<T>::push(T nuevo)
{
    T * aux = new T[this->cantidad+1];
    for(int i = 0;i< this->cantidad;i++)
        aux[i] = this->pila[i];
    aux[this->cantidad] = nuevo;
    this->pila = aux;
    this->cantidad++;
}

template<class T>
T Pila_Template<T>::pop()
{   T aux = this->pila[this->cantidad-1];
    T * a = new T[this->cantidad+1];
    for(int i = 0;i< this->cantidad-1;i++)
        a[i] = this->pila[i];
    this->pila = a;
    this->cantidad--;
    return aux;
}

template<class T>
bool Pila_Template<T>::empty()
{
    return this->cantidad != 0;
}
