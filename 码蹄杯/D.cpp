#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	i64 sum = 0;
	set<int> S;
	for(int i = 0; i < n; i ++) {
		cin >> a[i];
		sum += a[i];
		if(a[i] != 0) {
			S.insert(i);
		}
	}

	while(q --) {
		int x;
		cin >> x;
		if(x == 1) {
			cout << sum << '\n';
			continue;
		}
		vector<int> cur;
		for(auto c : S) {
			int t = a[c] / x;
			sum -= a[c] - t;
			a[c] = t;
			if(t == 0) {
				cur.emplace_back(c);
			}
		}

		for(auto c : cur) {
			S.erase(c);
		}

		cout << sum << '\n';
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