#ifndef RANKLIST_H
#define RANKLIST_H

#include <QWidget>

namespace Ui {
class Ranklist;
}

class Ranklist : public QWidget
{
    Q_OBJECT

public:
    explicit Ranklist(QWidget *parent = 0);
    ~Ranklist();

private:
    Ui::Ranklist *ui;
};

#endif // RANKLIST_H
