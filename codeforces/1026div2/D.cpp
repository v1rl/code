#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
#define int long long
const i64 inf = 1e9;

// 显然的二分答案和搜索判定
// 寻找一条合法路径
// 显然不同路径下的同一个点是会被访问多次的，且因为可能存在环，也不能不限制对点的访问
// 因此要使用dfs

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> w(n + 1);
	i64 sum = 0;
	for(int i = 1; i <= n; i ++) {
		cin >> w[i];
		sum += w[i];
	}

	vector<vector<array<int, 2>>> adj(n + 1);
	for(int i = 1; i <= m; i ++) {
		int x, y, c;
		cin >> x >> y >> c;
		adj[x].push_back({y, c});
	}

	vector<int> st(n + 1);
	auto dfs = [&](auto &&self, int x, int res, int mid) {
		if(x == n) {
			return true;
		}
		for(auto [y, c] : adj[x]) {
			if(st[y]) continue;
			if(res < c) continue;
			st[y] = true;
			if(self(self, y, min(mid, res + w[y]), mid)) {
				return true;
			}
			st[y] = false;
		}
		return false;
	};

	int l = 0, r = min<i64>(sum, inf) + 1;
	while(l < r) {
		int mid = l + r >> 1;
		st.assign(n + 1, 0);
		if(dfs(dfs, 1, min(w[1], mid), mid)) r = mid;
		else l = mid + 1;
	}

	if(l == min<int>(sum, inf) + 1) {
		cout << -1 << '\n';
	} else {
		cout << l << '\n';
	}
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;

    while(t --) {
        solve();
    }
    return 0;
}