#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPushButton>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/resource/image/xxb.jpg"));
    this->player = new QMediaPlayer(this);//设置背景音乐
    this->player->setMedia(QUrl("qrc:/resource/music/yourname.mp3"));
    this->player->setVolume(60);//音量
    this-> player->play();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_freeButton_clicked()
{
    int level=0;
    this->game=new Game(level);
    this->game->setWindowTitle("基本模式");
    this->game->show();
    this->hide();

    // 设置返回监听
    connect(this->game,&Game::exit,
            [=]() mutable
            {
                this->game->hide();
                this->show();
            });
}

void MainWindow::on_challengeButton_clicked()
{
    int level=1;
    this->game=new Game(level);
    this->game->setWindowTitle("关卡模式");
    this->game->show();
    this->hide();
    // 设置返回监听
    connect(this->game,&Game::exit,
            [=]() mutable
            {
                this->game->hide();
                this->show();
            });
}

void MainWindow::on_ranklistButton_clicked()
{
    this->ranklist=new Ranklist();
    this->ranklist->setWindowTitle("排行榜");
    this->ranklist->show();
}

void MainWindow::on_helpButton_clicked()
{
    this->help=new Help();
    this->help->setWindowTitle("帮助");
    this->help->show();
}

void MainWindow::on_settingsButton_clicked()
{
    this->setting=new Settings();
    this->setting->setWindowTitle("设置");
    this->setting->show();
    connect(this->setting,&Settings::isPlay,[=](bool isplay)
    {
        if(isplay){
            delete player;
            qDebug()<<"点击了开启"<<endl;
            player = new QMediaPlayer(this);//设置背景音乐
            player->setMedia(QUrl("qrc:/resource/music/yourname.mp3"));
            player->setVolume(60);//音量
            player->play();
        }
        else{
            qDebug()<<"点击了关闭"<<endl;
            // 释放
           delete player;
           player = NULL;
        }
    });
    // 监听音量调整
    connect(this->setting,&Settings::changeSound,[=](int value)
    {
        this->player->setVolume(value);
    });
}
