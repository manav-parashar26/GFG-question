class Solution {
	public:
	vector<int> parent, size;
	
	int find(int x) {
		if (parent[x] == x)
			return x;
		
		return parent[x] = find(parent[x]);
	}
	
	bool unite(int u, int v) {
		int pu = find(u);
		int pv = find(v);
		
		if (pu == pv)
			return false;
		
		if (size[pu] < size[pv]) {
			parent[pu] = pv;
			size[pv] += size[pu];
		}
		else {
			parent[pv] = pu;
			size[pu] += size[pv];
		}
		
		return true;
	}
	
	vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
		
		parent.resize(n * m);
		size.resize(n * m, 1);
		
		for (int i = 0; i < n * m; i++)
			parent[i] = i;
		
		vector<vector<int>> grid(n, vector<int>(m, 0));
		
		vector<int> ans;
		
		int islands = 0;
		
		int dr[] = {-1, 1, 0, 0};
		int dc[] = {0, 0, -1, 1};
		
		for (auto op : operators) {
			
			int r = op[0];
			int c = op[1];
			
			// Already land
			if (grid[r][c] == 1) {
				ans.push_back(islands);
				continue;
			}
			
			// Convert water -> land
			grid[r][c] = 1;
			islands++;
			
			int node = r * m + c;
			
			// Check 4 neighbours
			for (int k = 0; k < 4; k++) {
				
				int nr = r + dr[k];
				int nc = c + dc[k];
				
				// Outside grid
				if (nr < 0 || nr >= n || nc < 0 || nc >= m)
					continue;
				
				// Neighbour must be land
				if (grid[nr][nc] == 0)
					continue;
				
				int neighbour = nr * m + nc;
				
				// Different islands -> merge
				if (unite(node, neighbour))
					islands--;
			}
			
			ans.push_back(islands);
		}
		
		return ans;
	}
};
