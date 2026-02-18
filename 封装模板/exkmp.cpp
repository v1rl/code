#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

vector<int> zFunction(string &s) {
	int n = s.size();
	vector<int> z(n);
	for(int i = 1, l = 0, r = 0; i < n; i ++) {
		if(i <= r) {
			z[i] = min(z[i - l], r - i + 1);
		}

		while(i + z[i] < n && s[i + z[i]] == s[z[i]]) {
			z[i] ++;
		}

		if(i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] - 1;
		}
	}
	return z;
}

void solve() {
	string a, b;
	cin >> a >> b;
	string s = b + '#' + a;
	auto x = zFunction(s);
	x[0] = b.size();
	i64 ans1 = 0, ans2 = 0;
	for(int i = 0; i < b.size(); i ++) {
		ans1 ^= 1ll * (i + 1) * (x[i] + 1);
	}
	for(int i = 0; i < a.size(); i ++) {
		ans2 ^= 1ll * (i + 1) * (x[i + b.size() + 1] + 1);
	}

	cout << ans1 << '\n' << ans2 << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	// cin >> t;
	t = 1;
	while(t --) {
		solve();
	}
	return 0;
}