#ifndef GAMEMAP_H
#define GAMEMAP_H
#include<QVector>
#include<QString>
#include"cellbtn.h"
class Gamemap
{
private:
    int width;
    int height;
    int level;
    int currentCount;//当前还剩多少个棋子
    int nPicNum=4;//花色数
    QVector<QVector<int>> cellMap;


public:
    Gamemap();
    Gamemap(int level);
    Gamemap(QVector<QVector<int>> target);
    QVector<QVector<int>> Getmap();
    void Initcellmap();
    void Clearmap(){cellMap.clear();}
    void setLevel(int lv);
    void printmap();
    void Resetmap();
    void Initgamemap();
    bool isEmpty(){return currentCount==0;}
    void setCell(int x,int y,int status);
    bool isSametype(int x1,int y1,int x2,int y2);
    bool oneLine(int x1,int y1,int x2,int y2);
    bool twoLine(int x1,int y1,int x2,int y2);
    bool threeLine(int x1,int y1,int x2,int y2);
};

#endif // GAMEMAP_H
