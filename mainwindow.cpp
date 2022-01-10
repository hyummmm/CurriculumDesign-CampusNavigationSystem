#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "info.h"
#include "path.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("CSU新校区导航系统");
    setFixedSize(1000,600);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_InfomationInterfaceButton_clicked()
{
    Info info;
    info.exec();

}


void MainWindow::on_PathInterfaceButton_clicked()
{
    Path p;
    p.exec();

}


void MainWindow::on_ExitInterfaceButton_clicked()
{
    close();
}

