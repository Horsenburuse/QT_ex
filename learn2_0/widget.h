#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QErrorMessage>
#include <QWizard>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    QPushButton *bt_filename;
    QPushButton *bt_getcolor;
    QPushButton *bt_getfont;
    QPushButton *bt_getinput;
    QPushButton *bt_message;
    QPushButton *bt_error;
    QPushButton *bt_progress;
    QPushButton *bt_wizard;

    QTextEdit *te_test;
private:
    QWizardPage *createpage1();
    QWizardPage *createpage2();
};

#endif // WIDGET_H
