#include "game_area.h"
#include <QTimerEvent>
#include <QVector>
#include <QMessageBox>
#include <QKeyEvent>
#include <QTime>
#include <QTimer>
#include <QDebug>

Game_area::Game_area(QWidget *parent) : QWidget(parent)
{
    setMinimumSize(AREA_ROWS,AREA_COLUMES);
//    NewGame();
}

//创建新的游戏的方块
void Game_area:: NewGame(){
    QVector<QPoint> init_points;
    init_points.clear();
    TimeID = startTimer(1000);
    CItem_color.setRgb(qrand()%256,qrand()%256,qrand()%256);
    mFixItem.CopyPoints(init_points);//清空上一局的
    mCurItem.InitNew(static_cast<unsigned int>(QTime::currentTime().second()));
    mCurItem.Moveto(DEFAULT_BORNP_POS_X,0);
    mNextItem.InitNew(static_cast<unsigned int>(QTime::currentTime().msec()));
    NItem_color.setRgb(qrand()%256,qrand()%256,qrand()%256);
    qDebug() << tr("创建");
};

void Game_area :: DrawBKRects()//绘制方块操作背景
{
    QPainter painter(this);
//    painter.setBrush(QColor("#008789"));
    painter.setBrush(QBrush(QPixmap(":/image/images/new.jpg")));
    painter.setPen(Qt::NoPen);
    for (int i = 0; i <= (C_NUM-1); ++i) {
        for (int j = 0; j < (R_NUM); ++j) {
                painter.drawRect(i*RECT_W,j*RECT_H,RECT_W,RECT_H);
            }
        }
    }

void Game_area :: DrawCurItem()//绘制移动方块
{
    QPainter painter(this);
//    painter.setBrush(QColor("#FFDEAD"));
//    painter.setBrush(QBrush(QPixmap(":/image/images/2.jpg")));
    painter.setBrush(CItem_color);
    painter.setPen(QPen(QColor(Qt::black),1));
    mCurItem.Draw(painter,0,0,RECT_W,RECT_H);
}

void Game_area ::DrawFixItem(){
    QPainter painter(this);
    painter.setBrush(QBrush(QPixmap(":/image/images/2.jpg")));
    painter.setPen(Qt::NoPen);
    mFixItem.Draw(painter,0,0,RECT_W,RECT_H);
}

//方块触底
bool Game_area::HitBottom(){
    for (int i = 0; i < mCurItem.GetPoints().size(); ++i) {
        QPoint pt = mCurItem.GetPoints()[i];
        if(pt.y() >=  R_NUM){
            qDebug()<<tr("触底") << speed_level << getspeed() ;
            return true;
        }
        if(mFixItem.GetPoints().contains(pt)){
            qDebug()<< "xxxxxxxxxxxxxx";
            return  true;
        }
    }
    return  false;
}
//方块到顶
bool Game_area::HitTop(){
    for (int i = 0; i < mFixItem.GetPoints().size(); ++i) {
        if(mFixItem.GetPoints()[i].y() <= 1)
            return true;
    }
    return  false;
}
//方块碰触边界
bool Game_area::HitSide(){
    for (int i = 0; i < mCurItem.GetPoints().size(); ++i) {
        QPoint pt = mCurItem.GetPoints()[i];
        if(pt.x() < 0 || pt.x() >= C_NUM){
            qDebug()<<"碰壁" << pt.x() << -0;
            return true;
        }
    }
    return  false;
}

void Game_area::paintEvent(QPaintEvent *event)
{
    DrawBKRects();
    DrawCurItem();
    DrawFixItem();
    changspeed();
    update();
}


void Game_area::KeyPressed(int key){
    int x = 0;
    int y = 0;
    switch(key)
    {
    case Qt::Key_Left:
    {
        x = -1;
        break;
    }
    case Qt::Key_Up:
    {
        if(HitSide() || HitBottom())
        {
            return;
        }
        else {
            mCurItem.ChangeShape(1);
        }
        break;
    }
    case Qt::Key_Right:
    {
        x = 1;
        break;
    }
    case Qt::Key_Down:
    {
        y = 1;
        break;
    }
    case Qt::Key_Space:
    {
        //空格键直接移到底部
        while(1)
        {
            mCurItem.Move(0,1);
            if(HitSide() || HitBottom())
            {
                mCurItem.Move(0,-1);
                break;
            }
        }
        return;
    }
    }
    mCurItem.Move(x,y);
    while (mCurItem.getxMax() >= C_NUM) {
        qDebug()<<tr("超出背景");
        mCurItem.Move(-1,0);
    }

    if (HitSide() || HitBottom())
    {
        mCurItem.Move(-x,-y);
    }
    return;
}

void Game_area::timerEvent(QTimerEvent *event)
{
    int DR_num = 0;
    if(event->timerId() == TimeID)
    {
        mCurItem.Move(0,1);
        if(HitBottom())
        {
            qDebug()<<tr("判断触底") << speed_level << getspeed() << mCurItem.GetPoints()[1].x();
            mCurItem.Move(0,-1);
            addFixItem();
            DR_num = deletAllRow();
            mCurItem =  mNextItem;
            CItem_color = NItem_color;
            mCurItem.Moveto(DEFAULT_BORNP_POS_X,0);
            mNextItem.InitNew(static_cast<unsigned int>(QTime::currentTime().msec()));
            NItem_color.setRgb(qrand()%256,qrand()%256,qrand()%256);
        }
        if (HitTop())
        {
            killTimer(TimeID);
//            QMessageBox::information(NULL, "GAME OVER", "GAME OVER", QMessageBox::Yes , QMessageBox::Yes);
//            NewGame();
            emit signalGameover();
            return;
        }
        if(DR_num)
            score += (DR_num*100 + (DR_num-1)*100);
            qDebug()<<score;
            emit signalUpadteScore(score);
    }
    emit signalUpadteNI(mNextItem);
    emit siganlUpdateSP(speed_level);
}

void Game_area::addFixItem()
{
    mFixItem.AddPoints(mCurItem.GetPoints());
}

int Game_area::deletAllRow(){
    int FILL_num = 0;
    int DR_num = 0;
    for (int i = 0; i < R_NUM; ++i) {
        FILL_num = 0;
        for (int j = 0; j < C_NUM; ++j) {
            if(mFixItem.GetPoints().contains(QPoint(j,i)))
            FILL_num++;
        }
        if(FILL_num >= C_NUM){
            mFixItem.DeletRow(i);
            mFixItem.MoveDown(i,1);
            DR_num++;
        }
    }
    return DR_num;
}

int Game_area::getspeed()
{
    if(speed_level > 9)
    {
        return 200;
    }
    else {
        return  ((11-speed_level)*100);
    }
}

void Game_area::changspeed()
{
    if(score >= speed_level*100)
    {
        speed_level++;
        killTimer(TimeID);
        TimeID = startTimer(getspeed());
        qDebug()<<speed_level<<getspeed();
    }
}







