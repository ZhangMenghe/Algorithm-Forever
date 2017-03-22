#include <algorithm>
#include <iostream>
#include <vector>
#include <sys/resource.h>
#include <stack>

using namespace std;
void dfsutil(vector<vector<int> > adj, int u, vector<bool>&visited){
  visited[u] = true;
  for (int i = 0; i < adj[u].size(); i++){
    int v = adj[u][i];
    if (!visited[v]){
      dfsutil(adj, v, visited);
    }
  }
}
void dfs(vector<vector<int> > adj, vector<bool>&visited,int u,stack<int>&s ){
  visited[u] = true;
  for (int i = 0; i < adj[u].size(); i++){
    int v = adj[u][i];
    if (!visited[v]){
      dfs(adj, visited, v,s);
    }
  }
  s.push(u);
}
int number_of_strongly_connected_components(vector<vector<int> > adj, int n) {
  int result = 0;
  stack<int> s;
  vector<bool> visited(n, false);
  for (int i = 0; i < n; i++){
    if (!visited[i]){
      dfs(adj, visited, i, s);
    }
      
  }
  vector<vector<int> > adjM(n, vector<int>());
  for (int v = 0; v < n; v++){
    for (int i = 0; i < adj[v].size(); i++){
      int u = adj[v][i];
      adjM[u].push_back(v);
    }
  }
  visited = vector<bool>(n, false);
  while (!s.empty())
  {
    int v = s.top();
    s.pop();
    if (!visited[v]){
      dfsutil(adjM,v, visited);
      result++;
    }
  }
  return result;
}

int main() {
  rlimit R;
getrlimit(RLIMIT_STACK, &R);
R.rlim_cur = R.rlim_max;
setrlimit(RLIMIT_STACK, &R);
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << number_of_strongly_connected_components(adj, n );
}
