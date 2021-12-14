#ifndef GAME_AREA_H
#define GAME_AREA_H

#include <QWidget>
#include <QLineF>
#include <QPainter>
#include <QHBoxLayout>
#include <QKeyEvent>
#include "item.h"

//设置方块大小
#define RECT_W  40
#define RECT_H  40
//
#define C_NUM   20 //列数
#define R_NUM   20 //行数
#define AREA_COLUMES R_NUM*RECT_H
#define AREA_ROWS    (C_NUM+3)*RECT_W

//item出现的初始位置
#define DEFAULT_BORNP_POS_X  (qrand()%(C_NUM-3))


class Game_area : public QWidget
{
    Q_OBJECT
public:
    explicit Game_area(QWidget *parent = nullptr);

    void NewGame();
    void DrawBKRects();
    void DrawCurItem();
    void DrawFixItem();

    bool HitBottom();
    bool HitTop();
    bool HitSide();
//    bool CheckBoudary();

    void KeyPressed(int key);
    void addFixItem();
    int  deletAllRow();
    int  getspeed();
    void changspeed();

    int getscore()
    {
        return  this->score;
    }

protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
signals:
    void  signalUpadteScore(int score);
public slots:

private:
    item mCurItem;
    item mNextItem;
    item mFixItem;

    int TimeID;
    int score = 0;
    int speed_level = 1;
};

#endif // GAME_AREA_H
