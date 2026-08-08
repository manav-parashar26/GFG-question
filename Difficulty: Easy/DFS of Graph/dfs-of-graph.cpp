class Solution {
    void help(int& st,vector<int>& vis,vector<vector<int>>& adj,vector<int>& ls){
        vis[st] = 1;
        ls.push_back(st);
        for(auto it :adj[st]){
            if(!vis[it])help(it,vis,adj,ls);
        }
    }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
       int n = adj.size();
       vector<int> vis(n,0);
       int st = 0;
       vector<int> ls;
       help(st,vis,adj,ls);
       return ls;
    }
};