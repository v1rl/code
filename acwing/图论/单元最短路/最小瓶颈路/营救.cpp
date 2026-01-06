#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using PII = pair<int, int>;
const int inf = 1e9;

/*
一个非常显然的做法是二分然后判断连通性
但我们此处不这么写
dijkstra也可以求单源最小瓶颈路，其中桶优化dijk又非常适合最大边权确定的单源最小瓶颈路
*/

void solve() {
	int n, m, stt, edd;
	cin >> n >> m >> stt >> edd;
	vector<vector<PII>> adj(n + 1);
	int mx = 0;
	for(int i = 1; i <= m; i ++) {
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].push_back({y, w});
		adj[y].push_back({x, w});
		mx = max(mx, w);
	}

	vector<vector<int>> bk(mx + 1);
	vector<int> dist(n + 1, inf);
	dist[stt] = 0;
	bk[0].emplace_back(stt);

	for(int i = 0; i <= mx; i ++) {
		/*
			需要注意，在for(auto x : bk[i])循环内部对bk[i]添加的内容并不会在后续的for循环中访问到
			因此，这里使用访问+弹出的方式保证后续加入的值也会被访问到
		*/

		while(!bk[i].empty()) {
			int x = bk[i].back();
			bk[i].pop_back();
			if(dist[x] < i) continue;

			for(auto [y, w] : adj[x]) {
				if(max(dist[x], w) < dist[y]) {
					dist[y] = max(dist[x], w);
					bk[dist[y]].emplace_back(y);
				}
			}
		}
	}

	cout << dist[edd] << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	// cin >> t;
	while(t --) {
		solve();
	}
	return 0;
}