#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    sender = new QUdpSocket(this);
    receiver = new QUdpSocket(this);
//    receiver->bind(QHostAddress("192.168.114.1"),(qint16)8100);//绑定ip地址与端口，接收特定地址与端口的数据
      receiver->bind((qint16)8100);//主机上所有地址8100端口发送数据?实测只有192.168.114.1能收到
//    receiver->bind(QHostAddress::LocalHost,8100);
    connect(receiver,&QUdpSocket::readyRead,this,&Widget::processPendingDatagram);
}

Widget::~Widget()
{
    delete ui;
    delete sender;
    delete receiver;
}

void Widget::processPendingDatagram(){
    QByteArray datagram;
    datagram.resize(receiver->pendingDatagramSize());
    QHostAddress cliAddr;
    receiver->readDatagram(datagram.data(),datagram.size(), &cliAddr);
    ui->textBrowser->append(datagram);
    qDebug()<<cliAddr.toString();
}

void Widget::on_pushButton_clicked()
{
    QByteArray datagram = (ui->lineEdit->text()).toUtf8();
//固定地址，端口发送数据报
//    QString ip = "192.168.114.1";
//    sender->writeDatagram(datagram,QHostAddress(ip),8200);
//区域网，8100端口广播
    sender->writeDatagram(datagram, QHostAddress::Broadcast,8100);
    qDebug() << QHostAddress::LocalHost;
}
