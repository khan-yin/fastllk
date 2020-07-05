#include "ranklist.h"
#include "ui_ranklist.h"

Ranklist::Ranklist(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ranklist)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/resource/image/xxb.jpg"));
}

Ranklist::~Ranklist()
{
    delete ui;
}
