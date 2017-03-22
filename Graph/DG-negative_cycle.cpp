#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <limits.h>

#define INFINITY 99999
using namespace std;
//struct for the edges of the graph
struct Edge {
  int u;  //start vertex of the edge
  int v;  //end vertex of the edge
  int w;  //weight of the edge (u,v)
};

//Graph - it consists of edges
struct Graph {
  int V;  //total number of vertices in the graph
  int E;  //total number of edges in the graph
  struct Edge *edge;  //array of edges
};




int bellmanford(Graph *g, int source, vector<int>&d) {
  //variables
  int i, j, u, v, w;

  //total vertex in the graph g
  int tV = g->V;

  //total edge in the graph g
  int tE = g->E;

  //distance array
  //size equal to the number of vertices of the graph g
  //vector<int>d(tV, INFINITY);

  //predecessor array
  //size equal to the number of vertices of the graph g
  vector<int>p(tV, 0);

  //step 1: fill the distance array and predecessor array

  //mark the source vertex
  d[source] = 0;

  //step 2: relax edges |V| - 1 times
  for (i = 1; i <= tV - 1; i++) {
    for (j = 0; j < tE; j++) {
      //get the edge data
      u = g->edge[j].u;
      v = g->edge[j].v;
      w = g->edge[j].w;

      if (d[u] != INFINITY && d[v] > d[u] + w) {
        d[v] = d[u] + w;
        p[v] = u;
      }
    }
  }

  //step 3: detect negative cycle
  //if value changes then we have a negative cycle in the graph
  //and we cannot find the shortest distances
  for (i = 0; i < tE; i++) {
    u = g->edge[i].u;
    v = g->edge[i].v;
    w = g->edge[i].w;
    if (d[u] != INFINITY && d[v] > d[u] + w) {
      return 1;
    }
  }
  return 0;
}
int negative_cycle(Graph *g){
  vector<int>d(g->V, INFINITY);
  for (int i = 0; i < g->V; i++){
    if (d[i] == INFINITY){
      if (bellmanford(g, i, d) == 1)
        return 1;
    }
  }
  return 0;
}
int main(void) {
  //create graph
  struct Graph *g = (struct Graph*)malloc(sizeof(struct Graph));
  int n, m;
  std::cin >> n >> m;
  g->V = n; //total vertices
  g->E = m; //total edges

  //array of edges for graph
  g->edge = (struct Edge*)malloc(g->E * sizeof(struct Edge));
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    g->edge[i].u = x - 1;
    g->edge[i].v = y - 1;
    g->edge[i].w = w;
  }
  cout << negative_cycle(g);    //0 is the source vertex

  return 0;
}
