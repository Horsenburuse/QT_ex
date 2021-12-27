#include "tcpserver.h"
#include "tcpcilent.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    tcpcilent w;
    tcpserver s;
    w.show();
    s.show();
    return a.exec();
}
