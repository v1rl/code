#include<bits/stdc++.h>
using namespace std;
#define int long long
using i64 = long long;
const int N = 2e5 + 10, inf = 1e18;

/*
x * pow(10, bit) + y;

(x * pow(10, bit) - x) % (x + y) == 0

(x*999...) % (x*3) == 0;
y = x * 2
*/

void solve() {
	int n;
	cin >> n;
	cout << n * 2 << '\n';

}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while(t --) {
		solve();
	}
	// cout << 4284 % (42 + 84) << "\n";
}