#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*
时间复杂度O(nm)
*/

const int inf = 1e9 + 10;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<PII>> adj(n + 1);
	for(int i = 0; i < n - 1; i ++) {
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].push_back({y, w});
		adj[y].push_back({x, w});
	}

	vector f(n + 1, vector(m + 1, 0));
	
/*
	vector<int> siz(n + 1, 1);
	auto dfs = [&](auto &&self, int x, int p) -> void {
		for(auto [y, w] : adj[x]) {
			if(y == p) {
				continue;
			}
			self(self, y, x);
			for(int j = min(m, siz[x]); j >= 1; j --) {
				for(int k = min(m - j, siz[y]); k >= 0; k --) {
					f[x][j + k] = max(f[x][j + k], f[x][j - 1] + w + f[y][k]);
				}
			}
			siz[x] += siz[y];
		}
	};
*/
	

	auto dfs = [&](auto &&self, int x, int p) -> void {
		for(auto [y, w] : adj[x]) {
			if(y == p) {
				continue;
			}

			f[y][0] = -inf;
			for(int j = 1; j <= m; j ++) {
				f[y][j] = f[x][j - 1] + w;
			}

			self(self, y, x);

			for(int j = 1; j <= m; j ++) {
				f[x][j] = max(f[x][j], f[y][j]);
			}
		}
	};


	dfs(dfs, 1, -1);
	cout << f[1][m] << '\n';
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