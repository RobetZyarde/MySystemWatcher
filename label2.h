#ifndef LABEL2_H
#define LABEL2_H

#include <QWidget>

namespace Ui {
class label2;
}

class label2 : public QWidget
{
    Q_OBJECT

public:
    explicit label2(QWidget *parent = 0);
    ~label2();
    void sethandle(int content);
    void setline2(int content);
    void setprogress(int content);
    void settime(int content);
    void sethandon(int content,int content2);

private:
    Ui::label2 *ui;
};

#endif // LABEL2_H
