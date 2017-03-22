#include <iostream>
#include <vector>
#include <queue>
/*Check Undirect Graph could be bipartied*/
using namespace std;
bool bipartite(vector<vector<int> > &adj,int n,int src,vector<int> &color) {
  //write your code here
  //vector<int> color(n,-1);
  queue<int>q;
  color[src] = 1;
  q.push(src);
  while (!q.empty()){
    int u = q.front();
    q.pop();
    for (vector<int>::iterator i = adj[u].begin(); i != adj[u].end(); i++){
      if (color[*i] == -1){
        color[*i] = 1 - color[u];
        q.push(*i);
      }
      else if (color[*i] == color[u])
        return false;
    }
  }
  return true;
}
int checkBiparties(vector<vector<int> > &adj, int n){
  vector<int> color(n, -1);
  for (int i = 0; i < n; i++){
    if (color[i] == -1)
      if (bipartite(adj, n, i, color) == false)
        return 0;
  }
  return 1;
}
int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << checkBiparties(adj, n);
}
