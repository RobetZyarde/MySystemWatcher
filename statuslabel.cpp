#include "statuslabel.h"
#include "ui_statuslabel.h"

StatusLabel::StatusLabel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StatusLabel)
{
    ui->setupUi(this);
}

StatusLabel::~StatusLabel()
{
    delete ui;
}
