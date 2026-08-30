class Solution {
	public:
	vector<int> topoSort(int V, vector<vector<int>> & edges) {
		vector<vector<int>> adj(V);
		
		// Build adjacency list
		for (auto &edge : edges) {
			int u = edge[0];
			int v = edge[1];
			adj[u].push_back(v);
		}
		
		// Calculate indegree
		vector<int> indegree(V, 0);
		
		for (int u = 0; u < V; u++) {
			for (int v : adj[u]) {
				indegree[v]++;
			}
		}
		
		// Push all nodes with indegree 0
		queue<int> q;
		
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		
		vector<int> ans;
		
		// BFS
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			
			ans.push_back(node);
			
			for (int neighbour : adj[node]) {
				indegree[neighbour]--;
				
				if (indegree[neighbour] == 0) {
					q.push(neighbour);
				}
			}
		}
		
		return ans;
	}
};
