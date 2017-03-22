#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
/*Undirect Graph without weight(number of points between 2)
Find shortest distance between two points
Input:
4 4
1 2
4 1
2 3
3 1
2 4
Output:
2
*/
int distance(vector<vector<int> > &adj, int s, int t, int n) {
  queue<int>q;
  vector<int >level(n, INT_MAX);
  level[s] = 0;
  q.push(s);
  while (!q.empty()){
    int u = q.front();
    q.pop();
    for (vector<int>::iterator i = adj[u].begin(); i != adj[u].end(); i++){
      if (level[*i] == INT_MAX){
        q.push(*i);
        level[*i] = level[u] + 1;
      }
    }
  }

  //write your code here
  return (level[t] == INT_MAX)?-1:level[t];
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t, n);
}
