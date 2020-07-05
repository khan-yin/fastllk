#include "game.h"
#include "ui_game.h"
#include<QDebug>
#include<iostream>
#include<QPen>
#include<QPainter>
#include<QMessageBox>
#include <QTimer>
#include"msgbox.h"
using namespace std;
Game::Game(int level,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
    ui->frame->setParent(this);
    this->level = level;
    this->map = new Gamemap(this->level);
    ui->frame->hide();
    this->msgb = new Msgbox();
    this->setWindowIcon(QIcon(":/resource/image/xxb.jpg"));
}

Game::~Game()
{
    delete ui;
}

bool Game::Checkclick(int x1,int y1,int x2,int y2)
{
    bool flag=this->map->isSametype(x1,y1,x2,y2);
    if(flag)
    {
        if(this->map->oneLine(x1,y1,x2,y2))
        {
            return true;
        }
        else if(this->map->twoLine(x1,y1,x2,y2))
        {
            return true;
        }
        else if(this->map->threeLine(x1,y1,x2,y2))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else{
        return false;
    }

}
//void draw(QVector<Cellbtn> m)
//{
//    QPainter p;//创建画家对象
//    QPen pen;//创建画笔
//    pen.setColor(QColor(14,9,234));
//    pen.setWidth(5);
//    p.setPen(pen);
//    for(int i=0;i<m.length();i++)
//    {
//        p.drawLines(a);
//    }
//    p.
//}

void Game::on_startButton_clicked()
{

    this->score=0;
    ui->scorelabel->setText(QString::number(score));
    this->Initcellbtnmap(ui->frame,this->map->Getmap());
    ui->frame->show();
    setTime(100);//设置时间
    ui->startButton->setDisabled(true);
    connect(this,&Game::sendPoint,
            [=](int x,int y) mutable
            {
                this->cellbtnMap[x][y]->setColor(true);
                if(Clicked)
                {
                    bool flag=Checkclick(prex,prey,x,y);
//                    qDebug()<<flag;
                    if(flag==true)
                    {
                        map->setCell(prex,prey,0);
                        map->setCell(x,y,0);
                        cellbtnMap[prex][prey]->delImg();
                        cellbtnMap[x][y]->delImg();
                        Clicked=false;
                        this->score+=5;
                        ui->scorelabel->setText(QString::number(score));
                        if(map->isEmpty())
                        {
                            qDebug()<<"胜利";
                            if(msgb!=NULL)
                            {
                                msgb->setWindowTitle("game over");
                                msgb->setContent("成功过关");
                                msgb->show();
                            }

                            ui->startButton->setEnabled(true);
//                            qDebug()<<333;
                            this->cellbtnMap.clear();
//                            qDebug()<<cellbtnMap.length();
                            this->map->Clearmap();
                            if (this->level>0)
                            {
                                this->level++;
                            }
                            this->map->setLevel(this->level);
//                            delete this->map;
//                            qDebug()<<1212;
                            this->isStop = true;
//                            qDebug()<<212;
                            ui->frame->hide();
                        }
//                        qDebug()<<1;
                    }
                    else{
                        this->cellbtnMap[prex][prey]->setColor(false);
                        this->cellbtnMap[x][y]->setColor(true);
                        prex=x;
                        prey=y;
                    }

                }
                else{
                    Clicked=true;
                    prex=x;
                    prey=y;
                }
            });
//    this->map->Initgamemap();
}

void Game::on_stopButton_clicked()
{
      QString str=ui->stopButton->text();
//      qDebug()<<str;
      if (str=="暂停游戏"){
            ui->frame->hide();
            this->isStop = true;
            ui->attendtionButton->setDisabled(true);
            ui->resetButton->setDisabled(true);
      }
      else{

            ui->frame->show();
            ui->attendtionButton->setEnabled(true);
            ui->resetButton->setEnabled(true);
            this->isStop = false;
      }
      str=="暂停游戏"? str="游戏继续":str="暂停游戏";
      ui->stopButton->setText(str);


}

void Game::on_attendtionButton_clicked()
{
    Msgbox* msgb = new Msgbox;
    msgb->setWindowTitle("提示");
    msgb->setContent("这都不会?");
    msgb->show();
}

void Game::on_resetButton_clicked()
{
    this->map->Resetmap();
    cout<<"ss"<<endl;
//    qDebug()<<this->map->Getmap();
//    this->cellbtnMap.clear();
    this->Resetcellbtnmap(this->map->Getmap());
    ui->frame->show();
}

void Game::on_leftButton_clicked()
{
    emit exit();
}

void Game::Initcellbtnmap(QWidget *parent,QVector<QVector<int>> arr)
{
    //拿到长度
    int iLen = arr.length();
    // 二重循环进行初始化
    for(int i=0;i<iLen;i++){
           QVector<Cellbtn*> tempCellArr;
           for(int j=0;j<arr[i].length();j++){
               Cellbtn *temp = new Cellbtn(parent);
               // 设置位置和坐标
                temp->setPlace(55*(j+1),55*(i+1));
                temp->setx(i);
                temp->sety(j);
                connect(temp,&Cellbtn::isClicked,
                        [=](int x,int y) mutable
                        {
//                            qDebug()<<x<<y;
//                            temp->setColor(true);
                          emit sendPoint(x,y);
                        }
                );
                // 设置Logo
                temp->setImg(arr[i][j]);
                // 插入返回结果
               tempCellArr.push_back(temp);
               if(arr[i][j] ==0){
                   temp->delImg();
               }
           }
           cellbtnMap.push_back(tempCellArr);
       }


}

void Game::Resetcellbtnmap(QVector<QVector<int> > arr)
{
    int iLen = arr.length();
    // 二重循环进行初始化
    for(int i=0;i<iLen;i++){
           for(int j=0;j<arr[i].length();j++){
               if(arr[i][j] ==0){
                    this->cellbtnMap[i][j]->delImg();
               }
               else{
                   if(this->cellbtnMap[i][j]->isHidden())
                   {
                       this->cellbtnMap[i][j]->showImg();
                   }
               }
               this->cellbtnMap[i][j]->setImg(arr[i][j]);
              this->cellbtnMap[i][j]->setx(i);
              this->cellbtnMap[i][j]->sety(j);
           }
       }
}

// 进度条控制
void Game::setTime(int t)
{
       if(t == 0 ){
       this->ui->progressBar->hide();
       }
       else{
               time = t;
               ui->progressBar->setMaximum(time);
               ui->progressBar->setValue(time);
               QTimer *progressSetting = new QTimer();
               progressSetting->start(1000);
               // 定时器标志
               this->isStop = false;
               connect(progressSetting,&QTimer::timeout,[=]()mutable{
                   // 定时
                   if(!this->isStop){
                         ui->progressBar->setValue(--this->time);
                   }
                   if(time==0){
                       progressSetting->stop();
                       Msgbox* msgb = new Msgbox;
                       msgb->setWindowTitle("game over");
                       msgb->setContent("time over");
                       msgb->show();
                       ui->startButton->setEnabled(true);
                       this->cellbtnMap.clear();
                       this->map->Clearmap();
                       this->isStop = true;
                       ui->frame->hide();
                    }
    });
}
}
