#include "item.h"

#include <QTime>
#include <QDebug>

inline item::item(item_TYPE t,int nShape)
{
    mPos = QPoint(0,0);
    Inititem(t,nShape);
};


item::~item()
{};

void item::InitNew(unsigned int nSeed)
{
    if(nSeed == 0)
    {
        qsrand(static_cast<unsigned int>(QTime::currentTime().msec()));
    }
    else
    {
        qsrand(nSeed);
    }
    item_TYPE t = static_cast<item_TYPE>(qrand()%item_MAX);
    int s = qrand()%4;
    Inititem(t,s);
};

void item::Inititem(item_TYPE t,int nShape)
{
    mPoints.clear();
    mType = t;
    mShape = nShape;
    switch (t) {
    case item_1:
        {
            if(nShape%2 == 0)
            {
                    for (int i = 0; i < 4; ++i) {
                        mPoints.append(mPos + QPoint(i,1));
                    }
            }
            else if (nShape%2 == 1) {
                for (int i = 0; i < 4; ++i) {
                    mPoints.append(mPos + QPoint(1,i));
                }
           }
           break;
        }
    case item_2:
        {
            if(nShape == 0)
            {
                  mPoints.append(mPos + QPoint(1,0));
                  mPoints.append(mPos + QPoint(0,1));
                  mPoints.append(mPos + QPoint(1,1));
                  mPoints.append(mPos + QPoint(2,1));
            }
            else if (nShape == 1) {
                  mPoints.append(mPos + QPoint(0,0));
                  mPoints.append(mPos + QPoint(1,0));
                  mPoints.append(mPos + QPoint(2,0));
                  mPoints.append(mPos + QPoint(1,1));
           }
            else if (nShape == 2) {
                  mPoints.append(mPos + QPoint(0,0));
                  mPoints.append(mPos + QPoint(0,1));
                  mPoints.append(mPos + QPoint(0,2));
                  mPoints.append(mPos + QPoint(1,1));
            }
            else if (nShape == 3) {
                  mPoints.append(mPos + QPoint(0,1));
                  mPoints.append(mPos + QPoint(1,1));
                  mPoints.append(mPos + QPoint(1,2));
                  mPoints.append(mPos + QPoint(1,0));
            }
           break;
        }
    case item_3:
        {
            if(nShape == 0)
            {
                  mPoints.append(mPos + QPoint(1,0));
                  mPoints.append(mPos + QPoint(1,1));
                  mPoints.append(mPos + QPoint(2,1));
                  mPoints.append(mPos + QPoint(3,1));
            }
            else if (nShape == 1) {
                  mPoints.append(mPos + QPoint(1,0));
                  mPoints.append(mPos + QPoint(2,0));
                  mPoints.append(mPos + QPoint(1,1));
                  mPoints.append(mPos + QPoint(1,2));
           }
            else if (nShape == 2) {
                  mPoints.append(mPos + QPoint(1,0));
                  mPoints.append(mPos + QPoint(2,0));
                  mPoints.append(mPos + QPoint(3,0));
                  mPoints.append(mPos + QPoint(3,1));
            }
            else if (nShape == 3) {
                  mPoints.append(mPos + QPoint(2,0));
                  mPoints.append(mPos + QPoint(2,1));
                  mPoints.append(mPos + QPoint(2,2));
                  mPoints.append(mPos + QPoint(1,2));
            }
           break;
        }
    case item_4:
        {
            if(nShape == 0)
            {
              mPoints.append(mPos + QPoint(1,1));
              mPoints.append(mPos + QPoint(2,1));
              mPoints.append(mPos + QPoint(3,1));
              mPoints.append(mPos + QPoint(3,0));
            }
            else if (nShape == 1) {
              mPoints.append(mPos + QPoint(1,0));
              mPoints.append(mPos + QPoint(1,1));
              mPoints.append(mPos + QPoint(1,2));
              mPoints.append(mPos + QPoint(2,2));
           }
            else if (nShape == 2) {
              mPoints.append(mPos + QPoint(1,0));
              mPoints.append(mPos + QPoint(1,1));
              mPoints.append(mPos + QPoint(2,0));
              mPoints.append(mPos + QPoint(3,0));
            }
            else if (nShape == 3) {
              mPoints.append(mPos + QPoint(1,0));
              mPoints.append(mPos + QPoint(2,0));
              mPoints.append(mPos + QPoint(2,1));
              mPoints.append(mPos + QPoint(2,2));
            }
           break;
        }
    case item_5:
        {
             mPoints.append(mPos + QPoint(0,0));
             mPoints.append(mPos + QPoint(0,1));
             mPoints.append(mPos + QPoint(1,0));
             mPoints.append(mPos + QPoint(1,1));

           break;
        }
    case item_6:
        {
            if(nShape == 0)
            {
              mPoints.append(mPos + QPoint(0,0));
              mPoints.append(mPos + QPoint(1,0));
              mPoints.append(mPos + QPoint(1,1));
              mPoints.append(mPos + QPoint(2,1));
            }
            else if (nShape == 1) {
              mPoints.append(mPos + QPoint(1,0));
              mPoints.append(mPos + QPoint(0,1));
              mPoints.append(mPos + QPoint(1,1));
              mPoints.append(mPos + QPoint(2,0));
            }
            else if (nShape == 2) {
              mPoints.append(mPos + QPoint(0,0));
              mPoints.append(mPos + QPoint(0,1));
              mPoints.append(mPos + QPoint(1,1));
              mPoints.append(mPos + QPoint(1,2));
            }
            else if (nShape == 3) {
              mPoints.append(mPos + QPoint(1,0));
              mPoints.append(mPos + QPoint(1,1));
              mPoints.append(mPos + QPoint(0,1));
              mPoints.append(mPos + QPoint(0,2));
            }

           break;
        }
    default:
        break;
    }
}

