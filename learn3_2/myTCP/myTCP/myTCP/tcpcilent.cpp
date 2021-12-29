#include "tcpcilent.h"
#include "ui_tcpcilent.h"

tcpcilent::tcpcilent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tcpcilent)
{
    ui->setupUi(this);
    cilentSocket = new QTcpSocket(this);
    connect(cilentSocket,&QTcpSocket::readyRead,this,&tcpcilent::readMessage);
    connect(cilentSocket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(QAbstractSocket::SocketError));
}

void tcpcilent::newConnect()
{
    blocksize = 0;
    cilentSocket->abort();
    cilentSocket->connectToHost(ui->lineEdit->text(),ui->lineEdit_2->text().toInt());
    if(cilentSocket->waitForConnected(1000))
        qDebug()<<tr("连接成功");
    else
        qDebug()<<tr("连接失败");
    qDebug()<<ui->lineEdit->text();
    qDebug()<<ui->lineEdit_2->text();
}
void tcpcilent::readMessage()
{
 #if 0
    QDataStream in(cilentSocket);
    in.setVersion(QDataStream::Qt_5_14);
    if(blocksize == 0){
        if(cilentSocket->bytesAvailable()<(int)sizeof(quint16))
            return;
        in >> blocksize;
    }
    if(cilentSocket->bytesAvailable()<(int)sizeof(quint16))
        return;
    in>>message;
    qDebug()<<message;
    ui->textBrowser->append(message);
#endif
    QByteArray receive_block = cilentSocket->readAll();
    qDebug()<<receive_block;
    ui->textBrowser->append(receive_block);
}

void tcpcilent::sendMessage(){
    QByteArray send_block = ui->lineEdit_3->text().toUtf8();
    cilentSocket->write(send_block);
}

void tcpcilent::displayError(QAbstractSocket::SocketError){
    qDebug()<< cilentSocket->errorString();

}


tcpcilent::~tcpcilent()
{
    delete ui;
}

void tcpcilent::on_pushButton_clicked()
{
    newConnect();
}

void tcpcilent::on_pushButton_2_clicked()
{
    sendMessage();
}
