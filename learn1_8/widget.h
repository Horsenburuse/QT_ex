#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QDebug>
#include <QtTextToSpeech/QTextToSpeech>

class Widget : public QWidget
{
    Q_OBJECT

public slots:
    void XXX()
    {
        x->say(le->text());
        qDebug() <<"4xxxxxxxxxx";
    }
    void XX()
    {
        x->say(bt1->text());
        qDebug() <<"3xxxxxxxxxx";
    }

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    QPushButton *bt;
    QPushButton *bt1;

    QLineEdit *le;
    QTextToSpeech *x;
};

#endif // WIDGET_H
