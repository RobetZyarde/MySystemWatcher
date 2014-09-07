#include "label3.h"
#include "ui_label3.h"

label3::label3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::label3)
{
    ui->setupUi(this);
    QLabel *number=ui->number;


    QLabel *opnumber=ui->opnumber;
}

label3::~label3()
{
    delete ui;
}
