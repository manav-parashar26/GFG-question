class Solution {
	public:
	int timer = 1;
	
	void dfs(int node, int parent, vector<int> adj[],
	vector<int>& vis, int tin[], int low[],
	vector<int>& mark) {
		
		vis[node] = 1;
		tin[node] = low[node] = timer++;
		
		int children = 0;
		
		for (auto it : adj[node]) {
			
			// Ignore parent
			if (it == parent)
				continue;
			
			// Unvisited child
			if (!vis[it]) {
				
				dfs(it, node, adj, vis, tin, low, mark);
				
				low[node] = min(low[node], low[it]);
				
				// Articulation condition for non-root
				if (low[it] >= tin[node] && parent != -1) {
					mark[node] = 1;
				}
				
				children++;
			}
			
			// Back edge
			else {
				low[node] = min(low[node], tin[it]);
			}
		}
		
		// Special condition for root
		if (parent == -1 && children > 1) {
			mark[node] = 1;
		}
	}
	
	vector<int> articulationPoints(int V, vector<vector<int>> & edges) {
		
		vector<int> adj[V];
		
		for (auto edge : edges) {
			adj[edge[0]].push_back(edge[1]);
			adj[edge[1]].push_back(edge[0]);
		}
		
		vector<int> vis(V, 0);
		vector<int> mark(V, 0);
		
		int tin[V];
		int low[V];
		
		for (int i = 0; i < V; i++) {
			if (!vis[i]) {
				dfs(i, -1, adj, vis, tin, low, mark);
			}
		}
		
		vector<int> ans;
		
		for (int i = 0; i < V; i++) {
			if (mark[i])
				ans.push_back(i);
		}
		
		if (ans.empty())
			return {-1};
		
		return ans;
	}
};
