#ifndef MAINSCEEN_H
#define MAINSCEEN_H

#include <QDialog>

namespace Ui {
class mainsceen;
}

class mainsceen : public QDialog
{
    Q_OBJECT

public:
    explicit mainsceen(QWidget *parent = nullptr);
    int numberofnodes=0;
    int numberofedges=0;
    ~mainsceen();

private slots:
    void on_pushButton_clicked();

private:
    Ui::mainsceen *ui;
};

#endif // MAINSCEEN_H
