#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;
/*Input:
4 3
1 2
4 1
3 1
Output:
4 3 1 2
Explanation*/
void dfs(vector<vector<int> > &adj, vector<bool> &visited, vector<int> &order, int x) {
  //write your code here
  visited[x] = true;
  for (int i = 0; i < adj[x].size(); i++){
    int v = adj[x][i];
    if (!visited[v]){
      dfs(adj,visited,order,v);
    }
  }
  order.push_back(x);
}

vector<int> toposort(vector<vector<int> > adj, int n) {
  vector<int> order;
  stack<int> s;
  vector<bool> visited(n, false);
  for (int i = 0; i < n; i++)
    if (!visited[i])
      dfs(adj, visited, order,i);

  return order;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  vector<int> order = toposort(adj,n);
  for (int i = order.size()-1; i >=0; i--) {
    std::cout << order[i] + 1 << " ";
  }
  return 0;
}
