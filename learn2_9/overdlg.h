#ifndef OVERDLG_H
#define OVERDLG_H
#include <QPushButton>

#include <QWidget>

class overdlg : public QWidget
{
    Q_OBJECT
public:
    explicit overdlg(QWidget *parent = nullptr);

signals:
    void signalRestart();
    void signalExit();

public slots:
private:
    QPushButton *button_restart;
    QPushButton *button_exit;
};

#endif // OVERDLG_H
