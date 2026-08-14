class Solution {
    bool detect(int src, vector<int>& vis, vector<vector<int>>& adj) {
        vis[src] = 1;
        queue<pair<int,int>> q;
        q.push({src, -1});
        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for (auto adjnode : adj[node]) {
                if (!vis[adjnode]) {
                    vis[adjnode] = 1;
                    q.push({adjnode, node});
                }
                else if (parent != adjnode) return true;
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Build adjacency list from edge pairs
        vector<vector<int>> adj(V);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);  // undirected: add both directions
        }

        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i] && detect(i, vis, adj)) return true;
        }
        return false;
    }
};
