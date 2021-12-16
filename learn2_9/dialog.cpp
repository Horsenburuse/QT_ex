#include "dialog.h"
#include "ui_dialog.h"
#include <QToolButton>
#include <QPainter>
#include <QPixmap>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->pushButton_start,&QToolButton::clicked,[&](){
        emit signalStart();
    });
    connect(ui->pushButton_close,&QToolButton::clicked,[&](){
        emit signalExit();
    });
    this->paintEvent();
}



Dialog::~Dialog()
{
    delete ui;
}


void Dialog::paintEvent()
{
    QPainter painter(this);
    painter.drawPixmap(rect(),QPixmap(":/image/images/open.jpg"),QRect());
    update();

}