void item::ChangeShape(int nAdd){
    mShape = (mShape+nAdd)%4;
    Inititem(mType,mShape);
}


void item::Draw(QPainter &painter, int nStarX, int nStarY, int nW, int nH)
{
    for (int i = 0; i < mPoints.size(); i++) {
        QPoint pt = mPoints[i];
        painter.drawRect(QRect(nStarX + pt.x()*nW,nStarY + pt.y()*nH,nW,nH));
    }
}

void item::AddPoints(QVector<QPoint>& points){
    for (int i = 0;i<points.size();i++) {
        if(!mPoints.contains(points[i]))
        {
            mPoints.append(points[i]);
        }
    }
}

void item::Move(int x,int y){
    for (int i = 0; i < mPoints.size(); i++) {
        int x1 = mPoints[i].x() + x;
        int y1 = mPoints[i].y() + y;
        mPoints[i].setX(x1);
        mPoints[i].setY(y1);
    }
    mPos += QPoint(x,y);
    qDebug()<< mPos.x() << mPos.y();
}

void item::Moveto(int x, int y){
    for (int i = 0; i<mPoints.size(); i++)
    {
        int x1 = mPoints[i].x() - mPos.x() + x;
        int y1 = mPoints[i].y() - mPos.y() + y;
        mPoints[i].setX(x1);
        mPoints[i].setY(y1);
    }
    mPos = QPoint(x,y);
}

void item::DeletRow(int y)
{
    QVector<QPoint> newPoints;
    for (int i = 0; i < mPoints.size(); ++i) {
        if(mPoints[i].y() != y)
        {
            newPoints.append(mPoints[i]);
        }
    }
    mPoints = newPoints;
}

void item::MoveDown(int Row ,int y)
{
    for (int i = 0; i < mPoints.size(); ++i) {
        if(mPoints[i].y() < Row){
            mPoints[i].setY(mPoints[i].y()+y);
        }
    }
}

int item::getxMax()
{
    int x_value = 0;
    for (int i = 0; i < mPoints.size()-1; ++i) {
        if(mPoints[i+1].x() > mPoints[i].x())
            x_value = mPoints[i+1].x();
        else {
            x_value = mPoints[i].x();
        }
    }
    return  x_value;
};

void item::CopyPoints(QVector<QPoint> nPoints){
    this->mPoints = nPoints;
}




