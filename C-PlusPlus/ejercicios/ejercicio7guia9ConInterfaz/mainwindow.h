#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "gestor_bienes.h"
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
    void on_agregarButton_clicked();

    void on_calcularTotalButton_clicked();

    void on_buscarButton_clicked();

private:
    Ui::MainWindow *ui;
    Gestor_Bienes unGestor;
};
#endif // MAINWINDOW_H
