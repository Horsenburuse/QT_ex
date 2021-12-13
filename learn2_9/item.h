#ifndef item_H
#define item_H

#include <QPoint>
#include <QPainter>
#include "qmap.h"


enum item_TYPE{
    item_1 = 0,    //长条
    item_2,        //山字
    item_3,        //L型1
    item_4,        //L型1
    item_5,        //田字形
    item_6,        //z字形
    item_MAX
};

class item
{
public:
    item(){}
    item(item_TYPE t,int nshape = 0);
    ~item(void);

    void InitNew(unsigned int nSeed = 0);
    void Inititem(item_TYPE t,int nShape);
    void Draw(QPainter & painter,int nStarX, int nStarY, int nW, int nY);
    void AddPoints(QVector<QPoint>& points);
    void Move(int x, int y);
    void Moveto(int x, int y);
    void DeletRow(int y);
    void MoveDown(int Row ,int y);
    void ChangeShape(int nAdd = 1);
    int  getxMax();

    QVector<QPoint>& GetPoints(){
        return  this->mPoints;
    };
    QPoint& GetmPos(){
        return  this->mPos;
    };
    item_TYPE& GetType()
    {
        return this->mType;
    }

private:
    QVector<QPoint> mPoints;
    QPoint mPos;
    item_TYPE mType;
    int mShape;
};

#endif // item_H
