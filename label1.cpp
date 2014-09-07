#include "label1.h"
#include "ui_label1.h"

label1::label1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::label1)
{
    ui->setupUi(this);
   QLabel *a=ui->All;
   a->setText("strALL");

   QLabel *c=ui->cache;
   c->setText("strcache");

   QLabel *av=ui->available;
   av->setText("stravailable");

   QLabel *f=ui->free;
   f->setText("strfree");
}

label1::~label1()
{
    delete ui;
}

void label1::setALL(int content){
    ui->All->setText(QString::number(content,10));
}


void label1::setcache(int content){
    ui->cache->setText(QString::number(content,10));
}

void label1::setavailable(int content){
    ui->available->setText(QString::number(content,10));
}

void label1::setfree(int content){
    ui->free->setText(QString::number(content,10));
}

