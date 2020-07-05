#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include<QString>
#include<QVector>
#include<QPushButton>
#include"gamemap.h"
#include"msgbox.h"
#include"cellbtn.h"
namespace Ui {
class Game;
}

class Game : public QWidget
{
    Q_OBJECT

public:
    explicit Game(int level,QWidget *parent = 0);
    ~Game();

private slots:
    void on_startButton_clicked();
    void on_stopButton_clicked();
    void on_attendtionButton_clicked();
    void on_resetButton_clicked();
    void on_leftButton_clicked();
    void Initcellbtnmap(QWidget *parent,QVector<QVector<int>> arr);
    void Resetcellbtnmap(QVector<QVector<int>> arr);
    bool Checkclick(int x1,int y1,int x2,int y2);
    void setTime(int t);

private:
    Ui::Game *ui;
    int level;
    bool isStop;
    int time;
    Gamemap *map;
    int prex;
    int prey;
    bool Clicked;
    int score;
    Msgbox* msgb;
    QVector<QVector<Cellbtn*>> cellbtnMap;

// 信号发送
signals:
     void exit();
     void sendPoint(int x,int y);

public slots:

};

#endif // GAME_H
