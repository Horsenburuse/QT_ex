#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QDialog>
#include <QtNetwork>


namespace Ui {
class tcpserver;
}
class QTcpServer;

class tcpserver : public QDialog
{
    Q_OBJECT

public:
    explicit tcpserver(QWidget *parent = nullptr);
    ~tcpserver();

private slots:
    void sendMessage(QTcpSocket* clientConnection);
    void readMessage(QTcpSocket* clientConnection);

    void on_pushButton_clicked();

private:
    Ui::tcpserver *ui;
    QTcpServer *tcpServer = nullptr;
    QTcpSocket *cilentSocket = nullptr;
    QByteArray message;
    quint16 blocksize;
};

#endif // TCPSERVER_H
