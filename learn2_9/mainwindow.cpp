#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QFont>
#include <QToolButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lcdNumber->setMinimumHeight(50);
    ui->lcdNumber->display(ui->widgetGameArea->getscore());
    logdlg = new Dialog();
    exitdlg = new overdlg();
    logdlg->show();
    connect(logdlg,&Dialog::signalStart,[&](){
        logdlg->close();
        this->show();
        ui->widgetGameArea->NewGame();
    });
    connect(logdlg,&Dialog::signalExit,[&](){
        logdlg->close();
        this->close();
    });
    connect(ui->widgetGameArea,&Game_area::signalUpadteScore,[&](){
        this->ui->lcdNumber->display(QString::number(ui->widgetGameArea->getscore()));
    });

    connect(ui->widgetGameArea,&Game_area::signalUpadteNI,[&](){
        this->ui->widget1->setShowItem(ui->widgetGameArea->getNextItem());
    });

    connect(ui->widgetGameArea, &Game_area::siganlUpdateSP,[&](){
        QFont ft;
        ft.setPointSize(12);
        ft.setPointSize(20);
        this->ui->label_1->setFont(ft);
        this->ui->label_1->setText(QString::number(ui->widgetGameArea->getSL()));
        this->ui->label_2->setFont(ft);
        this->ui->label_3->setFont(ft);

    });
    connect(ui->widgetGameArea,&Game_area::signalGameover,[&](){
        exitdlg->show();
    });
    connect(exitdlg,&overdlg::signalRestart,[&](){
        exitdlg->close();
        ui->widgetGameArea->NewGame();
    });
    connect(exitdlg,&overdlg::signalExit,[&](){
        exitdlg->close();
        this->close();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    ui->widgetGameArea->KeyPressed(event->key());
    QMainWindow::keyPressEvent(event);
}
