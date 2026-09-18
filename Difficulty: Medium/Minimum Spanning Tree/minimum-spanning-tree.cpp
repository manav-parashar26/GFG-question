class Solution {
	public:
	
	vector<int> parent, rank;
	
	int find(int x) {
		if (parent[x] == x)
			return x;
		
		return parent[x] = find(parent[x]);
	}
	
	void unionByRank(int u, int v) {
		
		u = find(u);
		v = find(v);
		
		if (u == v)
			return;
		
		if (rank[u] < rank[v]) {
			parent[u] = v;
		}
		else if (rank[u] > rank[v]) {
			parent[v] = u;
		}
		else {
			parent[v] = u;
			rank[u]++;
		}
	}
	
	int spanningTree(int V, vector<vector<int>> & edges) {
		
		parent.resize(V);
		rank.resize(V, 0);
		
		for (int i = 0; i < V; i++) {
			parent[i] = i;
		}
		
		sort(edges.begin(), edges.end(),
		[](vector<int>& a, vector<int>& b) {
			return a[2] < b[2];
		});
		
		int mstWeight = 0;
		int count = 0;
		
		for (auto &edge : edges) {
			
			int u = edge[0];
			int v = edge[1];
			int wt = edge[2];
			
			if (find(u) != find(v)) {
				
				mstWeight += wt;
				
				unionByRank(u, v);
				
				count++;
				
				if (count == V - 1)
					break;
			}
		}
		
		return mstWeight;
	}
};
// vector<vector<pair<int,int>>> adj(V);

// for(auto &it : edges) {
//     int u = it[0];
//     int v = it[1];
//     int wt = it[2];

//     adj[u].push_back({v, wt});
//     adj[v].push_back({u, wt});
// }

// priority_queue<
//     pair<int,int>,
//     vector<pair<int,int>>,
//     greater<pair<int,int>>
// > pq;

// vector<int> vis(V, 0);

// pq.push({0, 0});

// int sum = 0;

// while(!pq.empty()) {

//     int wt = pq.top().first;
//     int node = pq.top().second;
//     pq.pop();

//     if(vis[node])
//         continue;

//     vis[node] = 1;
//     sum += wt;

//     for(auto it : adj[node]) {
//         int adjNode = it.first;
//         int edgeWeight = it.second;

//         if(!vis[adjNode]) {
//             pq.push({edgeWeight, adjNode});
//         }
//     }
// }

// return sum;
