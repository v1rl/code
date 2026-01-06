#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
#define int long long
const int mod = 998244353;

i64 qmi(i64 a, i64 b) {
	i64 res = 1;
	while(b) {
		if(b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	sort(a.begin() + 1, a.end());

	vector<int> f(n + 1);
	f[1] = 1;
	for(int i = 2; i <= n; i ++) {
		f[i] = (1ll * f[i - 1] * 3 - 1) % mod;
	}
	int ans = 0;
	for(int i = 1; i <= n; i ++) {
		ans += 1ll * f[i] * a[i] % mod * qmi(2, n - i) % mod;
		ans %= mod;
	}

	cout << (ans % mod + mod) % mod << '\n';
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	cin >> t;
	while(t --) {
		solve();
	}
}