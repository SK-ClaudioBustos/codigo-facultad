#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <secondwindow.h>
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
    int controlarTamanioMapa(int dimension);
private slots:
    void on_lanzarSimulacion_clicked();
private:
    SecondWindow * ventanilla;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
