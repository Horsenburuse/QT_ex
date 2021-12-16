#include "overdlg.h"
#include "QVBoxLayout"
#include <QToolButton>
#include <QPainter>
#include <QPixmap>

overdlg::overdlg(QWidget *parent) : QWidget(parent)
{
    setMinimumSize(400,400);
    button_restart = new QPushButton("再来一局");
    button_exit = new QPushButton("不玩了！！！");
    button_restart->setMinimumSize(50,100);
    button_exit->setMinimumSize(50,100);
    QVBoxLayout *VBox = new QVBoxLayout();
    VBox->addWidget(button_restart);
    VBox->addWidget(button_exit);
    setLayout(VBox);

    connect(button_restart,&QToolButton::clicked,[&](){
        emit signalRestart();
    });

    connect(button_exit,&QToolButton::clicked,[&](){
        emit signalExit();
    });

}

void overdlg::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(rect(),QPixmap(":/image/images/1.jpg"),QRect());
    update();
}
