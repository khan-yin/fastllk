#ifndef MSGBOX_H
#define MSGBOX_H

#include <QWidget>

namespace Ui {
class Msgbox;
}

class Msgbox : public QWidget
{
    Q_OBJECT

public:
    explicit Msgbox(QWidget *parent = 0);
    void setContent(QString msg);


    ~Msgbox();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Msgbox *ui;
};

#endif // MSGBOX_H
