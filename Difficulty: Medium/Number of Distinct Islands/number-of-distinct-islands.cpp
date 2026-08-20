class Solution {
	void dfs(int row, int col, vector<vector<int>> & vis, vector<pair<int, int>> & vec, vector<vector<char>> & grid, int row0, int col0) {
		vis[row][col] = 1;
		vec.push_back({row - row0, col - col0});
		int n = grid.size();
		int m = grid[0].size();
		vector<int> delrow = {-1, 0, 1, 0};
		vector<int> delcol = {0, -1, 0, 1};
		for (int i = 0 ; i < 4 ; i++) {
			int nrow = row + delrow[i];
			int ncol = col + delcol[i];
			if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 'L') {
				dfs(nrow, ncol, vis, vec, grid, row0, col0);
			}
		}
	}
	public:
	int countDistinctIslands(vector<vector<char>> & grid) {
		int n = grid.size();
		int m = grid[0].size();
		vector<vector<int>> vis (n, vector<int>(m, 0));
		set<vector<pair<int, int>> > st;
		for (int i = 0 ; i < n ; i++) {
			for (int j = 0 ; j < m ; j++) {
				if (!vis[i][j] && grid[i][j] == 'L') {
					vector<pair<int, int>> vec;
					vis[i][j] = 1;
					dfs(i, j, vis, vec, grid, i, j);
					st.insert(vec);
				}
			}
		}
		return st.size();
	}
};
