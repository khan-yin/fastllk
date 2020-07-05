#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include<QPushButton>
#include"help.h"
#include"game.h"
#include"settings.h"
#include"ranklist.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_freeButton_clicked();

    void on_challengeButton_clicked();

    void on_ranklistButton_clicked();

    void on_helpButton_clicked();

    void on_settingsButton_clicked();

private:
    Ui::MainWindow *ui;
    Help *help;
    Game *game;
    QMediaPlayer *player;
    Settings *setting;
    Ranklist *ranklist;

};

#endif // MAINWINDOW_H
