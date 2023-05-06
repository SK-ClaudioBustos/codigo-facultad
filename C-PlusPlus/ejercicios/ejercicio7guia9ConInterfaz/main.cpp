#include "mainwindow.h"
#include <QApplication>
/*
7. Realice un programa que mantenga los datos de bienes de una empresa. Todo bien tiene un
código único que permite el acceso rápido y un valor determinado. El software debe permitir
cargar un bien, buscarlo por código y calcular el valor total de los bienes. Utilice Qt y stl.
*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
