#include <iostream>
#include "pila_template.cpp"
using namespace std;

int main()
{
    Pila_Template<int> unaPila;
    unaPila.push(69);
    unaPila.push(42);
    unaPila.push(4);
    unaPila.push(2);
    while(unaPila.empty()){
        cout << unaPila.pop() << " ";
    }
    cout << endl;
    if(!unaPila.empty())
        cout << "Pila Vacia" << endl;
    cout << endl;
    return 0;
}
