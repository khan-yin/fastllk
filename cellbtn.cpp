#include "cellbtn.h"
#include<QDebug>
Cellbtn::Cellbtn(QWidget *parent) :QPushButton(parent)
{
    setText("");
    resize(50,50);
    connect(this,&QPushButton::clicked,
            [=]() mutable
            {
                // 分发坐标
                emit isClicked(Getx() ,Gety());
            });
}

Cellbtn::~Cellbtn()
{

}

int Cellbtn::Getx()
{
    return x;
}

int Cellbtn::Gety()
{
    return y;
}


void Cellbtn::setx(int x)
{
     this->x=x;
}

void Cellbtn::sety(int y)
{
    this->y=y;
}

void Cellbtn::setPlace(int x,int y)
{
    this->move(x,y);
}


void Cellbtn::setImg(int count)
{
    // 因为只有7张图
     count = count % 8;

     QString countString = QString::number(count,10);
     this -> imgnumber = countString;

     // 设置图片背景
     QString currentStyle = "QPushButton{background-image:url(:/resource/image/logo("+countString+").png);background-position:center;}";
     setStyleSheet(currentStyle);
}

void Cellbtn::delImg()
{
    this->hide();
}

void Cellbtn::showImg()
{
    if(this->isHidden()){
        QString temp =  "QPushButton{background-image:url(:/resource/image/logo("+this->imgnumber+").png);background-position:center;}";
        this->setStyleSheet(temp);
          this->show();
    }

}

// 设置点击反馈
void Cellbtn::setColor(bool flag)
{
    qDebug()<<imgnumber;
    if(flag){
        // 边框设置为red
        QString temp =  "QPushButton{background-image:url(:/resource/image/logo("+this->imgnumber+").png);background-position:center;border:2px solid red;}";
        this->setStyleSheet(temp);
    }
    else{
        QString temp =  "QPushButton{background-image:url(:/resource/image/logo("+this->imgnumber+").png);background-position:center;}";
        this->setStyleSheet(temp);
//        this->setStyleSheet( "QPushButton{background-image:url(:/resource/image/logo("+countCurrent+").png);background-position:center;");
    }
}
