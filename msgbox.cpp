#include "msgbox.h"
#include "ui_msgbox.h"
#include<QString>
Msgbox::Msgbox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Msgbox)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/resource/image/xxb.jpg"));
}

Msgbox::~Msgbox()
{
    delete ui;
}
void Msgbox::setContent(QString msg)
{
    ui->label_2->setText(msg);
}

void Msgbox::on_pushButton_clicked()
{
    this->hide();

}
