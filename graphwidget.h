#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include "edge.h"

#include "info.h"
#include "mainscreen.h"

#include "showedge.h"
#include <QLabel>
#include <QString>
#include "kruskal.h"
#include "kruskalEdge.h"
#include "inputdialog.h"
#include "inputdialogueforprim.h"

class Node;

class GraphWidget : public QGraphicsView
{
    Q_OBJECT

public:
    GraphWidget(QWidget *parent = nullptr);

    Node *node[50];
    Edge *edge[50];
    Node *source;
    Node *dest;
    mainsceen mw;
    ShowEdge se;
    QLabel *lb;
    kruskalEdge kedge[20];
    Kruskal kgraph;
    int edge_counter=0;

public slots:
    void zoomIn();
    void zoomOut();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;  //adds node on scene
    void drawBackground(QPainter *painter, const QRectF &rect) override;
    void scaleView(qreal scaleFactor);
    void handle_ShowEdgeButton();
    void handle_infoButton();
    void handle_primButton();
    void handle_kruskalButton();

private:

    Node *centerNode;
    QGraphicsScene *scene;
};
//! [0]

#endif // GRAPHWIDGET_H
