/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *Cilent_button;
    QPushButton *Server_button;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 424);
        Cilent_button = new QPushButton(Widget);
        Cilent_button->setObjectName(QString::fromUtf8("Cilent_button"));
        Cilent_button->setGeometry(QRect(120, 170, 111, 51));
        Server_button = new QPushButton(Widget);
        Server_button->setObjectName(QString::fromUtf8("Server_button"));
        Server_button->setGeometry(QRect(520, 170, 111, 51));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        Cilent_button->setText(QCoreApplication::translate("Widget", "TCP_client open", nullptr));
        Server_button->setText(QCoreApplication::translate("Widget", "TCP_server open", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
