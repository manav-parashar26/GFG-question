class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {

        vector<vector<pair<int, int>>> adj(V);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        set<pair<int, int>> st;

        vector<int> dist(V, 1e9);

        dist[src] = 0;
        st.insert({0, src});

        while (!st.empty()) {

            auto [dis, node] = *(st.begin());
            st.erase(st.begin());

            if (dis > dist[node])
                continue;

            for (auto it : adj[node]) {

                int adjnode = it.first;
                int edwt = it.second;

                if (dis + edwt < dist[adjnode]) {

                    dist[adjnode] = dis + edwt;

                    st.insert({dist[adjnode], adjnode});
                }
            }
        }

        return dist;
    }
};
