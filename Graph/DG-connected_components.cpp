#include <iostream>
#include <vector>
#include <stack>
/*Number of Connected Componenet in Undirect Graph
#DFS times
Input:
4 2
1 2
3 2
Output:
2*/
using namespace std;
int number_of_components(vector<vector<int> > &adj,int n) {
  stack<int> s;
  vector<bool> visited(n, false);
  int res = 0;
  for (int x = 0; x < n; x++){
    if (visited[x])
      continue;
    res++;
    s.push(x);
    while (!s.empty()){
      int v = s.top();
      s.pop();
      visited[v] = true;
      for (int i = 0; i < adj[v].size(); i++){
        int c = adj[v][i];
        if (!visited[c]){
          s.push(c);
          visited[c] = true;
        }
      }
    }
  }
  
  return res;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << number_of_components(adj,n);
}
