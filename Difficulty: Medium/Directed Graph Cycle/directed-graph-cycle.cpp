class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        vector<int> indegree(V,0);
        for(int i = 0 ; i < V ; i++){
            for(auto j : adj[i]){
                indegree[j]++;
            }
        }
        queue<int> q;
        for(int i = 0 ; i < V ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        int cnt = 0;
        while(!q.empty()){
            int node = q.front();q.pop();
            cnt++;
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0)q.push(it);
            }
        }
        if(cnt == V)return false;
        return true;
    }
};