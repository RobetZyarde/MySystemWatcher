#ifndef LABEL3_H
#define LABEL3_H

#include <QWidget>

namespace Ui {
class label3;
}

class label3 : public QWidget
{
    Q_OBJECT

public:
    explicit label3(QWidget *parent = 0);
    ~label3();
    void setnumber(int content);
    void setopnumber(int content);

private:
    Ui::label3 *ui;
};

#endif // LABEL3_H
