#include "gamemap.h"
#include<QDebug>
#include<iostream>
#include<ctime>
#define BLANK 0


Gamemap::Gamemap()
{
    this->width=0;
    this->height=0;
    this->currentCount=this->width*this->height;
}

Gamemap::Gamemap(int level)
{
    if(level==0)
    {
        this->width=12;
        this->height=8;
    }
    else
    {
        this->width=2+level*2;
        this->height=4+level*2;
    }
    this->currentCount=this->width*this->height;
    Initgamemap();
}

Gamemap::Gamemap(QVector<QVector<int>> target)
{
    this->height = target.length();
    this->width = target.at(0).length();
    this->cellMap = target;
    this->currentCount=this->width*this->height;
}

void Gamemap::setLevel(int lv)
{
    this->level=lv;
    if(level==0)
    {
        this->width=6;
        this->height=8;
    }
    else
    {
        this->width=2+level*2;
        this->height=4+level*2;
    }
    this->currentCount=this->width*this->height;
    Initgamemap();
}

void Gamemap::Initcellmap()
{

    int npn=this->nPicNum;//4种花色
    //int nRepeatNum=width*height/npn;//获得重复数
    int nCount=1;//记录当前是第几个元素
    for(int i=0;i<this->height+2;i++)
    {
        QVector<int> temp;
        for(int j=0;j<this->width+2;j++)
        {
            if (i==0||j==0||i==this->height+1||j==this->width+1)
            {
                temp.push_back(0);
            }
            else
            {
                temp.push_back(nCount%(npn+1));
                nCount++;
                if(nCount==npn+1)
                {
                    nCount=1;
                }
            }
        }
        cellMap.push_back(temp);
    }
    //qDebug()<<cellMap;
//    printmap();
}

void Gamemap::printmap()
{
    qDebug()<<"cellMap.length():"<<cellMap.length()<<endl;
    for(int i=0;i<cellMap.length();i++)
    {
        for(int j=0;j<cellMap[0].length();j++)
        {
            qDebug()<<cellMap[i][j];
        }
        qDebug()<<endl;
    }

}

// 打乱
int change(int a,int b)
{
//    srand(time(0));
    return a + rand() % (b - a);
}

void Gamemap::Resetmap()
{

    int h = this->height+2;
    int w = this->width+2;
    // 进行随机对换：
     for(int i = 0;i < h*w/2; i++){
         int x1 = change(1,h-1);
         int y1 = change(1,w-1);
         int x2 = change(1,h-1);
         int y2 = change(1,w-1);
//         swap(this->cellMap[x1][y1],cellMap[x2][y2]);
//         qDebug()<<x1<<y1<<x2<<y2;
//         qDebug()<<this->cellMap[x1][y1];
//         qDebug()<<this->cellMap[x2][y2];
         int temp = this->cellMap[x1][y1];
         this->cellMap[x1][y1] = this->cellMap[x2][y2];
         this->cellMap[x2][y2] = temp;
//         qDebug()<<this->cellMap[x1][y1];
//         qDebug()<<this->cellMap[x2][y2];
     }
}

QVector<QVector<int>> Gamemap::Getmap()
{
    return this->cellMap;
}

void Gamemap::Initgamemap()
{
    srand(time(0));
    Initcellmap();
    Resetmap();
    qDebug()<<this->cellMap;
}

bool Gamemap:: isSametype(int x1,int y1,int x2,int y2)
{
    return cellMap[x1][y1]==cellMap[x2][y2];
}



bool Gamemap:: oneLine(int x1,int y1,int x2,int y2)
{
    if(x1==x2&&y1==y2)
        return false;
    if (x1==x2)
    {
        int min=(y1<y2)?y1:y2;
        int max=(y1>y2)?y1:y2;
//        qDebug()<<"min"<<min<<"max"<<max;
        for(int i=min+1;i<max;i++)
        {
//            qDebug()<<323;
//            qDebug()<<cellMap[x1][i];
            if(cellMap[x1][i]!=BLANK)
            {
                return false;
            }
        }
        return true;
    }
    else if(y1==y2)
    {

        int min=(x1<x2)?x1:x2;
        int max=(x1>x2)?x1:x2;
//        qDebug()<<"min"<<min<<"max"<<max;
        for(int i=min+1;i<max;i++)
        {
//             qDebug()<<555;
            if(cellMap[i][y1]!=BLANK)
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool Gamemap:: twoLine(int x1,int y1,int x2,int y2)
{
//    1：判断相交的顶点是否为空
        if (this->cellMap[x1][y2] == BLANK)
        {
//            qDebug()<<"s";
        //            2：判断两个同行的顶点是否一条直线连通
        //            3：判断两个同列的顶点是否一条直线连通
            if (oneLine(x1,y2,x2,y2)&& oneLine(x1,y1,x1,y2))
                return true;
        }
        if(this->cellMap[x2][y1] == BLANK)
        {
//            qDebug()<<"m";
            if(oneLine(x2,y1,x2,y2)&& oneLine(x2,y1,x1,y1))
                return true;
        }
        return false;
}

bool Gamemap:: threeLine(int x1,int y1,int x2,int y2)
{
    for(int i=0;i<cellMap.length();i++)
    {
        int v1=cellMap[i][y1];
        int v2=cellMap[i][y2];
        if(v1==BLANK&&v2==BLANK)
        {
            if(oneLine(x1,y1,i,y1)&&oneLine(i,y1,i,y2)&&oneLine(x2,y2,i,y2))
                return true;
        }
    }

    for(int j=0;j<cellMap[0].length();j++)
    {
        int v1=cellMap[x1][j];
        int v2=cellMap[x2][j];
        if(v1==BLANK&&v2==BLANK)
        {
            if(oneLine(x1,j,x1,y1)&&oneLine(x1,j,x2,j)&&oneLine(x2,j,x2,y2))
                return true;
        }
    }
    return false;
}

void Gamemap::setCell(int x,int y,int status)
{
    if(status==0&&currentCount>0)
        currentCount--;
    cellMap[x][y]=status;
}
