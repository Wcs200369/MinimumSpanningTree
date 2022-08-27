#include "showedge.h"
#include "ui_showedge.h"



//this file handles events when the Add Edge Button is clicked
ShowEdge::ShowEdge(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowEdge)
{
    ui->setupUi(this);
}

ShowEdge::~ShowEdge()
{
    delete ui;
}

void ShowEdge::on_pushButton_clicked()
{
    QString str = ui->spinBox->cleanText();
    source= str.toInt();
    QString str2 = ui->spinBox_2->cleanText();
    dest= str2.toInt();
    QString str3 = ui->spinBox_3->cleanText();
    weight= str3.toInt();
}
