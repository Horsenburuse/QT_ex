/********************************************************************************
** Form generated from reading UI file 'tcpcilent.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPCILENT_H
#define UI_TCPCILENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_tcpcilent
{
public:
    QSplitter *splitter_1;
    QSplitter *splitter2;
    QLabel *label;
    QLineEdit *lineEdit;
    QSplitter *splitter_4;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QSplitter *splitter_3;
    QLabel *label_3;
    QTextBrowser *textBrowser;
    QSplitter *splitter;
    QLabel *label_4;
    QPushButton *pushButton;
    QSplitter *splitter_2;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_3;

    void setupUi(QDialog *tcpcilent)
    {
        if (tcpcilent->objectName().isEmpty())
            tcpcilent->setObjectName(QString::fromUtf8("tcpcilent"));
        tcpcilent->resize(572, 379);
        splitter_1 = new QSplitter(tcpcilent);
        splitter_1->setObjectName(QString::fromUtf8("splitter_1"));
        splitter_1->setGeometry(QRect(30, 70, 500, 244));
        splitter_1->setOrientation(Qt::Vertical);
        splitter2 = new QSplitter(splitter_1);
        splitter2->setObjectName(QString::fromUtf8("splitter2"));
        splitter2->setOrientation(Qt::Horizontal);
        label = new QLabel(splitter2);
        label->setObjectName(QString::fromUtf8("label"));
        splitter2->addWidget(label);
        lineEdit = new QLineEdit(splitter2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        splitter2->addWidget(lineEdit);
        splitter_1->addWidget(splitter2);
        splitter_4 = new QSplitter(splitter_1);
        splitter_4->setObjectName(QString::fromUtf8("splitter_4"));
        splitter_4->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(splitter_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        splitter_4->addWidget(label_2);
        lineEdit_2 = new QLineEdit(splitter_4);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        splitter_4->addWidget(lineEdit_2);
        splitter_1->addWidget(splitter_4);
        splitter_3 = new QSplitter(splitter_1);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setOrientation(Qt::Vertical);
        label_3 = new QLabel(splitter_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        splitter_3->addWidget(label_3);
        textBrowser = new QTextBrowser(splitter_3);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        splitter_3->addWidget(textBrowser);
        splitter_1->addWidget(splitter_3);
        splitter = new QSplitter(tcpcilent);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(30, 30, 129, 23));
        splitter->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(splitter);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        splitter->addWidget(label_4);
        pushButton = new QPushButton(splitter);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        splitter->addWidget(pushButton);
        splitter_2 = new QSplitter(tcpcilent);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setGeometry(QRect(30, 330, 501, 23));
        splitter_2->setOrientation(Qt::Horizontal);
        pushButton_2 = new QPushButton(splitter_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        splitter_2->addWidget(pushButton_2);
        lineEdit_3 = new QLineEdit(splitter_2);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        splitter_2->addWidget(lineEdit_3);

        retranslateUi(tcpcilent);

        QMetaObject::connectSlotsByName(tcpcilent);
    } // setupUi

    void retranslateUi(QDialog *tcpcilent)
    {
        tcpcilent->setWindowTitle(QCoreApplication::translate("tcpcilent", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("tcpcilent", "\344\270\273\346\234\272", nullptr));
        label_2->setText(QCoreApplication::translate("tcpcilent", "\347\253\257\345\217\243", nullptr));
        label_3->setText(QCoreApplication::translate("tcpcilent", "\346\216\245\346\224\266\345\206\205\345\256\271", nullptr));
        label_4->setText(QCoreApplication::translate("tcpcilent", "TCP\345\256\242\346\210\267\347\253\257", nullptr));
        pushButton->setText(QCoreApplication::translate("tcpcilent", "\350\277\236\346\216\245", nullptr));
        pushButton_2->setText(QCoreApplication::translate("tcpcilent", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tcpcilent: public Ui_tcpcilent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPCILENT_H
