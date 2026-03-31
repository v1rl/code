#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

// https://leetcode.cn/problems/minimum-fuel-cost-to-report-to-the-capital/description/

const int inf = 1e9 + 10;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < n; i ++) {
		int x, y;
		cin >> x >> y;
		adj[x].emplace_back(y);
		adj[y].emplace_back(x);
	}

	vector<int> siz(n + 1, 1);
	i64 ans = 0;
	auto dfs = [&](auto &&self, int x, int p) -> void {
		for(auto y : adj[x]) {
			if(y == p) {
				continue;
			}
			self(self, y, x);
			siz[x] += siz[y];
			ans += (siz[y] + m - 1) / m;
		}
	};
	dfs(dfs, 0, -1);

	cout << ans << '\n';
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