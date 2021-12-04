#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QRadioButton>
#include <QGroupBox>

namespace Ui {
class MainWindow;
class Twidget;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_New_triggered();

private:
    Ui::MainWindow *ui;
};

//工具栏弹出框1
class Twidget : public QWidget
{
    Q_OBJECT
public:
    explicit Twidget(QWidget *parent = nullptr);
    ~Twidget();

private:
    QGroupBox *gp;
};

#endif // MAINWINDOW_H
