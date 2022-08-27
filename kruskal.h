#ifndef KRUSKAL_H
#define KRUSKAL_H
#include "showedge.h"
#include "kruskalEdge.h"


class Kruskal
{
public:
    //Kruskal();
      int V=0;
      int edge_counter;
      void createGraphs(int V,int E);
     void updateGraph(int source,int dest, int weight);
     void kruskalGraph(kruskalEdge kedge[20]);
     int source_array[20];
     int dest_array[20] ;
     int weight_array[20];
     int graph_weight;

};


#endif // KRUSKAL_H

