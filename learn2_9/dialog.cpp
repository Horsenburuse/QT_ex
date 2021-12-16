#include "dialog.h"
#include "ui_dialog.h"
#include <QToolButton>

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
}


Dialog::~Dialog()
{
    delete ui;
}
