#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bien.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_agregarButton_clicked()
{
    int codigo = this->ui->codigoLineEdit->text().toInt();
    float valor = this->ui->valorLineEdit->text().toFloat();
    Bien nuevo(codigo,valor);
    this->unGestor.cargarBien(nuevo);
    this->ui->codigoLineEdit->setText("");
    this->ui->valorLineEdit->setText("");
}

void MainWindow::on_calcularTotalButton_clicked()
{
    float total = this->unGestor.calcularValorTotal();
    this->ui->mostrarTotalLabel->setText(QString::number(total));
}

void MainWindow::on_buscarButton_clicked()
{   int codigo = this->ui->bienParaBuscarLineEdit->text().toInt();
    if(this->unGestor.validarBusqueda(codigo)){
        Bien aux = this->unGestor.buscarBien(codigo);
        this->ui->bienEncontradoLabel->setText(QString::number(aux.getValor()));
    }
    else{
     this->ui->bienEncontradoLabel->setText("Bien no encontrado");
    }
}
