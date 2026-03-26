#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 mod = 1e9 + 7;
const i64 inf = 1e18;

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	swap(a, b);
	swap(b, c);
	cout << a << ' ' << b << ' ' << c << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	i64 t = 1;
	// cin >> t;
	while(t --) {
		solve();
	}
}