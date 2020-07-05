#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/resource/image/xxb.jpg"));
}

Settings::~Settings()
{
    delete ui;
}

void Settings::on_open_clicked()
{
    emit isPlay(true);
}

void Settings::on_close_clicked()
{
    emit isPlay(false);
}

void Settings::on_sound_valueChanged(int value)
{
    emit changeSound(value);
}
