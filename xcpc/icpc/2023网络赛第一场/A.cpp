#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;
// https://qoj.ac/contest/1794

/*
简单模拟即可
*/

void solve() {
	int n, m;
	unordered_set<string> S1, S2;

	cin >> n >> m;
	vector<string> a, b;
	for(int i = 0; i < n; i ++) {
		string s;
		cin >> s;
		if(!S1.count(s)) {
			S1.insert(s);
			a.emplace_back(s);
		}
	}
	for(int i = 0; i < m; i ++) {
		string s;
		cin >> s;
		if(!S2.count(s)) {
			S2.insert(s);
			b.emplace_back(s);
		}
	}

	vector<string> ans;
	unordered_set<string> S;
	for(int i = 0; i < max(a.size(), b.size()); i ++) {
		if(i < a.size()) {
			if(!S.count(a[i])) {
				S.insert(a[i]);
				ans.emplace_back(a[i]);
			}
		}
		if(i < b.size()) {
			if(!S.count(b[i])) {
				S.insert(b[i]);
				ans.emplace_back(b[i]);
			}
		}
	}

	for(auto c : ans) {
		cout << c << '\n';
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
}