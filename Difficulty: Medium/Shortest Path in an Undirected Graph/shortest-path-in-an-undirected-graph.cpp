class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        vector<vector<pair<int, int>>> adj(V + 1);
        for (auto &it : edges) {
            int u = it[0], v = it[1], wt = it[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<int> dist(V + 1, INT_MAX);
        vector<vector<int>> path(V + 1);   // lexicographically smallest path found so far

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        dist[src] = 0;
        path[src] = {src};
        pq.push({0, src});

        while (!pq.empty()) {
            auto [dis, node] = pq.top();
            pq.pop();

            if (dis > dist[node]) continue;   // only skip truly stale (worse) entries

            for (auto &[adjnode, wt] : adj[node]) {
                int newDist = dis + wt;

                if (newDist < dist[adjnode]) {
                    dist[adjnode] = newDist;
                    path[adjnode] = path[node];
                    path[adjnode].push_back(adjnode);
                    pq.push({newDist, adjnode});
                }
                else if (newDist == dist[adjnode]) {
                    vector<int> candidate = path[node];
                    candidate.push_back(adjnode);
                    if (candidate < path[adjnode]) {   // vector<int> compares lexicographically
                        path[adjnode] = candidate;
                        pq.push({newDist, adjnode});   // re-propagate the improved path
                    }
                }
            }
        }

        if (dist[dest] == INT_MAX) return {-1};
        return path[dest];
    }
};