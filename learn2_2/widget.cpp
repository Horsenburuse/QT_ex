#include "widget.h"
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    bt_c = new QCheckBox("显示登陆密码");
    cmb_t = new QComboBox;
    cmb_t ->addItem("com1");
    cmb_t ->addItem("com2");
    cmb_t ->addItem("com3");
    le_t = new QLineEdit;
    le_t->setEchoMode(QLineEdit::Password);
    fcb_t = new QFontComboBox;
    te_t = new QTextEdit;
    sp_t = new QSpinBox;
    lcd_t = new QLCDNumber;
    lcd_t->setMinimumHeight(50);
    dl_t = new QDial;
    Ba_t = new QScrollBar;
    Ba_t->setOrientation(Qt::Horizontal);
    Sd_t = new QSlider;
    Sd_t->setOrientation(Qt::Horizontal);

    connect(fcb_t,&QFontComboBox::currentFontChanged,[&](QFont x){
        le_t->setFont(x);
        te_t->setCurrentFont(x);
    });
    connect(bt_c,&QCheckBox::clicked,[&](bool x){
        le_t->setEchoMode(x?QLineEdit::Normal:QLineEdit::Password);
    });
    connect(sp_t,static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),[&](int x){
        lcd_t->display(x);
    });//有重载信号无法获取函数指针，需要进行显示转换为void(typename *)(param)类型函数指针
    connect(dl_t,static_cast<void(QDial::*)(int)>(&QDial::valueChanged),[&](int x){
        lcd_t->display(x);});
    connect(Ba_t,static_cast<void(QScrollBar::*)(int)>(&QScrollBar::valueChanged),[&](int x){
        lcd_t->display(x);});
    connect(Sd_t,static_cast<void(QSlider::*)(int)>(&QSlider::valueChanged),[&](int x){
        lcd_t->display(x);});

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(le_t);
    vbox->addWidget(bt_c);
    vbox->addWidget(cmb_t);
    vbox->addWidget(fcb_t);
    vbox->addWidget(te_t);
    vbox->addWidget(sp_t);
    vbox->addWidget(dl_t);
    vbox->addWidget(Ba_t);
    vbox->addWidget(Sd_t);
    vbox->addWidget(lcd_t);

    setLayout(vbox);
}

Widget::~Widget()
{

}
