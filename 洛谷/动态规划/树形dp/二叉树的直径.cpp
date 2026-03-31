#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

// https://leetcode.cn/problems/diameter-of-binary-tree/description/

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

	vector<int> mx(n + 1);
	mx[0] = 0;
	int ans = 0;
	auto dfs = [&](auto &&self, int x) {
		if(x == 0) {
			return;
		}

		self(self, adj[x][0]);
		self(self, adj[x][1]);

		int l = adj[x][0], r = adj[x][1];
		mx[x] = max(mx[l], mx[r]) + 1;
		ans = max(ans, mx[l] + mx[r]);
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