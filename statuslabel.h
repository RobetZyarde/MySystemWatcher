#ifndef STATUSLABEL_H
#define STATUSLABEL_H

#include <QWidget>

namespace Ui {
class StatusLabel;
}

class StatusLabel : public QWidget
{
    Q_OBJECT

public:
    explicit StatusLabel(QWidget *parent = 0);
    ~StatusLabel();

private:
    Ui::StatusLabel *ui;
};

#endif // STATUSLABEL_H
