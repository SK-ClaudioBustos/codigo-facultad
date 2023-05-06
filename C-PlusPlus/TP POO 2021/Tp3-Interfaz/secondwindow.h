#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H
#include <QSpinBox>
#include <QDialog>
#include <QLabel>
#include "simulador.h"
namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();
    void inicializarSimulador(int filas, int columnas, int cantPastizales, int duracionTiempo, int cantPoblacionA, int cantPoblacionB);
    void reservarLabels(int filas,int columnas);
    void contadorSegundos();
    void actualizarMatriz();
private slots:
    void timeout();
    void on_seguirSimulacionButton_clicked();
    void on_pararSimulacionButton_clicked();
private:
    QLabel *** labels;
    Ui::SecondWindow *ui;
    QTimer * timer;
    Simulador unSimulador;
    Mapa * unMapa;
    int segundosPasados = 1;
    int diaActual = 0;
};

#endif // SECONDWINDOW_H
