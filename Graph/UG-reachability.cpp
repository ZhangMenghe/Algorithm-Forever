#include <iostream>
#include <vector>
#include <stack>
/*
Check Reachability in Undirect Graph
4 4
1 2
3 2
4 3
1 4
1 4
Output:
1
*/
using namespace std;
int reach(vector<vector<int> > &adj, int n, int x, int y) {
	stack<int> s;
	vector<bool> visited(n, false);
	s.push(x);
	while (!s.empty()){
		int v = s.top();
		s.pop();
		visited[v] = true;
		for (int i = 0; i < adj[v].size(); i++){
			int c = adj[v][i];
			if (!visited[c]){
				if (c == y)
					return 1;
				s.push(c);
				visited[c] = true;
			}
		}
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
		adj[y - 1].push_back(x - 1);
	}
	int x, y;
	std::cin >> x >> y;
	std::cout << reach(adj, n, x - 1, y - 1);
}
