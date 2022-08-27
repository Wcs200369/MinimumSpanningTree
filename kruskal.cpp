#include "kruskal.h"
#include "showedge.h"
#include "kruskalEdge.h"
#include <bits/stdc++.h>


//this file handles Kruskal Algorithm
//code concept taken from https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/
class Edge
{
    public:
    int src, dest, weight;
};

class Graph
{
    public:
    // V-> Number of vertices, E-> Number of edges
    int V, E;
    Edge* edge;
};

Graph* kruskal_graph;
int e;


Graph* createGraph(int V, int E)
{
    Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;

    graph->edge = new Edge[E];

    return graph;
}


class subset
{
    public:
    int parent;
    int rank;
};

int find(subset subsets[], int i)
{
    // find root and make root as parent of i
    // (path compression)
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}


void Union(subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    // Attach smaller rank tree under root of high
    // rank tree (Union by Rank)
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;

    // If ranks are same, then make one as root and
    // increment its rank by one
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}


int myComp(const void* a, const void* b)
{
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->weight > b1->weight;
}


int sum=0;
Edge result[20];
 // THis will store the resultant MST
void KruskalMST(Graph* graph)
{
    int V = graph->V;

    e = 0; // An index variable, used for result[]
    int i = 0;
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);


    subset *subsets = new subset[( V * sizeof(subset) )];

    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < graph->E)
    {
        Edge next_edge = graph->edge[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
}

void Kruskal:: createGraphs(int V,int E){
    kruskal_graph = createGraph(V, E);
}

void Kruskal::updateGraph(int source,int dest, int weight){
    kruskal_graph->edge[edge_counter].src = source;
    kruskal_graph->edge[edge_counter].dest = dest;
    kruskal_graph->edge[edge_counter].weight = weight;
    edge_counter++;
}

void Kruskal::kruskalGraph(kruskalEdge kedge[20]){
     KruskalMST(kruskal_graph);
    //graph_weight=sum;
    for(int i = 0; i<e ; i++){
        kedge[i].src=result[i].src;
        kedge[i].dest=result[i].dest;
        kedge[i].weight=result[i].weight;
    }
 }
