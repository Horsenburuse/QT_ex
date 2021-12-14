#include "nextarea.h"
#include <QPainter>

NextArea::NextArea(QWidget *parent) : QWidget(parent)
{
     setMinimumSize(NA_ROWS,NA_COLUMES);
     ShowItem = item();
}

void NextArea::paintEvent(QPaintEvent *event){
    DrawBkRects();
    DrawShowItem();
    update();
}

void NextArea::DrawBkRects(){
    QPainter painter(this);
    painter.setBrush(QColor("#ffffdd"));
    painter.setPen(Qt::NoPen);
    for (int i = 0; i < NAR_NUM; ++i) {
        for (int j = 0; j < NAR_NUM; ++j) {
            painter.drawRect(i*RECT_W,j*RECT_H,RECT_W,RECT_H);
        }
    }
}

void NextArea::DrawShowItem(){
    QPainter painter(this);
    painter.setBrush(QColor("#FFDEAD"));
    painter.setPen(QPen(QColor(Qt::red),1));
    ShowItem.Draw(painter,40,40,RECT_W,RECT_H);
}

void NextArea::setShowItem(item& NewItem ){

    ShowItem.CopyPoints(NewItem.GetPoints());
}
