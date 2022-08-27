#include "inputdialogueforprim.h"
#include "ui_inputdialogueforprim.h"


//this pops-up after the prim button is clicked
inputdialogueforprim::inputdialogueforprim(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inputdialogueforprim)
{
    //ui->setupUi(this);
}

inputdialogueforprim::~inputdialogueforprim()
{
    delete ui;
}
