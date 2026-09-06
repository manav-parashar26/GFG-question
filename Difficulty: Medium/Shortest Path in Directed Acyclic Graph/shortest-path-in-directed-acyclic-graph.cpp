class Solution {

    void topo(int node, vector<vector<pair<int,int>>> &adj,
              vector<int> &vis, stack<int> &st) {

        vis[node] = 1;

        for(auto it : adj[node]) {
            int v = it.first;

            if(!vis[v]) {
                topo(v, adj, vis, st);
            }
        }

        st.push(node);
    }

public:
    vector<int> shortestPath(int V, vector<vector<int>>& edges) {

        // 1. Create adjacency list
        vector<vector<pair<int,int>>> adj(V);

        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
        }

        // 2. Topological sort
        vector<int> vis(V, 0);
        stack<int> st;

        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                topo(i, adj, vis, st);
            }
        }

        // 3. Distance array
        vector<int> dist(V, 1e9);
        dist[0] = 0;

        // 4. Relax edges in topological order
        while(!st.empty()) {

            int node = st.top();
            st.pop();

            // Don't process unreachable nodes
            if(dist[node] == 1e9)
                continue;

            for(auto it : adj[node]) {
                int v = it.first;
                int wt = it.second;

                if(dist[node] + wt < dist[v]) {
                    dist[v] = dist[node] + wt;
                }
            }
        }

        // 5. Convert unreachable nodes to -1
        for(int i = 0; i < V; i++) {
            if(dist[i] == 1e9) {
                dist[i] = -1;
            }
        }

        return dist;
    }
};
