#ifndef INFO_H
#define INFO_H

#include <QDialog>

namespace Ui {
class Info;
}

class Info : public QDialog
{
    Q_OBJECT

public:
    explicit Info(QWidget *parent = nullptr);
    ~Info();

private slots:
   /* void on_spinBox_valueChanged(int arg1);

    void on_lineEdit_textEdited(const QString &arg1);

    void on_pushButton_clicked();

    void on_lineEdit_returnPressed();*/

private:
    Ui::Info *ui;
};

#endif // INFO_H
