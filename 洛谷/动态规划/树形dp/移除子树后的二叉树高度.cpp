#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

// https://leetcode.cn/problems/height-of-binary-tree-after-subtree-removal-queries/description/

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

	/*
	vector<int> dep(n + 1);
	vector<int> mx1(n + 1, -1), mx2(n + 1, -1);
	vector<int> h(n + 1);
	h[0] = -1;

	auto dfs = [&](auto &&self, int x, int d) {
		if(x == 0) {
			return;
		}
		int l = adj[x][0], r = adj[x][1];
		int pt = w[x];
		dep[pt] = d;

		self(self, l, d + 1), self(self, r, d + 1);

		l = w[l], r = w[r];
		h[pt] = max(h[l], h[r]) + 1;

		if(h[pt] > mx1[d]) {
			mx2[d] = mx1[d];
			mx1[d] = h[pt];
		} else if(h[pt] > mx2[d]) {
			mx2[d] = h[pt];
		}
	};

	dfs(dfs, 1, 0);

	int m;
	cin >> m;
	while(m --) {
		int x;
		cin >> x;
		int d = dep[x];
		if(h[x] == mx1[d]) {
			cout << d + mx2[d] << '\n';
		} else {
			cout << d + mx1[d] << '\n';
		}
	}
	*/

	vector<int> pre(n + 1), suf(n + 2);
	vector<int> in(n + 1), out(n + 1);
	vector<int> dep(n + 1);
	pre[0] = 0, suf[n + 1] = 0;
	cnt = 0;
	auto dfs = [&](auto &&self, int x, int d) {
		if(x == 0) {
			return;
		}
		int p = w[x];

		in[p] = ++ cnt;
		dep[cnt] = d;
		int l = adj[x][0], r = adj[x][1];
		self(self, l, d + 1);
		self(self, r, d + 1);

		out[p] = cnt;
	};


	dfs(dfs, 1, 0);

	for(int i = 1; i <= n; i ++) {
		pre[i] = max(pre[i - 1], dep[i]);
	}
	for(int i = n; i >= 1; i --) {
		suf[i] = max(suf[i + 1], dep[i]);
	}

	int m;
	cin >> m;
	while(m --) {
		int x;
		cin >> x;
		cout << max(pre[in[x] - 1], suf[out[x] + 1]) << '\n';
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
    return 0;
}