#include<bits/stdc++.h>
using namespace std;
#define int long long
using i64 = long long;
const int N = 2e5 + 10;
const i64 inf = 1e10 + 10;

/*

*/

void solve() {
	int n;
	cin >> n;
	vector<array<int, 3>> a(n);
	i64 base = 0;
	for(int i = 0; i < n; i ++) {
		int l, r;
		cin >> l >> r;
		a[i] = {l + r, l, r};
		base += r - l;
	}

	sort(a.begin(), a.end());
	if(n & 1) {
		i64 res = 0;
		for(int i = 0; i < n; i ++) {
			res += a[i][2];
		}
		for(int i = 0; i < n / 2 + 1; i ++){
			res -= a[i][0];
		}
		i64 ans = 0;
		for(int i = 0; i < n / 2 + 1; i ++) {
			ans = max(ans, res + a[i][1]);
		}
		res += a[n / 2][0];
		for(int i = n / 2; i < n; i ++) {
			ans = max(ans, res - a[i][2]);
		}
		cout << ans + base << '\n';
	} else {
		i64 ans = 0;
		for(int i = 0; i < n; i ++) {
			ans += a[i][2];
		}
		for(int i = 0; i < n / 2; i ++) {
			ans -= a[i][0];
		}
		cout << ans + base << '\n';
	}
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