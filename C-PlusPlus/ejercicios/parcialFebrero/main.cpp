#include <iostream>
#include "administradorproductos.h"
#include "producto.h"
#include "compuesto.h"
#include "internacional.h"
#include "nacional.h"

using namespace std;

int main()
{
    AdministradorProductos unAdmin;
    Producto * p1 = new Internacional(1500,"termo");
    Producto * p2 = new Nacional(2500,"mate");
    Compuesto * p3 = new Compuesto("Conjunto Gamer");
    Producto * p4 = new Internacional(15000,"Mouse Gamer");
    Producto * p5 = new Internacional(15000,"CPU Gamer");

    p3->setProducto(p4);
    p3->setProducto(p5);

    unAdmin.setProducto(p1);
    unAdmin.setProducto(p2);
    unAdmin.setProducto(p3,2);

    unAdmin.mostrarProductos();
    cout<<"---------------\n";
    unAdmin.mostrarCodigo();
    cout<<endl;
    return 0;
}
