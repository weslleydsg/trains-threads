#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "train.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


public slots:
    void updateInterface(int,int,int);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;

    //Cria os objetos TRAIN's
    Train *train1;
    Train *train2;
    Train *train3;
    Train *train4;
    Train *train5;
};

#endif // MAINWINDOW_H
