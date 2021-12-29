#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "tcpcilent.h"
#include "tcpserver.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_Cilent_button_clicked();


    void on_Server_button_clicked();

private:
    Ui::Widget *ui;
    tcpcilent * tcp_cilent = nullptr;
    tcpserver * tcp_server = nullptr;

};
#endif // WIDGET_H
