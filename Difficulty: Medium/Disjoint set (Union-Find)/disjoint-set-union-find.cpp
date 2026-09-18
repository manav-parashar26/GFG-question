class Solution {
	public:
	
	int find(int x, vector<int>& parent) {
		if (parent[x] == x)
			return x;
		
		return parent[x] = find(parent[x], parent);
	}
	
	vector<int> DSU(int n, vector<vector<int>> & queries) {
		
		vector<int> parent(n + 1);
		
		// Initially, every element is its own representative
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
		}
		
		vector<int> ans;
		
		for (auto q : queries) {
			
			// Type 1: Union
			if (q[0] == 1) {
				
				int x = q[1];
				int z = q[2];
				
				int rootX = find(x, parent);
				int rootZ = find(z, parent);
				
				// Representative of z becomes representative
				parent[rootX] = rootZ;
			}
			
			// Type 2: Find
			else {
				
				int x = q[1];
				
				ans.push_back(find(x, parent));
			}
		}
		
		return ans;
	}
};
