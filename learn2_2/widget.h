#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QComboBox>
#include <QFontComboBox>
#include <QTextEdit>
#include <QSpinBox>
#include <QLCDNumber>
#include <QDial>
#include <QScrollBar>
#include <QSlider>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    QCheckBox *bt_c;
    QLineEdit *le_t;
    QComboBox *cmb_t;
    QFontComboBox *fcb_t;
    QTextEdit *te_t;
    QSpinBox *sp_t;
    QLCDNumber *lcd_t;
    QDial *dl_t;
    QScrollBar *Ba_t;
    QSlider *Sd_t;
};

#endif // WIDGET_H
