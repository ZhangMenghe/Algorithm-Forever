#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

struct Node
{
  long long  x;
  long long  y;
  long long  setNum;
};
struct Edge
{
  long long  s;
  long long  t;
  double distance;
};
bool myComp(Edge e1, Edge e2){
  return (e1.distance < e2.distance);
}
void ConstructEdges(vector<Edge>& edges, vector<Node> nodes){
  long long  n = nodes.size();
  for (long long i = 0; i < n; i++){
    for (long long j = 0; j < n; j++){
      if (i != j){
        Edge newEdge;
        newEdge.s = i;
        newEdge.t = j;
        newEdge.distance = sqrt(pow((nodes[i].x - nodes[j].x),2) + pow((nodes[i].y - nodes[j].y),2));
        edges.push_back(newEdge);
      }
    }
  }
}
long long Union(vector<Node> &nodes, long long  s, long long  t){
  long long setNum = min(nodes[s].setNum, nodes[t].setNum);
  long long setNumt = nodes[t].setNum;
  long long setNums = nodes[s].setNum;
  set<long long> counSetNum;
  for (long long i = 0; i < nodes.size(); i++){
    if (nodes[i].setNum == setNumt || nodes[i].setNum == setNums)
      nodes[i].setNum = setNum;
    counSetNum.insert(nodes[i].setNum);
  } 
  
  return counSetNum.size();
}
double clustering(vector<Node> nodes, long long  k) {
  double result = 0.;
  long long  regionNum = nodes.size();
  vector<Edge>edges;
  ConstructEdges(edges, nodes);
  sort(edges.begin(), edges.end(), myComp);
  long long  edgeNum = edges.size();
  for (int i = 0; i < edgeNum; i++){
    long long  s = edges[i].s;
    long long  t = edges[i].t;
    if (nodes[s].setNum != nodes[t].setNum){
      //result += edges[i].distance;
      if (regionNum == k)
        return edges[i].distance;
      regionNum = Union(nodes, s, t);
    }
  }
  //write your code here
  return -1;
}

int main() {
  size_t n;
  long long  k;
  std::cin >> n;
  vector<Node> nodes;
  for (size_t i = 0; i < n; i++) {
    Node newNode;
    std::cin >> newNode.x >> newNode.y;
    newNode.setNum = i;
    nodes.push_back(newNode);
  }
  std::cin >> k;
  std::cout << std::setprecision(10) << clustering(nodes,k) << std::endl;
}
