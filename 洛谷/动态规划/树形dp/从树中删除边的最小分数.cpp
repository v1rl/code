#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

// https://leetcode.cn/problems/minimum-score-after-removals-on-a-tree/description/

const int inf = 1e9 + 10;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++) {
		cin >> a[i];
	}

	vector<vector<int>> adj(n);
	for(int i = 0; i < n - 1; i ++) {
		int x, y;
		cin >> x >> y;
		adj[x].emplace_back(y);
		adj[y].emplace_back(x);
	}

	vector<int> in(n), out(n);
	vector<int> sub(n);
	vector<int> v(n + 1);
	int cnt = 0;
	auto dfs = [&](auto &&self, int x, int p) -> void {
		in[x] = ++ cnt;
		v[cnt] = a[x];
		sub[x] = a[x];

		for(auto y : adj[x]) {
			if(y == p) {
				continue;
			}
			self(self, y, x);
			sub[x] ^= sub[y];
		}

		out[x] = cnt;
	};

	dfs(dfs, 0, -1);

	vector<int> pre(n + 1);
	for(int i = 1; i <= n; i ++) {
		pre[i] = pre[i - 1] ^ v[i];
	}

	int ans = inf;
	for(int i = 1; i < n - 1; i ++) {
		for(int j = i + 1; j < n; j ++) {
			vector<int> v(3);
			int x = i, y = j;
			if(in[x] < in[y]) {
				swap(x, y);
			}
			if(out[y] >= out[x]) {
				v[0] = sub[x];
				v[1] = sub[y] ^ sub[x];
				v[2] = sub[0] ^ sub[y];
			} else {
				v[0] = sub[x];
				v[1] = sub[y];
				v[2] = sub[0] ^ sub[x] ^ sub[y];
			}

			ans = min(ans, *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end()));
		}
	}

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