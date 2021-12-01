#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMenu *editMenu = ui->menuBar->addMenu(tr("编辑(&E)"));
    QAction *action_Open = editMenu->addAction(
    QIcon(":/image/images/open.jpg"),tr("打开问及那(&O)"));
    action_Open->setShortcut(QKeySequence("Ctrl+O"));
    ui->mainToolBar->addAction(action_Open);
}

MainWindow::~MainWindow()
{
    delete ui;
}
