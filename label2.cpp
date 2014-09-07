#include "label2.h"
#include "ui_label2.h"

label2::label2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::label2)
{
    ui->setupUi(this);

    QLabel *handle=ui->handle;


    QLabel *line2=ui->line_2;


    QLabel *progress=ui->progress;


    QLabel *time=ui->time;


    QLabel *handon=ui->handon;

}
label2::~label2()
{
    delete ui;
}
