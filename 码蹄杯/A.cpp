#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n;
	cin >> n;
	int cnt = 0;
	for(int i = 1; i <= n; i ++) {
		int x, y;
		cin >> x >> y;
		if(y >= x) {
			cnt ++;
		}
	}
	cout << cnt << ' ' << n - cnt << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	// cin >> t;
	while(t --) {
		solve();
	}
}