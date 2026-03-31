#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

// https://www.nowcoder.com/practice/380d49d7f99242709ab4b91c36bf2acc

/*
*/

const int inf = 1e9 + 10;

void solve() {
	int n, R;
	cin >> n >> R;
	vector<vector<int>> adj(n + 1);

	vector<int> mx(n + 1), mn(n + 1), isbst(n + 1), siz(n + 1);
	mx[0] = -inf, mn[0] = inf, isbst[0] = true, siz[0] = 0;

	for(int i = 0; i < n; i ++) {
		int x, l, r;
		cin >> x >> l >> r;
		adj[x].emplace_back(l);
		adj[x].emplace_back(r);
	}

	auto dfs = [&](auto &&self, int x) -> void {
		if(x == 0) {
			return;
		}
		for(auto y : adj[x]) {
			self(self, y);
		}
		int l = adj[x][0], r = adj[x][1];
		mx[x] = max({x, mx[l], mx[r]});
		mn[x] = min({x, mn[l], mn[r]});
		isbst[x] = isbst[l] && isbst[r] && x > mx[l] && x < mn[r];
		if(isbst[x]) {
			siz[x] = siz[l] + siz[r] + 1;
		} else {
			siz[x] = max(siz[l], siz[r]);
		}
	};


	dfs(dfs, R);
	cout << siz[R];
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