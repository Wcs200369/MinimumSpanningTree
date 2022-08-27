#include "graphwidget.h"
#include <QApplication>
#include <QPushButton>
#include "edge.h"


//this file is required to start-up the gui program

#include <QMainWindow>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    GraphWidget *widget = new GraphWidget;
    QMainWindow mainWindow;
    mainWindow.setCentralWidget(widget);
    mainWindow.setFixedSize(800,800);

    mainWindow.show();
    return app.exec();


}
