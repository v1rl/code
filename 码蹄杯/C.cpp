#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	i64 ans = 1ll * m * n;
	while(m --) {
		int l, r;
		cin >> l >> r;
		int L = lower_bound(a.begin(), a.end(), l) - a.begin();
		int R = upper_bound(a.begin(), a.end(), r) - a.begin();
		if(R == 0) {
			continue;
		}
		R --;
		ans -= R - L + 1;
	}
	cout << ans % 10007 << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	// cin >> t;
	while(t --) {
		solve();
	}
}