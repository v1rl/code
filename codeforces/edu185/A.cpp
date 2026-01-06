#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9, mod = 998244353;

/*

*/

void solve() {
	int n;
	cin >> n;
	if(n == 2) {
		cout << 9 << '\n';
	} else if(n == 1) {
		cout << 1 << '\n';
	} else {
		int base = n * n;
		cout << max({base * 4 - 3 - n - 1, base * 5 - 1 - n * 3 - 3 - n * 2 - 1}) << '\n';
	}
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