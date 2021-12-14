#ifndef NEXTAREA_H
#define NEXTAREA_H

#include <QWidget>
#include <QVector>
#include "item.h"

#define RECT_W  40
#define RECT_H  40
#define NAC_NUM 5//列数
#define NAR_NUM 5//行数

#define NA_COLUMES  NAR_NUM*RECT_H
#define NA_ROWS  NAC_NUM*RECT_W

class NextArea : public QWidget
{
    Q_OBJECT
public:
    explicit NextArea(QWidget *parent = nullptr);
    void DrawBkRects();
    void DrawShowItem();
    void setShowItem(item& NewItem);
signals:

public slots:

protected:
    void paintEvent(QPaintEvent *event);

private:
    item ShowItem;
};

#endif // NEXTAREA_H
