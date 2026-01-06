#include<bits/stdc++.h>
using namespace std;
#define int long long
using i64 = long long;
const int N = 2e5 + 10, inf = 1e18;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int cnt = 0;
	for(auto c : s) {
		if(c == '0') {
			cnt ++;
		}
	}
	int ans = 0;
	for(int i = 0; i < s.size(); i ++) {
		if(s[i] == '0' && i >= cnt) {
			ans ++;
		}
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while(t --) {
		solve();
	}
}