#include "label3.h"
#include "ui_label3.h"

label3::label3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::label3)
{
    ui->setupUi(this);
    QLabel *number=ui->number;
    number->setText("strnumber");

    QLabel *opnumber=ui->opnumber;
    opnumber->setText("stropnumber");
}

label3::~label3()
{
    delete ui;
}

void label3::setnumber(int content){
    ui->number->setText(QString::number(content,10));
}

void label3::setopnumber(int content){
    ui->opnumber->setText(QString::number(content,10));
}
