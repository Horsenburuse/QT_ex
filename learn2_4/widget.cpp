#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->textEdit->hide();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_toggled(bool checked)
{
    ui->textEdit->setVisible(checked);
    if(checked)
        ui->pushButton->setText(tr("隐藏可拓展窗口"));
    else
        ui->pushButton->setText(tr("显示可拓展窗口"));
}
