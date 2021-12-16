#include "overdlg.h"
#include "QVBoxLayout"
#include <QToolButton>

overdlg::overdlg(QWidget *parent) : QWidget(parent)
{
    button_restart = new QPushButton("再来一局");
    button_exit = new QPushButton("不玩了！！！");
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
