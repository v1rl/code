#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 1e9 + 7, inv2 = 5e8 + 4;

/*
容易想当然的认为获得钱的数量和第几个抢无关
不过仔细分析：
第一个人期望拿走w/2的钱
那么第二个人期望建立在第一个人的期望之上，即拿走(w - w/2) / 2的钱
以此类推...
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
	i64 w, n, k;
	cin >> w >> n >> k;
	cout << (w * qmi(inv2, k) % mod + mod) % mod << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t;
	t = 1;
	while(t --) {
		solve();
	}
}