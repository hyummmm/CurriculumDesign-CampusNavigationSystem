#include "searchpath.h"
#include "ui_searchpath.h"

SearchPath::SearchPath(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchPath)
{
    ui->setupUi(this);
}

SearchPath::~SearchPath()
{
    delete ui;
}
