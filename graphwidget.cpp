#include "graphwidget.h"
#include "kruskalEdge.h"
#include "edge.h"
#include "node.h"
#include <math.h>
#include <QKeyEvent>
#include <QKeyEvent>
#include <QRandomGenerator>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include <QButtonGroup>
#include <QPushButton>
#include <QDialog>
#include <QLabel>
#include <iostream>
#include<sstream>
#include "info.h"
#include "mainscreen.h"
#include "inputdialog.h"
#include "showedge.h"
#include <QIntValidator>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>

//this cpp file manages the scene where graph implementation is taking place

int counter=0;

GraphWidget::GraphWidget(QWidget *parent)
    : QGraphicsView(parent)
{
    scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(0, 0, 800, 800);  //works perfectly

    QPushButton *infoButton = new QPushButton();
    connect(infoButton, &QPushButton::clicked,this, handle_infoButton);
    infoButton->setText("Info");
    infoButton->setFixedSize(100,50);
    scene->addWidget(infoButton);

    QPushButton *addEdgeButton = new QPushButton();
    connect(addEdgeButton, &QPushButton::clicked,this, handle_ShowEdgeButton);
    addEdgeButton->setText("Add Edge");
    addEdgeButton->setFixedSize(100,50);
    addEdgeButton->move(150,0);  //150 represents the x coordinate it would
    scene->addWidget(addEdgeButton);

    QPushButton *kruskalButton= new QPushButton();
    connect(kruskalButton, &QPushButton::clicked,this, handle_kruskalButton);
    kruskalButton->setText("Kruskal");
    kruskalButton->setFixedSize(100,50);
    kruskalButton->move(150+150,0);  //150 represents the x coordinate it would
    scene->addWidget(kruskalButton);

    QPushButton *primButton= new QPushButton();
    connect(primButton, &QPushButton::clicked,this, handle_primButton);
    primButton->setText("Prim");
    primButton->setFixedSize(100,50);
    primButton->move(150+150+150,0);  //150 represents the x coordinate it would
    scene->addWidget(primButton);

    setScene(scene);
    mw.setModal(true);
    mw.exec();

    kgraph.createGraphs(mw.numberofnodes,mw.numberofedges);

    setCacheMode(CacheBackground);
    setViewportUpdateMode(BoundingRectViewportUpdate);
    setRenderHint(QPainter::Antialiasing);
    setTransformationAnchor(AnchorUnderMouse);
    scale(qreal(0.9), qreal(0.9));  //positions the scene in the center

    source=new Node(this);
    dest=new Node(this);

     if(counter==0){
        for(int i=0;i<mw.numberofnodes;i++){
            node[i]=new Node(this);
        }
     }

}


void GraphWidget::drawBackground(QPainter *painter, const QRectF &rect)
{
    Q_UNUSED(rect);

    // Shadow
    QRectF sceneRect = this->sceneRect();

    // Fill
    QLinearGradient gradient(sceneRect.topLeft(), sceneRect.bottomRight());
    gradient.setColorAt(0, Qt::white);
    gradient.setColorAt(1, Qt::lightGray);
    painter->fillRect(rect.intersected(sceneRect), gradient);
    painter->setBrush(Qt::NoBrush);
    painter->drawRect(sceneRect);
}

void GraphWidget::scaleView(qreal scaleFactor)
  {
    qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
    if (factor < 0.07 || factor > 100)
        return;

    scale(scaleFactor, scaleFactor);

}

Edge *edge;
void GraphWidget::mouseDoubleClickEvent(QMouseEvent *event){

    if(counter<mw.numberofnodes){
        scene->addItem(node[counter]);
       node[counter]->setPos(event->x()+40,event->y()+40);
    }
    counter++;
 }

int count=0;
int weight[20];
void GraphWidget :: handle_ShowEdgeButton(){

    if(count<=mw.numberofedges){
        se.setModal(true);
        se.exec();
        source=NULL;
        dest=NULL;

        for(int i=0;i<mw.numberofnodes;i++){
            if(se.source==i) source=node[i];
            if(se.dest==i)  dest=node[i];
        }

        if(source!=NULL && dest!=NULL){
            edge[edge_counter] = new Edge(source,dest);
            weight[edge_counter]=se.weight;
            scene->addItem(edge[edge_counter]);
            edge_counter++;
            kgraph.updateGraph(se.source,se.dest,se.weight);
        }
        count++;
    }

}

void GraphWidget :: handle_infoButton(){
    Info sc;
    sc.setModal(true);
    sc.exec();

}

void GraphWidget ::handle_primButton(){
    inputDialog id;
     kgraph.kruskalGraph(kedge);


    for(int i=0;i<mw.numberofedges;i++){
                edge[i]->hide();       }

    for(int i=0;i<mw.numberofedges;i++){
                edge[i]->hide();            }

            for(int i=0;i<mw.numberofedges;i++){
                edge[i]->hide();
            }

            for(int i=0; i<mw.numberofedges ;i++){
                for(int j=0;j<mw.numberofedges;j++){
                   if(kedge[i].weight == weight[j]){
                      edge[j]->show();
                      continue;
                   }
                }
            }
         inputdialogueforprim  idp;
         idp.setModal(true);
         idp.exec();
}

void  GraphWidget ::handle_kruskalButton(){

    inputDialog id;
     kgraph.kruskalGraph(kedge);

    for(int i=0;i<mw.numberofedges;i++){
                edge[i]->hide();       }

    for(int i=0;i<mw.numberofedges;i++){
                edge[i]->hide();            }

            for(int i=0;i<mw.numberofedges;i++){
                edge[i]->hide();
            }

            for(int i=0; i<mw.numberofedges ;i++){
                for(int j=0;j<mw.numberofedges;j++){
                   if(kedge[i].weight == weight[j]){
                      edge[j]->show();
                      continue;
                   }
                }
            }

            id.setModal(true);
            id.exec();

}

void GraphWidget::zoomIn()
{
     scaleView(qreal(1.2));
}

void GraphWidget::zoomOut()
{
   scaleView(1 / qreal(1.2));
}

void GraphWidget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Plus:
        zoomIn();
        break;
    case Qt::Key_Minus:
        zoomOut();
        break;
    default:
        QGraphicsView::keyPressEvent(event);
    }

}
