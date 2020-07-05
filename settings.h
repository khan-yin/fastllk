#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>

namespace Ui {
class Settings;
}

class Settings : public QWidget
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();

private slots:
    void on_open_clicked();

    void on_close_clicked();

    void on_sound_valueChanged(int value);

private:
    Ui::Settings *ui;

signals:
    void isPlay(bool);
    void changeSound(int);

};

#endif // SETTINGS_H
