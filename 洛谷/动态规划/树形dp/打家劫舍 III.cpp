#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

// https://leetcode.cn/problems/house-robber-iii/description/

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

	vector f(n + 1, vector(2, 0));
	f[0][0] = f[0][1] = 0;
	auto dfs = [&](auto &&self, int x) {
		if(x == 0) {
			return;
		}
		int l = adj[x][0], r = adj[x][1];
		self(self, l), self(self, r);

		f[x][0] = max(f[l][1], f[l][0]) + max(f[r][0], f[r][1]);
		f[x][1] = f[l][0] + f[r][0] + w[x];
	};

	dfs(dfs, 1);
	cout << max(f[1][0], f[1][1]) << '\n';
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