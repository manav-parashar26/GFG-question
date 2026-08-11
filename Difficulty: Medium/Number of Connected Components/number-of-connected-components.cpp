class Solution {
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj) {
        vis[node] = 1;

        for (auto nbr : adj[node]) {
            if (!vis[nbr]) {
                dfs(nbr, vis, adj);
            }
        }
    }

public:
    int countConnected(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(V, 0);
        int cnt = 0;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(i, vis, adj);
            }
        }

        return cnt;
    }
};