#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

signals:
    void signalStart();
    void signalExit();
private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
