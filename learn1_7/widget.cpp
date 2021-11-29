#include "widget.h"
#include "QVBoxLayout"
#include "QHBoxLayout"
#include "QGridLayout"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setFixedSize(640,480);

    bt = new QPushButton("读", this);
    le = new QLineEdit;
    x = new QTextToSpeech;

//    垂直排列
//    QVBoxLayout *vbox = new QVBoxLayout;
//    vbox ->addWidget(le);
//    vbox ->addWidget(bt);
//    this->setLayout(vbox);

//    水平排列
//    QHBoxLayout *Hbox = new QHBoxLayout;
//    Hbox ->addWidget(le);
//    Hbox ->addWidget(bt);
//    this->setLayout(Hbox);

//    网格排列
      QGridLayout *Gbox = new QGridLayout;
      Gbox ->addWidget(le);
      Gbox ->addWidget(bt);
      this->setLayout(Gbox);

    connect(bt, SIGNAL(clicked(bool)),this,SLOT(XXX()) );
    //    bt ->setStyleSheet("QPushButton{background-color:blue};");
    //    bt ->setGeometry(300,400,100,50);
    //    bt ->setStyleSheet("QPushButton{color:blue;};");
}
Widget::~Widget()
{

}
