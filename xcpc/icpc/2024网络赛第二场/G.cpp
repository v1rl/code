#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 998244353;

/*
首先，平局不影响局面，不必考虑，我们得到删去平局后两边获胜的概率
其次，我们考虑欧几里得算法建模，把(x, y)的变化从减法变成取余

*/

int qmi(i64 a, i64 b) {
	i64 res = 1;
	while(b) {
		if(b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

int dfs(int x, int y, int a, int b) {
	if(!x) return 0;
	if(!y) return 1;

	if(x >= y) {
		int k = x / y;
		int res = 1ll * a * (1 - qmi(b, k)) % mod * qmi(1 - b, mod - 2) % mod;
		return (res + 1ll * qmi(b, k) * dfs(x % y, y, a, b)) % mod;
	} else {
		return 1ll * qmi(a, y / x) * dfs(x, y % x, a, b) % mod;
	}
}

void solve() {
	int x, y, a, b, c;
	cin >> x >> y >> a >> b >> c;
	int t = qmi(a + b, mod - 2);
	a = 1ll * t * a % mod;
	b = 1ll * t * b % mod;
	cout << (dfs(x, y, a, b) % mod + mod) % mod << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}