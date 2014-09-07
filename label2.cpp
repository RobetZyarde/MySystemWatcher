#include "label2.h"
#include "ui_label2.h"
#include <windows.h>
#include <stdio.h>

label2::label2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::label2)
{
    ui->setupUi(this);
    QLabel *handle=ui->handle;
    handle->setText("strhandle");

    QLabel *line2=ui->line_2;
    line2->setText("strline");

    QLabel *progress=ui->progress;
    progress->setText("strpro");

    SYSTEMTIME sys;
    GetLocalTime( &sys );
   // printf( "%4d/%02d/%02d %02d:%02d:%02d.%03d 星期%1d\n",sys.wYear,sys.wMonth,sys.wDay,sys.wHour,sys.wMinute, sys.wSecond,sys.wMilliseconds,sys.wDayOfWeek);
    int hour = sys.wHour;
    QLabel *time=ui->time;
    time->setText(QString::number(hour));

    QLabel *handon=ui->handon;
    handon->setText("strhandon");
}

label2::~label2()
{
    delete ui;
}

void label2::sethandle(int content){
    ui->handle->setText(QString::number(content,10));
}

void label2::setline2(int content){
    ui->line_2->setText(QString::number(content,10));
}

void label2::setprogress(int content){
    ui->progress->setText(QString::number(content,10));
}

void label2::settime(int content){
    ui->time->setText(QString::number(content,10));
}

void label2::sethandon(int content,int content2){
    ui->handon->setText(QString::number(content,10)+"/"+QString::number(content2,10));
}
