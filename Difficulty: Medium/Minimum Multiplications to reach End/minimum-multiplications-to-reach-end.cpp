class Solution {
	public:
	int minSteps(vector<int>& arr, int start, int end) {
		if (start == end)
			return 0;
		queue<pair<int, int>> q;
		q.push({start, 0});
		vector<int>dist(1000, 1e9);
		dist[start] = 0;
		int mod = 1000;
		while (!q.empty()) {
			auto [node, steps] = q.front(); q.pop();
			for (auto i : arr) {
				int num = (i*node)%mod;
				if (steps + 1 < dist[num]) {
					dist[num] = steps + 1;
					if (num == end)return steps + 1;
					q.push({num, steps + 1});
				}
			}
		}
		return - 1;
	}
};
