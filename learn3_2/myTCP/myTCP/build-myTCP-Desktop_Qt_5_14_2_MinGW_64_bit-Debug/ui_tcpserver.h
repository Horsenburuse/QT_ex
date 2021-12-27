/********************************************************************************
** Form generated from reading UI file 'tcpserver.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPSERVER_H
#define UI_TCPSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_tcpserver
{
public:
    QLabel *label;
    QTextBrowser *textBrowser;
    QPushButton *pushButton;

    void setupUi(QDialog *tcpserver)
    {
        if (tcpserver->objectName().isEmpty())
            tcpserver->setObjectName(QString::fromUtf8("tcpserver"));
        tcpserver->resize(372, 300);
        label = new QLabel(tcpserver);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 12, 91, 20));
        textBrowser = new QTextBrowser(tcpserver);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 40, 341, 241));
        pushButton = new QPushButton(tcpserver);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(280, 10, 75, 23));

        retranslateUi(tcpserver);

        QMetaObject::connectSlotsByName(tcpserver);
    } // setupUi

    void retranslateUi(QDialog *tcpserver)
    {
        tcpserver->setWindowTitle(QCoreApplication::translate("tcpserver", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("tcpserver", "\347\255\211\345\276\205\350\277\236\346\216\245", nullptr));
        pushButton->setText(QCoreApplication::translate("tcpserver", "\346\230\276\347\244\272\346\216\245\346\224\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tcpserver: public Ui_tcpserver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPSERVER_H
