class Solution {
    bool detect(int node,int parent, vector<int>& vis, vector<vector<int>>& adj) {
        vis[node] = 1;
        for (auto adjnode : adj[node]) {
                if (!vis[adjnode]) {
                    if(detect(adjnode,node,vis,adj) == true)return true;
                }
                else if (parent != adjnode) return true;
            }
        
        return false;
    }
public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u); 
        }
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i] && detect(i,-1, vis, adj) == true) return true;
        }
        return false;
    }
};
