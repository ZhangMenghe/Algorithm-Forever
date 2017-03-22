#include <iostream>
#include <vector>
#include <queue>
#include<limits.h>
using namespace std;
int minDist(vector<int> dist, vector<bool> sptSet, int n){
	int min = INT_MAX;
	int minIndex = -1;
	for (int v = 0; v < n; v++){
		if (sptSet[v] == false && dist[v] <= min){
			min = dist[v];
			minIndex = v;
		}
	}
	return minIndex;
}
int distance(vector<vector<int> > &adj, int s, int t, int n) {
	vector<int> dist(n, INT_MAX);//output array
	vector<bool> sptSet(n, false);//vertex i included in shortes path set from s->i
	dist[s] = 0;
	for (int count = 0; count < n - 1; count++){
		int u = minDist(dist, sptSet, n);
		sptSet[u] = true;
		for (int v = 0; v < n; v++){
			int loc = -1;
			if (!sptSet[v] && adj[u][v] != 0 && dist[u] != INT_MAX && dist[u] + adj[u][v] < dist[v])
				dist[v] = dist[u] + adj[u][v];
		}
	}

	return (dist[t] == INT_MAX)? -1 : dist[t];
}

int main() {
	int n, m;
	std::cin >> n >> m;
	vector<vector<int> > adj(n, vector<int>(n,0));
	//vector<vector<int> > cost(n, vector<int>());
	for (int i = 0; i < m; i++) {
		int x, y, w;
		std::cin >> x >> y >> w;
		adj[x - 1][y - 1] = w;
	}
	int s, t;
	std::cin >> s >> t;
	s--, t--;
	std::cout << distance(adj, s, t, n);
}
