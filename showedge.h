#ifndef SHOWEDGE_H
#define SHOWEDGE_H

#include <QDialog>

namespace Ui {
class ShowEdge;
}

class ShowEdge : public QDialog
{
    Q_OBJECT

public:
    explicit ShowEdge(QWidget *parent = nullptr);
    ~ShowEdge();
     int source=0;
     int dest=0;
     int weight=0;

private slots:
    void on_pushButton_clicked();

private:
    Ui::ShowEdge *ui;
};

#endif // SHOWEDGE_H
