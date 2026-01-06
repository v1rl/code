#include<bits/stdc++.h>
using namespace std;
#define int long long
using i64 = long long;
using PII = pair<int, int>;

// 8 8 6 10

/*
12 4
8 8

3 13
*/

// 4 4 5 3
// 2 6
// 4 4 

void solve() {
	i64 k, x;
	cin >> k >> x;
	i64 base = 1ll << k;
	i64 a = x, b = base * 2 - x;

	vector<int> ans;
	vector<int> ops;
	int mn = 1e9;
	auto dfs = [&](auto && self, int u, i64 a, i64 b) {
		// cerr << a << ' ' << b << '\n';
		if(a == 0 || b == 0) {
			return;
		}
		if(a == base) {
			if(u < mn) {
				mn = u;
				ans = ops;
			}
			return;
		}
		if(a > b) {
			ops.emplace_back(2);
			self(self, u + 1, a - b, b * 2);
			ops.pop_back();
		}
		if(b > a) {
			ops.emplace_back(1);
			self(self, u + 1, a * 2, b - a);
			ops.pop_back();
		}
	};

	dfs(dfs, 0, a, b);

	cout << mn << '\n';
	reverse(ans.begin(), ans.end());
	for(auto c : ans) {
		cout << c << ' ';
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	cin >> t;
	while(t --) {
		solve();
	}
	return 0;
}