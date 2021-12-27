#ifndef TCPCILENT_H
#define TCPCILENT_H

#include <QDialog>
#include <QtNetwork>
#include <QTcpSocket>

namespace Ui {
class tcpcilent;
}

class tcpcilent : public QDialog
{
    Q_OBJECT

public:
    explicit tcpcilent(QWidget *parent = nullptr);
    ~tcpcilent();
private slots:
    void newConnect();
    void readMessage();
    void sendMessage();
    void displayError(QAbstractSocket::SocketError);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::tcpcilent *ui;
    QTcpSocket *cilentSocket = nullptr;
    QString message;
    quint16 blocksize;
};

#endif // TCPCILENT_H
