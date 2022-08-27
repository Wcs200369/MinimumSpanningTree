//include "prim.h"
#include "mainscreen.h"

//collected from www.studytonight.com

//due to lack of time and complications this file was not implemented in gui

/*
mainsceen mw;
const int V=mw.numberofnodes;

int min_Key(int key[], bool visited[])
{
    int min = 999, min_index;  // 999 represents an Infinite value

    for (int v = 0; v < V; v++) {
        if (visited[v] == false && key[v] < min) {
            // vertex should not be visited
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

int print_MST(int parent[], int cost[V][V])
{
    int minCost=0;
    for (int i = 1; i< V; i++) {
            //parent[i]<<" - "<<i<<" \t"<<cost[i][parent[i]]<<" \n";
            minCost+=cost[i][parent[i]];
        }
}

void find_MST(int cost[V][V])
{
    int parent[V], key[V];
    bool visited[V];

    // Initialize all the arrays
    for (int i = 0; i< V; i++) {
        key[i] = 999;    // 99 represents an Infinite value
        visited[i] = false;
        parent[i]=-1;
    }

    key[0] = 0;  // Include first vertex in MST by setting its key vaue to 0.
    parent[0] = -1; // First node is always root of MST

    // The MST will have maximum V-1 vertices
    for (int x = 0; x < V - 1; x++)
    {
        int u = min_Key(key, visited);

        visited[u] = true;
        for (int v = 0; v < V; v++)
        {
            if (cost[u][v]!=0 && visited[v] == false && cost[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = cost[u][v];
            }
        }
    }

}
int cost[20][20];
void createGraphs(int V,int E){

      for (int i=0;i<V;i++)
      {
          for(int j=0;j<V;j++)
          {
              cost[i][j]=0;
          }
      }
}

void primGraph(){
      find_MST(cost);
}
*/
