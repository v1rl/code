#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9 + 7;

void solve() {
	int n, m, p;
	cin >> n >> m >> p;
	vector<vector<int>> adj(n + 1);
	for(int i = 1; i <= m; i ++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].emplace_back(y);
		adj[y].emplace_back(x);
	}

	int s;
	cin >> s;
	queue<array<int, 2>> q;
	vector<array<int, 2>> dmn(n + 1, {inf, inf});
	for(int i = 1; i <= s; i ++) {
		int x;
		cin >> x;
		q.push({x, 0});
		dmn[x][0] = 0;
	}

	while(q.size()) {
		auto [x, c] = q.front();
		q.pop();
		if(dmn[x][c] == p) continue;

		for(auto y : adj[x]) {
			if(dmn[y][c ^ 1] == inf) {
				dmn[y][c ^ 1] = dmn[x][c] + 1;
				q.push({y, c ^ 1});
			}
		}
	}

	vector<array<int, 2>> pre(n + 1, {-1, -1});
	vector<array<int, 2>> dist(n + 1, {inf, inf});
	q.push({1, 0});
	dist[1][0] = 0;
	while(q.size()) {
		auto [x, c] = q.front();
		q.pop();

		for(auto y : adj[x]) {
			if(dist[y][c ^ 1] == inf && dist[x][c] + 1 < dmn[y][c ^ 1]) {
				dist[y][c ^ 1] = dist[x][c] + 1;
				pre[y][c ^ 1] = x;
				q.push({y, c ^ 1});
			}
		}
	}

	if(pre[n][0] == -1 && pre[n][1] == -1) {
		cout << -1 << '\n';
	}
	else {
		int t = 0;
		if(dist[n][1] < dist[n][0]) t = 1;

		int x = n;
		vector<int> res;
		while(x != -1) {
			res.emplace_back(x);
			x = pre[x][t];
			t ^= 1;
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
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    // t = 1;
    while(t --) {
        solve();
    }
    return 0;
}