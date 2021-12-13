#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lcdNumber->setMinimumHeight(50);
    ui->lcdNumber->display(ui->widgetGameArea->getscore());
    connect(ui->widgetGameArea,&Game_area::signalUpadteScore,[&](){
        this->ui->lcdNumber->display(QString::number(ui->widgetGameArea->getscore()));
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    ui->widgetGameArea->KeyPressed(event->key());
    QMainWindow::keyPressEvent(event);
}
