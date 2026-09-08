class Solution {
	public:
	int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
		vector<vector<int>> adj(V);
		for (auto it : edges) {
			adj[it[0]].push_back(it[1]);
			adj[it[1]].push_back(it[0]);
		}
		vector<int> dist(V, 1e9);
		dist[src] = 0;
		queue<int> q;
		q.push(src);
		while (!q.empty()) {
			int node = q.front(); q.pop();
			if (node == dest)
				return dist[node];
			for (auto i : adj[node]) {
				if (dist[node] + 1 < dist[i]) {
					dist[i] = dist[node] + 1;
					q.push(i);
				}
			}
		}
		return - 1;
	}
};
