#include "info.h"
#include "ui_info.h"
#include <QIntValidator>
#include "graphwidget.h"
#include <sstream>
#include <iostream>


//this file is for the info button seen on the graph scene.

Info::Info(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Info)
{
    ui->setupUi(this);

}
int integer_value=0;
Info::~Info()
{
    delete ui;
}

