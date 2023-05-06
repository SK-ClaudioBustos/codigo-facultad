#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ventanilla = new SecondWindow(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::controlarTamanioMapa(int dimension){
    if(dimension < 10)
        return 30;
    return dimension;
}

void MainWindow::on_lanzarSimulacion_clicked()
{
    int filas,columnas,cantPastizales,duracionTiempo,cantPoblacionA,cantPoblacionB;
    filas = controlarTamanioMapa(this->ui->cantidadFilas->value());
    columnas = controlarTamanioMapa(this->ui->cantidadColumnas->value());
    cantPastizales = this->ui->cantidadPastizales->value();
    duracionTiempo = this->ui->cantidadSegundos->value();
    cantPoblacionA = this->ui->cantidadPoblacionA->value();
    cantPoblacionB = this->ui->cantidadPoblacionB->value();
    this->ventanilla->inicializarSimulador(filas,columnas,cantPastizales,duracionTiempo,cantPoblacionA,cantPoblacionB);
    this->hide();
    this->ventanilla->show();
}
