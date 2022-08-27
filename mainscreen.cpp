#include "mainscreen.h"
#include "ui_mainsceen.h"
#include "graphwidget.h"


//the first set-up that is seeen when the program is executed
mainsceen::mainsceen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainsceen)
{
    ui->setupUi(this);
}

mainsceen::~mainsceen()
{
    delete ui;
}

void mainsceen::on_pushButton_clicked()
{
    QString str = ui->spinBox->cleanText();
    numberofnodes= str.toInt();

    QString str1 = ui->spinBox_2->cleanText();
    numberofedges= str1.toInt();
}


