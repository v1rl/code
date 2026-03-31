#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

// https://www.luogu.com.cn/problem/P2014

const int inf = 1e9 + 10;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	vector<int> w(n + 1);
	for(int y = 1; y <= n; y ++) {
		int x;
		cin >> x >> w[y];
		adj[x].emplace_back(y);
	}

	m ++;
	vector f(n + 1, vector(m + 1, 0));
	vector<int> siz(n + 1, 1);
	auto dfs = [&](auto &&self, int x) -> void {
		f[x][1] = w[x];

		for(auto y : adj[x]) {
			self(self, y);
			for(int j = min(siz[x], m); j >= 1; j --) {
				for(int k = min(siz[y], m - j); k >= 1; k --) {
					f[x][j + k] = max(f[x][j + k], f[x][j] + f[y][k]);
				}
			}
			siz[x] += siz[y];
		}
	};

	/*
	auto dfs = [&](auto &&self, int x) -> void {
		for(auto y : adj[x]) {
			for(int j = 0; j <= m; j ++) {
				if(j == 0) {
					f[y][j] = -inf;
				} else {
					f[y][j] = f[x][j - 1] + w[y];
				}
			}
			self(self, y);
			for(int j = 0; j <= m; j ++) {
				f[x][j] = max(f[x][j], f[y][j]);
			}
		}
	};
	*/

	dfs(dfs, 0);
	cout << f[0][m] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}