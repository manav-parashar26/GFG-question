class Solution {
	public:
	string findOrder(vector<string> &words) {
		
		int n = words.size();
		
		vector<vector<int>> adj(26);
		vector<int> indegree(26, 0);
		vector<bool> exists(26, false);
		
		// 1. Find all characters that actually exist
		for (string &word : words) {
			for (char c : word) {
				exists[c - 'a'] = true;
			}
		}
		
		// 2. Build graph using adjacent words
		for (int i = 0; i < n - 1; i++) {
			
			string &s1 = words[i];
			string &s2 = words[i + 1];
			
			int j = 0;
			
			while (j < s1.size() && j < s2.size() &&
			s1[j] == s2[j]) {
				j++;
			}
			
			// Prefix invalid case
			if (j == s2.size() && s1.size() > s2.size()) {
				return "";
			}
			
			// Found first different character
			if (j < s1.size() && j < s2.size()) {
				
				int u = s1[j] - 'a';
				int v = s2[j] - 'a';
				
				// Avoid duplicate edge
				bool alreadyExists = false;
				
				for (int x : adj[u]) {
					if (x == v) {
						alreadyExists = true;
						break;
					}
				}
				
				if (!alreadyExists) {
					adj[u].push_back(v);
					indegree[v]++;
				}
			}
		}
		
		// 3. Kahn's Algorithm
		queue<int> q;
		
		int totalCharacters = 0;
		
		for (int i = 0; i < 26; i++) {
			
			if (exists[i]) {
				totalCharacters++;
				
				if (indegree[i] == 0) {
					q.push(i);
				}
			}
		}
		
		string ans;
		
		while (!q.empty()) {
			
			int node = q.front();
			q.pop();
			
			ans += char(node + 'a');
			
			for (int next : adj[node]) {
				
				indegree[next]--;
				
				if (indegree[next] == 0) {
					q.push(next);
				}
			}
		}
		
		// 4. Cycle detection
		if (ans.size() != totalCharacters) {
			return "";
		}
		
		return ans;
	}
};
