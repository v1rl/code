#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

// https://leetcode.cn/problems/maximum-sum-bst-in-binary-tree

const int inf = 1e9 + 10;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++) {
		cin >> a[i];
	}

	vector<vector<int>> adj(n + 1);
	vector<int> w(n + 1);
	int j = 1;
	int cnt = 1;
	queue<int> q;
	q.push(1);
	w[1] = a[0];
	while(q.size()) {
		int x = q.front();
		q.pop();

		if(j >= n) {
			adj[x].emplace_back(0);
		} else {
			if(a[j] != -1) {
				adj[x].push_back(++ cnt);
				w[cnt] = a[j];
				q.push(cnt);
			} else {
				adj[x].emplace_back(0);
			}
			j ++;			
		}
		if(j >= n) {
			adj[x].emplace_back(0);
		} else {
			if(a[j] != -1) {
				adj[x].push_back(++ cnt);
				w[cnt] = a[j];
				q.push(cnt);
			} else {
				adj[x].emplace_back(0);
			}
			j ++;
		}
	}

	n = cnt;

	vector<int> mx(n + 1), mn(n + 1), isbst(n + 1), sum(n + 1);
	mx[0] = -inf, mn[0] = inf, isbst[0] = true, sum[0] = 0;
	int ans = 0;
	auto dfs = [&](auto &&self, int x) -> void {
		if(x == 0) {
			return;
		}

		int cw = w[x];
		for(auto y : adj[x]) {
			self(self, y);
		}
		int l = adj[x][0], r = adj[x][1];

		mx[x] = max({cw, mx[l], mx[r]});
		mn[x] = min({cw, mn[l], mn[r]});
		isbst[x] = isbst[l] && isbst[r] && cw > mx[l] && cw < mn[r];

		if(isbst[x]) {
			sum[x] = sum[l] + sum[r] + cw;
		} else {
			sum[x] = 0;
		}
		ans = max(ans, sum[x]);
	};

	dfs(dfs, 1);
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