#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTimer>
#include <QTime>
#include <QString>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
#if LINE_I
    Line = new myLineEdit();
    Line->installEventFilter(this);
    QVBoxLayout *Vbox = new QVBoxLayout();
    Vbox->addWidget(Line);
    setLayout(Vbox);
#endif

#if CLK
    angle = 0;
    QTimer *T1 = new QTimer;
    connect(T1,&QTimer::timeout,[&](){
        angle+=6;
        update();
    });
    T1->start(1000);//设置溢出时间
#endif

#if LDC_C
    LCD_display = new QLCDNumber(this);
    LCD_display->setDigitCount(10);
    QHBoxLayout *Hbox = new QHBoxLayout();
    Hbox->addWidget(LCD_display);
    setLayout(Hbox);
    QTimer *T2 = new QTimer;
    connect(T2,&QTimer::timeout,this,&Widget::timerUp);
    T2->start(1000);//设置溢出时间
#endif

}

Widget::~Widget()
{
    delete ui;
#if LINE_I
    delete Line;
#endif
#if LDC_C
    delete LCD_display;
#endif
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    pos = event->pos();
    //update();
    qDebug() << "按下鼠标;"<<event->pos();
    qDebug() << "按下键为："<<event->button();
}

void Widget::mouseDoubleClickEvent(QMouseEvent *event)
{
    qDebug() << "双击鼠标;"<<event->pos();
}
void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "释放鼠标;"<<event->pos();
}
void Widget::mouseMoveEvent(QMouseEvent *event)
{
    posend = event->pos();
    update();
    qDebug() << "鼠标移动;"<<event->pos();
}
void Widget::keyPressEvent(QKeyEvent *event)
{
    qDebug()<< "Widget键盘按下事件"<<event->key();
}
bool Widget::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == Line){
        if(event->type() == QEvent::KeyPress)
            qDebug()<<tr("Widget事件过滤器");
    }
    return QWidget::eventFilter(obj,event);
}
void Widget::paintEvent(QPaintEvent*event)
{
 #if CLK
    QPainter t(this);
    t.translate(100,100);
    t.scale(0.5,0.5);
    t.drawEllipse(QPoint(0,0),100,100);
    t.rotate(angle);
    t.drawLine(QPoint(0,0),QPoint(100,0));
    t.drawText(0,150,"hello");
#endif
    qDebug()<<tr("绘画事件")<<pos<<posend<<event->rect();
}
void Widget::timerUp()
{
    QTime time = QTime::currentTime();
    QString time_value = time.toString("h:m:s");
    qDebug()<<time_value;
    LCD_display->display(time_value);
}

//-------------------------------------------------------
myLineEdit::myLineEdit(QWidget *parent):
    QLineEdit (parent)
{

}

myLineEdit::~myLineEdit()
{

}

void myLineEdit::keyPressEvent(QKeyEvent *event)
{
    qDebug() << tr("line有输入");
    QLineEdit::keyPressEvent(event);
    event->ignore();
}
bool myLineEdit::event(QEvent * event)
{
    if(event->type() == QEvent::KeyPress)
        qDebug()<<tr("myLineEdit的event()的函数");
    return QLineEdit::event(event);
}

