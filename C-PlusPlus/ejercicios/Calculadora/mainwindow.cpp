#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Calculadora");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_uno_clicked()
{
    this->ui->pantallita->display(this->unaCalcu.inputNros("1"));
}

void MainWindow::on_dos_clicked()
{
    this->ui->pantallita->display(this->unaCalcu.inputNros("2"));
}

void MainWindow::on_tres_clicked()
{
    this->ui->pantallita->display(this->unaCalcu.inputNros("3"));
}

void MainWindow::on_cuatro_clicked()
{
    this->ui->pantallita->display(this->unaCalcu.inputNros("4"));
}

void MainWindow::on_cinco_clicked()
{
    this->ui->pantallita->display(this->unaCalcu.inputNros("5"));
}

void MainWindow::on_seis_clicked()
{
    this->ui->pantallita->display(this->unaCalcu.inputNros("6"));
}

void MainWindow::on_siete_clicked()
{
    this->ui->pantallita->display(this->unaCalcu.inputNros("7"));
}

void MainWindow::on_ocho_clicked()
{
    this->ui->pantallita->display(this->unaCalcu.inputNros("8"));
}

void MainWindow::on_nueve_clicked()
{
    this->ui->pantallita->display(this->unaCalcu.inputNros("9"));
}

void MainWindow::on_cero_clicked()
{
    this->ui->pantallita->display(this->unaCalcu.inputNros("0"));
}

void MainWindow::on_suma_clicked()
{
    this->unaCalcu.setOperacion("+");
    this->ui->pantallita->display("");
}

void MainWindow::on_resta_clicked()
{
    this->unaCalcu.setOperacion("-");
    this->ui->pantallita->display("");
}

void MainWindow::on_igual_clicked()
{
    double resultado = this->unaCalcu.output();
    this->ui->pantallita->display(resultado);
}

void MainWindow::on_division_clicked()
{
    this->unaCalcu.setOperacion("/");
    this->ui->pantallita->display("");
}

void MainWindow::on_multiplicacion_clicked()
{
    this->unaCalcu.setOperacion("*");
    this->ui->pantallita->display("");
}
