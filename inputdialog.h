#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>

namespace Ui {
class inputDialog;
}

class inputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit inputDialog(QWidget *parent = nullptr);
    ~inputDialog();
    QString s;


private slots:


private:
    Ui::inputDialog *ui;
};

#endif // INPUTDIALOG_H
