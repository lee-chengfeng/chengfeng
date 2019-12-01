#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    custom = new AnalogClock(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}
