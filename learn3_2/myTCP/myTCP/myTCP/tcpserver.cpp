#include "tcpserver.h"
#include "ui_tcpserver.h"
#include <QTimer>
#include <typeinfo>

tcpserver::tcpserver(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tcpserver)
{
    ui->setupUi(this);
    tcpServer = new QTcpServer(this);
    if(!tcpServer->listen(QHostAddress::Any,8000)){
        qDebug()<<tcpServer->errorString();
        close();
    }
    connect(tcpServer,&QTcpServer::newConnection,this,[&](){
        cilentSocket = tcpServer->nextPendingConnection();
        qDebug()<<cilentSocket;
        sendMessage(cilentSocket);
        connect(cilentSocket,&QTcpSocket::readyRead,[&](){
            readMessage(cilentSocket);
            qDebug()<<cilentSocket;
        });
    });
}


void tcpserver::sendMessage(QTcpSocket* clientConnection)
{   //开辟发送数据,接收数据缓存区
    QByteArray send_block;
    QDataStream out(&send_block,QIODevice::WriteOnly);

//设置数据流版本格式
    out.setVersion(QDataStream::Qt_5_14);
    out<<(quint16)0;
    out << tr("hello TCP!!!").toUtf8();
    out.device()->seek(0);
    out<<(quint16)(send_block.size()-sizeof (quint16));

//获取建立连接的套接字
    connect(clientConnection,&QTcpSocket::disconnected,clientConnection,&QTcpSocket::deleteLater);
    clientConnection->write(send_block);
//    clientConnection->disconnectFromHost();
    ui->label->setText(tr("发送数据成功！！"));
}

void tcpserver::readMessage(QTcpSocket* clientConnection)
{
//    QDataStream in(clientConnection);
    QByteArray receive_block = clientConnection->readAll();
//    in.setVersion(QDataStream::Qt_5_14);
//    if(blocksize == 0){
//        if(clientConnection->bytesAvailable()<(int)sizeof(quint16))
//            return;
//        in >> blocksize;
//    }
//    if(clientConnection->bytesAvailable()<(int)sizeof(quint16))
//        return;
    if(clientConnection->bytesAvailable())
        qDebug()<<clientConnection;
//    QString j = typeid(in).name();
//    qDebug()<<j;
//    in>>message;
//    qDebug()<<in;
    message = receive_block;
    qDebug()<<message;
    ui->textBrowser->append(message);
}

tcpserver::~tcpserver()
{
    delete ui;
}

void tcpserver::on_pushButton_clicked()
{
//    connect(cilentSocket,&QTcpSocket::readyRead,[&](){

//        readMessage(cilentSocket);
//        qDebug()<<cilentSocket;
//    });
}
