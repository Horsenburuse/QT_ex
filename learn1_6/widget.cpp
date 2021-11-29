#include "widget.h"
#include "QVBoxLayout"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setFixedSize(640,480);

    bt = new QPushButton("登录", this);
    le = new QLineEdit;

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox ->addWidget(le);
    vbox ->addWidget(bt);
    this->setLayout(vbox);

    //    bt ->setStyleSheet("QPushButton{background-color:blue};");
    //    bt ->setGeometry(300,400,100,50);
    //    bt ->setStyleSheet("QPushButton{color:blue;};");
}
Widget::~Widget()
{

}
