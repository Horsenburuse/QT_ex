#ifndef WIDGET_H
#define WIDGET_H

#define LDC_C  1
#define CLK    0
#define LINE_I 0


#include <QWidget>
#include <QLineEdit>
#include <QPainter>
#include <QTimer>
#include <QLCDNumber>

namespace Ui {
class Widget;
}

class myLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit myLineEdit(QWidget *parent = nullptr);
    ~myLineEdit();
    bool event(QEvent * event);
protected:
    void  keyPressEvent(QKeyEvent *event);
};


class Widget : public QWidget
{
    Q_OBJECT

protected:
    //鼠标按下事件
    void mousePressEvent(QMouseEvent *event);
    //鼠标双击
    void mouseDoubleClickEvent(QMouseEvent *event);
    //鼠标释放
    void mouseReleaseEvent(QMouseEvent *event);
    //鼠标移动事件
    void mouseMoveEvent(QMouseEvent *event);
    //键盘按下事件
    void keyPressEvent(QKeyEvent *event);
    //绘画事件
    void paintEvent(QPaintEvent *event);


public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    bool eventFilter(QObject* obj,QEvent* event);
    void timerUp();

private:
    Ui::Widget *ui;
    myLineEdit *Line;

    QPoint pos;
    QPoint posend;
    int angle;
    QLCDNumber *LCD_display;
};


#endif // WIDGET_H
