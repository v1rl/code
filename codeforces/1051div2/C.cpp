#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 998244353;

/*
每次相邻只会出现一次
我们会决定n - 1的相对大小
最终我们需要知道每个位置的rank
考虑建边跑拓扑序
*/

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> adj(n + 1);
	vector<int> din(n + 1);
	for(int i = 0; i < n - 1; i ++) {
		int u, v, x, y;
		cin >> u >> v >> x >> y;
		if(x > y) {
			adj[v].emplace_back(u);
			din[u] ++;
		} else {
			adj[u].emplace_back(v);
			din[v] ++;
		}
	}

	queue<int> q;
	for(int i = 1; i <= n; i ++) {
		if(!din[i]) {
			q.push(i);
		}
	}

	vector<int> ans(n + 1);
	int cnt = 0;
	while(q.size()) {
		int x = q.front();
		q.pop();
		ans[x] = ++cnt;
		for(auto y : adj[x]) {
			din[y] --;
			if(!din[y]) {
				q.push(y);
			}
		}
	}

	for(int i = 1; i <= n; i ++) {
		cout << ans[i] << " \n"[i == n];
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	cin >> t;
	while(t --) {
		solve();
	}
}