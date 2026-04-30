#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9, mod = 998244353;

void solve() {
	int n;
	cin >> n;
	vector g(n + 1, vector(n + 1, 0));
	for(int i = 1; i <= n; i ++) {
		for(int j = i; j <= n; j ++) {
			int x;
			cin >> x;
			g[i][j] = g[j][i] = x;
		}
	}

	vector p(n + 1, vector(n + 1, 0));
	for(int i = 2; i <= n; i ++) {
		p[1][i] = true;
	}

	for(int x = 2; x <= n; x ++) {
		for(int y = x + 1; y <= n; y ++) {
			int mid = g[1][x] ^ g[1][y] ^ g[x][y];
			if(mid == x) {
				p[x][y] = true;
			} else if(mid == y) {
				p[y][x] = true;
			}
		}
	}

	vector<int> dep(n + 1);
	dep[1] = 0;
	for(int j = 2; j <= n; j ++) {
		for(int i = 1; i <= n; i ++) {
			dep[j] += p[i][j];
		}
	}

	vector<vector<int>> adj(n + 1);
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) {
			if(p[i][j] && dep[j] - dep[i] == 1) {
				adj[i].emplace_back(j);
			}
		}
	}

	for(int i = 1; i <= n; i ++) {
		for(auto y : adj[i]) {
			cout << i << ' ' << y << '\n';
		}
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	// cin >> t;
	while(t --) {
		solve();
	}
}