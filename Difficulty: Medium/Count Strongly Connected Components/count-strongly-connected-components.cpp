class Solution {
public:

    void dfs1(int node, vector<vector<int>>& adj,
              vector<int>& vis, vector<int>& order) {

        vis[node] = 1;

        for (int nei : adj[node]) {
            if (!vis[nei])
                dfs1(nei, adj, vis, order);
        }

        order.push_back(node);
    }

    void dfs2(int node, vector<vector<int>>& rev,
              vector<int>& vis) {

        vis[node] = 1;

        for (int nei : rev[node]) {
            if (!vis[nei])
                dfs2(nei, rev, vis);
        }
    }

    int countSCC(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj(V);
        vector<vector<int>> rev(V);

        // Build original and reversed graph
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            rev[v].push_back(u);
        }

        // Step 1: finishing order
        vector<int> vis(V, 0);
        vector<int> order;

        for (int i = 0; i < V; i++) {
            if (!vis[i])
                dfs1(i, adj, vis, order);
        }

        // Step 2: DFS on reversed graph
        fill(vis.begin(), vis.end(), 0);

        int scc = 0;

        // Reverse finishing order
        for (int i = V - 1; i >= 0; i--) {

            int node = order[i];

            if (!vis[node]) {
                scc++;
                dfs2(node, rev, vis);
            }
        }

        return scc;
    }
};