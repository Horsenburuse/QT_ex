#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QRadioButton>
#include <QGroupBox>
#include <QMdiArea>
#include <QTextEdit>

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

    void on_actionShow_Dock_D_triggered();

    void on_actionOpen_file_O_triggered();

private:
    Ui::MainWindow *ui;
    QMdiArea *Tarea;
    QTextEdit *edit;
    QTextEdit *Tshow;
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
