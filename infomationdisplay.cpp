#include "infomationdisplay.h"
#include "ui_infomationdisplay.h"

InfomationDisplay::InfomationDisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InfomationDisplay)
{
    ui->setupUi(this);
}

InfomationDisplay::~InfomationDisplay()
{
    delete ui;
}
