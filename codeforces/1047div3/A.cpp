#include<bits/stdc++.h>
using namespace std;
#define int long long
using i64 = long long;
const int N = 2e5+10, inf = 1e18;

void solve() {
	i64 k, x;
	cin >> k >> x;
	while(k) {
		x *= 2;
		k --;
	}
	cout << x << '\n';
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