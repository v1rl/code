#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

// https://leetcode.cn/problems/longest-path-with-different-adjacent-characters/description/

const int inf = 1e9 + 10;

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> adj(n);
	int R = 0;
	for(int y = 0; y < n; y ++) {
		int x;
		cin >> x;
		if(x == -1) {
			R = y;
		} else {
			adj[x].emplace_back(y);
		}
	}
	string s;
	cin >> s;

	vector<int> len(n, 1);
	int ans = 0;
	auto dfs = [&](auto &&self, int x) -> void {
		int mx[2] {};
		for(auto y : adj[x]) {
			self(self, y);
			if(s[y] != s[x]) {
				len[x] = max(len[x], len[y] + 1);
				if(len[y] > mx[0]) {
					mx[1] = mx[0];
					mx[0] = len[y];
				} else if(len[y] >= mx[1]) {
					mx[1] = len[y];
				}
			}
		}
		ans = max({ans, len[x], mx[0] + mx[1] + 1});
	};

	dfs(dfs, R);
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