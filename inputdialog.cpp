#include "inputdialog.h"
#include "ui_inputdialog.h"
#include "graphwidget.h"


//this pops-up after the kruskal button is clicked
inputDialog::inputDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inputDialog)
{
    ui->setupUi(this);
    ui->label_2->setText("Using Kruskal's Algorithm: ");

}

inputDialog::~inputDialog()
{
    delete ui;
}

