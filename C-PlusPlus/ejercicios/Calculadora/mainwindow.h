#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "calculadora.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_uno_clicked();

    void on_dos_clicked();

    void on_tres_clicked();

    void on_cuatro_clicked();

    void on_cinco_clicked();

    void on_seis_clicked();

    void on_siete_clicked();

    void on_ocho_clicked();

    void on_nueve_clicked();

    void on_cero_clicked();

    void on_suma_clicked();

    void on_resta_clicked();

    void on_igual_clicked();

    void on_division_clicked();

    void on_multiplicacion_clicked();

private:
    Ui::MainWindow *ui;
    Calculadora unaCalcu;
};
#endif // MAINWINDOW_H
