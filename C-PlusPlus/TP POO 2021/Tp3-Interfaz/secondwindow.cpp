#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <QTimer>
#include<iostream>
#include <QMessageBox>
#include <Qt>
using namespace std;
SecondWindow::SecondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
    setWindowTitle("Mostrando Mapa");
    this->timer = new QTimer(this);
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::inicializarSimulador(int filas, int columnas, int cantPastizales, int duracionTiempo, int cantPoblacionA, int cantPoblacionB)
{
    int rpta = 0;
    bool flag = false;
    if(unSimulador.verificarExistenciaArchivoConfig()){
        int rpta = QMessageBox::question(this,"Cargar ultima configuracion ingresada","Desea cargar la ultima configuracion ingresada?(Y/N): ",QMessageBox::Yes | QMessageBox::No,QMessageBox::No);
        if(rpta == QMessageBox::Yes){
            vector<int>config = unSimulador.recuperarConfiguracionIngresada();
            filas= config[0];
            columnas = config[1];
            cantPastizales= config[2];
            duracionTiempo = config[3];
            cantPoblacionA = config[4];
            cantPoblacionB = config[5];
        }
    }
    if(unSimulador.verificarExistenciaSimulacionGuardada()){
         rpta = QMessageBox::question(this,"Recuperar Simulacion","Desea cargar la simulacion guardada?: ",QMessageBox::Yes | QMessageBox::No,QMessageBox::No);
         if(rpta == QMessageBox::Yes){
             flag = true;
         }
    }
    if(flag){
        unSimulador.recuperarSimulacionGuardada();
        diaActual = unSimulador.recuperarDiaActual();
        filas = unSimulador.getN();
        columnas = unSimulador.getM();
    }
    else{
        unMapa = new Mapa(filas,columnas,cantPastizales);
        unSimulador.setConfiguracion(unMapa,cantPoblacionA,cantPoblacionB,duracionTiempo);
        unMapa->llamarFuncionesMapa();
    }
    this->ui->indicadorDiasLabel->setText("Dia " + QString::number(this->diaActual));
    this->ui->segundosPasadosLabel->setText("0");
    unSimulador.inicializacionPoblaciones();
    duracionTiempo = unSimulador.getDuracionTiempo();
    this->reservarLabels(filas,columnas);
}

void SecondWindow::reservarLabels(int filas, int columnas)
{
    int ** matriz = this->unSimulador.getMatriz();
    QString aux;
    this->labels = new QLabel**[filas];
    for (int i = 0; i < filas; i++) {
        labels[i] = new QLabel*[columnas];
        for (int j = 0; j < columnas; j++){
            labels[i][j] = new QLabel();
            if(matriz[i][j] == 4)
                aux = "B";//poblacion de ciervos de tipo B
            if(matriz[i][j] == 3)
                aux = "A";//poblacion de ciervos de tipo A
            if(matriz[i][j] == 2)
                aux = "p";//pastizales
            if(matriz[i][j] == 0)
                aux = "+";//montañas
            if(matriz[i][j] == 1)
                aux = " ";//mesetas
            labels[i][j]->setText(aux);
            this->ui->gridLayout->addWidget(labels[i][j] ,i,j);
        }
    }
}

void SecondWindow::actualizarMatriz()
{
    int ** aux = this->unSimulador.getMatriz();
    QString aux2;
    int n = this->unSimulador.getN();
    int m = this->unSimulador.getM();

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            this->labels[i][j]->clear();

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if(aux[i][j] == 4)
                aux2 = "B";//poblacion de ciervos de tipo B
            if(aux[i][j] == 3)
                aux2 = "A";//poblacion de ciervos de tipo A
            if(aux[i][j] == 2)
                aux2 = "p";//pastizales
            if(aux[i][j] == 0)
                aux2 = "+";//montañas
            if(aux[i][j] == 1)
                aux2 = " ";//mesetas
            labels[i][j]->setText(aux2);
        }
    }
}

void SecondWindow::contadorSegundos(){
    this->timer->connect(timer, SIGNAL(timeout()), this, SLOT(timeout()));
    this->timer->setInterval(1000);
    this->timer->start();
}

void SecondWindow::timeout()
{
    if(this->segundosPasados<= this->unSimulador.getDuracionTiempo()){
        this->ui->segundosPasadosLabel->setText(this->ui->segundosPasadosLabel->text() + QString::number(this->segundosPasados) + " ");
        this->segundosPasados++;
    }
    else{
        this->timer->stop();
        this->ui->pararSimulacionButton->setEnabled(true);
        this->ui->seguirSimulacionButton->setEnabled(true);
    }
}

void SecondWindow::on_seguirSimulacionButton_clicked()
{
    this->ui->seguirSimulacionButton->setEnabled(false);
    this->ui->pararSimulacionButton->setEnabled(false);

    this->ui->segundosPasadosLabel->clear();
    this->segundosPasados = 0;
    this->diaActual++;
    this->ui->indicadorDiasLabel->setText("Dia " + QString::number(this->diaActual));

    unSimulador.movimientoDePoblaciones();
    unSimulador.controlDePoblacion();
    unSimulador.controlarPastizales();
    unSimulador.controlarRelacionesPoblacion();
    this->actualizarMatriz();
    this->contadorSegundos();
}

void SecondWindow::on_pararSimulacionButton_clicked()
{
    int rptaUsuario = QMessageBox::question(this,"Guardar Simulacion","¿Desea Guardar la simulacion?",QMessageBox::Save |QMessageBox::Discard);
    unSimulador.guardarConfiguracionIngresada();
    if(rptaUsuario == QMessageBox::Save)
               unSimulador.guardarSimulacion(diaActual);    
    this->close();
}
