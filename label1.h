#ifndef LABEL1_H
#define LABEL1_H

#include <QWidget>

namespace Ui {
class label1;
}

class label1 : public QWidget
{
    Q_OBJECT

public:
    explicit label1(QWidget *parent = 0);
    ~label1();
    void setALL(int content);
    void setcache(int content);
    void setavailable(int content);
    void setfree(int content);

private:
    Ui::label1 *ui;
};

#endif // LABEL1_H
