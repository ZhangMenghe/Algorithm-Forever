#include <iostream>
#include <vector>

#include <stack>
/*Check No aryclic in Direct graph
4 4
1 2
4 1
2 3
3 1
Output:
1
*/
using namespace std;
bool DFSUtil(vector<vector<int> > &adj, int u, vector<int>color){
  color[u] = 1;
  for (int i = 0; i < adj[u].size(); i++){
    int v = adj[u][i];
    if (color[v] == 1)
      return true;
    if (color[v] == 0 && DFSUtil(adj, v, color))
      return true;
  }
  color[u] = 2;
  return false;
}
int acyclic(vector<vector<int> > &adj, int n) {
  vector<int>color(n, 0);
  for (int i = 0; i < n; i++){
    if (color[i] == 0)
      if (DFSUtil(adj, i, color) == true)
        return 1;
  }
  return 0;
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
  std::cout << acyclic(adj,n);
}
