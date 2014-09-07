#include "label1.h"
#include "ui_label1.h"

label1::label1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::label1)
{
    ui->setupUi(this);
    QLabel *a=ui->All;
//实现方法如下： 构造函数中加入： QTimer *timer = new QTime
   //r(this); connect(timer,SINGAL(timeout()),this,SLOT(timer_deal_slot_function()));
   //槽函数这样写：（获取系统时间） QDateTime dateTime = QDateTime::currentDateTime(); int y=dateTime.date().year();
   //int m=dateTime.date().month(); int d=dateTime.date().day(); QString strTime=dateTime.time().toString();
   //ui->label->setText(strTime+" "+QString::number(y)+"/"+QString::number(m)+"/"+QString::number(d));
   //显示时间格式为例如 12:24:33 2008/8/28 ￥
   QLabel *c=ui->cache;

   QLabel *av=ui->available;


   QLabel *f=ui->free;

}

label1::~label1()
{
    delete ui;
}
