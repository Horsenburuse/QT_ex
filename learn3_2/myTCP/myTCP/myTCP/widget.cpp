#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_Cilent_button_clicked()
{
    if(ui->Cilent_button->text() == tr("TCP_client open"))
    {
        tcp_cilent = new tcpcilent();
        tcp_cilent->show();
        ui->Cilent_button->setText(tr("TCP_client close"));
    }
    else
    {
        tcp_cilent->close();
        ui->Cilent_button->setText(tr("TCP_client open"));
    }
}

void Widget::on_Server_button_clicked()
{
    if(ui->Server_button->text() == tr("TCP_server open"))
    {
        tcp_server = new tcpserver();
        tcp_server->show();
        ui->Server_button->setText(tr("TCP_serve close"));
    }
    else
    {
        tcp_server->close();
        ui->Server_button->setText(tr("TCP_server open"));
    }

}
