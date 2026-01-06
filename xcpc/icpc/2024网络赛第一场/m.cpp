#include<bits/stdc++.h>
using namespace std;
#define int long long
using i64 = long long;
using PII = pair<int, int>;
const int inf = 1e9;

/*
显然的stl模拟
*/

void solve() {
	unordered_set<string> S[26];
	vector<int> ans(26);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		string s;
		char c;
		string op;
		cin >> s >> c >> op;
		int ch = c - 'A';
		if(S[ch].count(s)) {
			continue;
		}
		if(op == "accepted") {
			S[ch].insert(s);
			ans[ch] ++;
		}
	}

	int mx = 0;
	int id = 0;
	for(int i = 0; i < 26; i ++) {
		if(ans[i] > mx) {
			mx = ans[i];
			id = i;
		}
	}

	cout << (char)('A' + id) << '\n';
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