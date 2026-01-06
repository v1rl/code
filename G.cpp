#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e18;
using PII = pair<int, int>;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<PII>> adj(n * (n + 100) + 1);
	vector<array<int, 3>> edge;
	edge.reserve(n);
	for(int i = 1; i <= n - 1; i ++) {
		int x, y, w;
		cin >> x >> y >> w;
		edge.push_back({x, y, w});
		for(int j = 0; j <= 0; j ++) {
			adj[x + j * n].push_back({y + j * n, w});
			adj[y + j * n].push_back({x + j * n, w});
		}
	}

	vector<array<int, 2>> edge0;
	edge.reserve(m);
	for(int i = 1; i <= m; i ++) {
		int x, y;
		cin >> x >> y;
		edge0.push_back({x, y});
	}

	vector<int> ans(n + 1);
	for(int i = 0; i <= n; i ++) {

		vector<int> dist(n + i * n + 1, inf);
		dist[1] = 0;
		priority_queue<PII, vector<PII>, greater<PII>> heap;
		heap.push({dist[1], 1});
		vector<int> st(n + i * n + 1);

		while(heap.size()) {
			auto [d, x] = heap.top();
			heap.pop();
			if(st[x]) continue;
			st[x] = true;
			for(auto [y, w] : adj[x]) {
				if(dist[y] > dist[x] + w) {
					dist[y] = dist[x] + w;
					heap.push({dist[y], y});
				}
			}
		}

		for(int j = 1; j <= n; j ++) {
			ans[i] += dist[j + i * n];
		}

		for(auto [x, y, w] : edge) {
			// cout << x << ' ' << y << ' ' << w << '\n';
			adj[x + (i + 1) * n].push_back({y + (i + 1) * n, w});
			adj[y + (i + 1) * n].push_back({x + (i + 1) * n, w});
		}

		for(auto [x, y] : edge0) {
			adj[x + i * n].push_back({y + (i + 1) * n, 0});
			adj[y + i * n].push_back({x + (i + 1) * n, 0});
		}

		// for(int j = 1; j <= n; j ++) {
		// 	heap.push({dist[j], j});
		// }
	}

	for(int i = 0; i <= n; i ++) {
		cout << ans[i] << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	// cin >> t;
	while(t --) {
		solve();
	}
}