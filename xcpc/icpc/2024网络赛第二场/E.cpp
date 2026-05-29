#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9 + 7;

void solve() {
	int n, m, p;
	cin >> n >> m >> p;
	vector<vector<int>> adj(n + 1);
	for(int i = 1; i <= m; i ++) {
		int x, y;
		cin >> x >> y;
		adj[x].emplace_back(y);
		adj[y].emplace_back(x);
	}

	int s;
	cin >> s;
	queue<array<int, 2>> q;
	vector dmn(2, vector(n + 1, inf));
	for(int i = 1; i <= s; i ++) {
		int x;
		cin >> x;
		q.push({x, 0});
		dmn[0][x] = 0;
	}

	while(q.size()) {
		auto [x, c] = q.front();
		q.pop();
		if(dmn[c][x] == p) {
			continue;
		}

		for(auto y : adj[x]) {
			if(dmn[c ^ 1][y] == inf) {
				dmn[c ^ 1][y] = dmn[c][x] + 1;
				q.push({y, c ^ 1});
			}
		}
	}

	vector pre(2, vector(n + 1, -1));
	vector dist(2, vector(n + 1, inf));
	q.push({1, 0});
	dist[0][1] = 0;
	while(q.size()) {
		auto [x, c] = q.front();
		q.pop();

		for(auto y : adj[x]) {
			if(dist[c ^ 1][y] == inf && dist[c][x] + 1 < dmn[c ^ 1][y]) {
				dist[c ^ 1][y] = dist[c][x] + 1;
				pre[c ^ 1][y] = x;
				q.push({y, c ^ 1});
			}
		}
	}

	if(pre[0][n] == -1 && pre[1][n] == -1) {
		cout << -1 << '\n';
	} else {
		int c = 0;
		if(dist[1][n] < dist[0][n]) {
			c = 1;
		}

		int x = n;
		vector<int> res;
		while(x != -1) {
			res.emplace_back(x);
			x = pre[c][x];
			c ^= 1;
		}
		reverse(res.begin(), res.end());
		cout << res.size() - 1 << '\n';
		for(auto x : res) {
			cout << x << ' ';
		}
		cout << '\n';
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}