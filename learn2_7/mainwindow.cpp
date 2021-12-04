#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QString>
#include <QVBoxLayout>
#include <QToolButton>
#include <QSpinBox>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QLabel>
#include <QFrame>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //加入编辑菜单
    QMenu *editMenu = ui->menuBar->addMenu(tr("编辑(&E)"));
    QAction *action_Open = editMenu->addAction(QIcon(":/image/images/open.jpg"),tr("编辑文件(&O)"));
    action_Open->setShortcut(QKeySequence("Ctrl+O"));
    ui->mainToolBar->addAction(action_Open);
    connect(action_Open,&QAction::triggered,[&](){
         QFileDialog::getOpenFileName();
    });
    QActionGroup * group = new QActionGroup(this);
    QAction *action_L= group->addAction(tr("左对齐(&L)"));
    action_L->setCheckable(true);
    QAction *action_R= group->addAction(tr("右对齐(&R)"));
    action_R->setCheckable(true);
    QAction *action_C= group->addAction(tr("居中(&C)"));
    action_C->setCheckable(true);
    action_L->setChecked(true);
    editMenu ->addSeparator();
    editMenu ->addAction(action_L);
    editMenu ->addAction(action_R);
    editMenu ->addAction(action_C);

    //加入工具菜单
    QMenu *toolMenu = ui->menuBar->addMenu(tr("工具(&T)"));
    QAction *action_tool = toolMenu->addAction(QIcon(":/newimage/images/1.jpg"),tr("工具(&T)"));
    action_tool->setShortcut(QKeySequence("Ctrl+T"));
    ui->mainToolBar->addAction(action_tool);
    connect(action_tool, &QAction::triggered,[&](){
        Twidget * tw = new Twidget();
        tw->show();
    });

    //加入工具栏
    QToolButton *toolBth = new QToolButton();
    toolBth->setText(tr("颜色"));
    QMenu * colorMenu = new QMenu(this);
    colorMenu->addAction(tr("红色"));
    colorMenu->addAction(tr("绿色"));
    toolBth->setMenu(colorMenu);
    toolBth->setPopupMode(QToolButton::MenuButtonPopup);
    ui->mainToolBar->addWidget(toolBth);
    QSpinBox *spinbox = new QSpinBox(this);
    ui->mainToolBar->addWidget(spinbox);

    //加入中心部件
    this->Tarea = new QMdiArea(this);
    this->setCentralWidget(this->Tarea);

    //显示状态栏
    ui->statusBar->showMessage(tr("欢迎实用信号处理文件编辑器"),2000);
    QLabel *lb = new QLabel(this);
    lb->setFrameStyle(QFrame::Box | QFrame::Sunken);
    lb->setText("1.txt");
    ui->statusBar->addPermanentWidget(lb);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_New_triggered()
{
    edit = new QTextEdit(this);
    QMdiSubWindow *child = this->Tarea->addSubWindow(edit);
    child->setWindowTitle(tr("多文档编辑器子窗口"));
    child->setWindowIcon(QIcon(":/image/images/2.jpg"));
    child->show();
}

Twidget::Twidget(QWidget *parent):
    QWidget (parent)
{
    this->setFixedSize(120,460);

    QPushButton *b1 = new QPushButton("载波捕获");
    QPushButton *b2 = new QPushButton("获取带宽");
    QRadioButton *rb1 = new QRadioButton("调制跟踪");
    QVBoxLayout *Vbox1 = new QVBoxLayout();
    QGroupBox *gp1 = new QGroupBox("载波捕获");
    Vbox1->addWidget(b1);
    Vbox1->addWidget(b2);
    Vbox1->addWidget(rb1);
    gp1->setLayout(Vbox1);

    QPushButton *b3 = new QPushButton("保存设置");
    QPushButton *b4 = new QPushButton("保存文件");
    QVBoxLayout *Vbox2 = new QVBoxLayout();
    QGroupBox *gp2 = new QGroupBox("参数设置");
    Vbox2->addWidget(b3);
    Vbox2->addWidget(b4);
    gp2->setLayout(Vbox2);

    QVBoxLayout *Vbox3 = new QVBoxLayout();
    Vbox3->addWidget(gp1);
    Vbox3->addWidget(gp2);
    setLayout(Vbox3);
}

Twidget::~Twidget()
{

}

void MainWindow::on_actionShow_Dock_D_triggered()
{
    ui->dockWidget_2->show();
}

void MainWindow::on_actionOpen_file_O_triggered()
{
    Tshow = new QTextEdit(tr("文本内容"));
    QString filename = QFileDialog :: getOpenFileName();
    QFile f(filename);
    f.open(QIODevice::ReadWrite);
    QByteArray buf = f.readAll();
    f.close();
    Tshow->setText(buf);
    Tshow->show();
}
