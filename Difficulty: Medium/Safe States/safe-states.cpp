class Solution {
  public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        vector<vector<int>> revadj(V);
        vector<int>indeg(V,0);
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            revadj[v].push_back(u);
            indeg[u]++;
        }
        queue<int> q;
        for(int i = 0 ; i < V ; i++){
            if(indeg[i] == 0)q.push(i);
        }
        vector<int> safenode;
        while(!q.empty()){
            int node = q.front();q.pop();
            safenode.push_back(node);
            for(auto next : revadj[node]){
                if(--indeg[next] == 0)q.push(next);
            }
        }
        sort(safenode.begin(),safenode.end());
        return safenode;
        
    }
};