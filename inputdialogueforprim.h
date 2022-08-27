#ifndef INPUTDIALOGUEFORPRIM_H
#define INPUTDIALOGUEFORPRIM_H

#include <QDialog>

namespace Ui {
class inputdialogueforprim;
}

class inputdialogueforprim : public QDialog
{
    Q_OBJECT

public:
    explicit inputdialogueforprim(QWidget *parent = nullptr);
    ~inputdialogueforprim();

private:
    Ui::inputdialogueforprim *ui;
};

#endif // INPUTDIALOGUEFORPRIM_H
