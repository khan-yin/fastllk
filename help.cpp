#include "help.h"
#include "ui_help.h"

Help::Help(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Help)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/resource/image/xxb.jpg"));
}

Help::~Help()
{
    delete ui;
}
