#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

// https://leetcode.cn/problems/path-sum-iii/description/

const int inf = 1e9 + 10;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int i = 0; i < n; i ++) {
		cin >> a[i];
	}

	vector<vector<int>> adj(n + 1);
	vector<int> w(n + 1);
	w[1] = a[0];
	int j = 1;
	int cnt = 1;
	queue<int> q;
	q.push(1);
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

	unordered_map<i64, int> mp;
	int ans = 0;
	mp[0] = 1;
	auto dfs = [&](auto &&self, int x, i64 s) {
		if(x == 0) {
			return;
		}

		s += w[x];
		if(mp.count(s - m)) {
			ans += mp[s - m];
		}

		mp[s] ++;
		self(self, adj[x][0], s);
		self(self, adj[x][1], s);
		mp[s] --;
	};

	dfs(dfs, 1, 0);
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