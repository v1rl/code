#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const int mod = 998244353;

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> adj(n + 1);
	vector<int> d(n + 1);
	for(int i = 1; i < n; i ++) {
		int x, y;
		cin >> x >> y;
		adj[x].emplace_back(y);
		adj[y].emplace_back(x);
		d[x] ++, d[y] ++;
	}

	if(n == 1) {
		cout << "red" << '\n';
		return;
	}

	vector<int> f(n + 1, 0);
	auto dfs = [&](auto &&self, int x, int p) {
		if(x != 1 && d[x] == 1) {
			f[x] = true;
			return;
		}

		int cnt = 0;
		for(auto y : adj[x]) {
			if(y == p) {
				continue;
			}
			self(self, y, x);
			cnt += f[y];
		}

		if((x == 1 && cnt >= 1) || cnt >= 2) {
			f[x] = true;
		}
	};

	dfs(dfs, 1, -1);

	cout << (f[1] ? "red" : "purple") << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	i64 t = 1;
	cin >> t;
	while(t --) {
		solve();
	}
}