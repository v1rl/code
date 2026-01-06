#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9, mod = 998244353;

/*
让奇数-1变小,让偶数取max变大
让偶数变成前缀max
然后让奇数-1直到符合条件
*/


void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	int mx = 0;
	for(int i = 1; i <= n; i ++) {
		mx = max(mx, a[i]);
		if(i % 2 == 0) {
			a[i] = mx;
		}
	}

	i64 ans = 0;
	for(int i = 1; i <= n; i += 2) {
		if(i == 1) {
			ans += max(a[i] - a[i + 1] + 1, 0);
		} else if(i == n && (n & 1)) {
			ans += max(a[i] - a[i - 1] + 1, 0);
		} else {
			ans += max({a[i] - a[i + 1] + 1, 0, a[i] - a[i - 1] + 1});
		}
	}
	cout << ans << '\n';

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while(t --) {
		solve();
	}
}