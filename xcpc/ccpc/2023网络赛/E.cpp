#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 998244353;

/*

*/

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	map<char, array<int, 2>> mp;
	mp['U'] = {0, 1};
	mp['D'] = {0, -1};
	mp['L'] = {-1, 0};
	mp['R'] = {1, 0};

	vector<array<int, 2>> ans;
	vector st(2 * n + 1, vector(2 * n + 1, -1));
	vector vis(2 * n + 1, vector(2 * n + 1, 0));

	auto dfs = [&](auto &&self, int cur, int x, int y) {
		auto [dx, dy] = mp[s[cur]];
		int nx = dx + x, ny = dy + y;
		if(st[nx][ny] != -1) {
			if(st[nx][ny]) {
				self(self, cur + 1, x, y);
			} else {
				self(self, cur + 1, nx, ny);
			}
		} else {
			
		}
	};


	dfs(dfs, 0, 0, 0);
	// cout << '\n';
	sort(ans.begin(), ans.end());
	for(auto [x, y] : ans) {
		cout << x << ' ' << y << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	// cin >> t;
	while(t --) {
		solve();
	}
}