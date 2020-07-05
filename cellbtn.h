#ifndef CELLBTN_H
#define CELLBTN_H

#include <QWidget>
#include <QPushButton>
#include<QString>
class Cellbtn : public QPushButton
{
    Q_OBJECT

public:
    explicit Cellbtn(QWidget *parent = 0);
    ~Cellbtn();
    int Getx();
    int Gety();
    void setx(int x);
    void sety(int y);
    void setPlace(int x,int y);
    void setImg(int count);
    void delImg();
    void showImg();
    void setColor(bool flag);


private:
    int x;
    int y;
    bool status;
    QString imgnumber;

signals:
    isClicked(int x,int y);

};

#endif // CELLBTN_H
