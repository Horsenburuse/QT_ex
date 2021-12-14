#ifndef NEXTAREA_H
#define NEXTAREA_H

#include <QWidget>
#include "item.h"

class NextArea : public QWidget
{
    Q_OBJECT
public:
    explicit NextArea(QWidget *parent = nullptr);

signals:

public slots:

private:
    item ShowItem;
};

#endif // NEXTAREA_H
