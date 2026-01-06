#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 1e9 + 7;

/*
用概率dp的方式做递推，把概率对应的操作次数(结果)作为dp的维度，把概率作为dp的属性
f[i][j] 表示经过 i 次操作后，袋子里有 j 个黑球被转化为白球的概率
*/

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
	int a, b, k;
	cin >> a >> b >> k;

	vector f(k + 1, vector(min(b, k) + 1, 0));
	f[0][0] = 1;
	int invs = qmi(a + b, mod - 2);

	for(int i = 1; i <= k; i ++) {
		for(int j = 0; j <= min(i, b); j ++) {
			f[i][j] = (f[i][j] + 1ll * f[i - 1][j] * (a + j) % mod * invs % mod) % mod;
			if(j > 0) f[i][j] = (f[i][j] + 1ll * f[i - 1][j - 1] * (b - j + 1) % mod * invs % mod) % mod;
		}
	}

	int ans = 0;
	for(int i = 0; i <= min(b, k); i ++) {
		ans = (ans + 1ll * f[k][i] * (a + i)) % mod;
	}

	cout << (ans % mod + mod) % mod << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t;
	cin >> t;
	// t = 1;
	while(t --) {
		solve();
	}
}