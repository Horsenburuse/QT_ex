#include "widget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFileDialog>
#include <QColorDialog>
#include <QFontDialog>
#include <QInputDialog>
#include <QErrorMessage>
#include <QMessageBox>
#include <QProgressDialog>
#include <QWizard>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    bt_filename = new QPushButton("获取文件名");
    bt_getcolor = new QPushButton("获取颜色");
    bt_getfont  = new QPushButton("获取字体");
    bt_getinput = new QPushButton("获取输入");
    bt_error    = new QPushButton("错误弹窗");
    bt_message  = new QPushButton("消息弹窗");
    bt_progress = new QPushButton("进度条对话框");
    bt_wizard   = new QPushButton("向导框");

    te_test = new QTextEdit;

    QVBoxLayout *Vbox = new QVBoxLayout;
    Vbox ->addWidget(bt_filename);
    Vbox ->addWidget(bt_getcolor);
    Vbox ->addWidget(bt_getfont);
    Vbox ->addWidget(bt_getinput);
    Vbox ->addWidget(bt_error);
    Vbox ->addWidget(bt_message);
    Vbox ->addWidget(bt_progress);
    Vbox ->addWidget(bt_wizard);

    QHBoxLayout *Hbox = new QHBoxLayout;
    Hbox -> addWidget(te_test);
    Hbox -> addLayout(Vbox);
    setLayout(Hbox);

    //文件对话框示例
    connect(bt_filename, &QPushButton::clicked, [&](){
        //提取单个文件名的对话框
   //        QString filename =  QFileDialog::getOpenFileName();
   //        te_test->append(filename);
        //提取多个文件名的对话框
        QStringList filenames = QFileDialog::getOpenFileNames(this, "打开图片", ".", "Images (*.png *.xpm *.jpg)");
        for(int i=0; i<filenames.length(); i++)
            te_test->append(filenames[i]);
    });//接收对象是this直接省略，[&]()为lambda表达式

    connect(bt_getcolor,&QPushButton::clicked, [&](){
        QColor color = QColorDialog::getColor();
        te_test -> setTextColor(color);
    });

    connect(bt_getfont,&QPushButton::clicked, [&](){
        bool ok;
        QFont font = QFontDialog::getFont(&ok);
        if(ok)
            te_test ->setCurrentFont(font);
    });
    connect(bt_getinput,&QPushButton::clicked,[&](){
        QString str = QInputDialog::getText(this, "欢迎光临","登录密码");
        te_test ->setText(str);
    });
    connect(bt_error, &QPushButton::clicked,[&](){
        QErrorMessage x;
        x.showMessage("发现错误");
        x.exec();
    });
    connect(bt_progress, &QPushButton::clicked, [&](){
        QProgressDialog x;
        x.setValue(66);
        x.exec();
    });
    connect(bt_message,&QPushButton::clicked,[&](){
        QMessageBox::warning(this,"错误","运行报错",QMessageBox::Open,QMessageBox::Apply);
    });
    connect(bt_wizard,&QPushButton::clicked,[&](){
        QWizard wizard(this);
        wizard.setWindowTitle(tr("向导对话框"));
        wizard.addPage(createpage1());
        wizard.addPage(createpage2());
        wizard.exec();
    });

}
inline
QWizardPage* Widget::createpage1()
{
    QWizardPage *Page = new QWizardPage;
    Page->setTitle(tr("介绍"));
    return  Page;
}
QWizardPage* Widget::createpage2()
{
    QWizardPage *Page = new QWizardPage;
    Page->setTitle(tr("下一个"));
    return  Page;
}


Widget::~Widget()
{

}
