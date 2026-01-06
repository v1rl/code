#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	for(int i = 1; i <= n; i ++) {
		int x;
		cin >> x;
	}
	for(int i = 1; i <= m; i ++) {
		int x;
		cin >> x;
	}
	cout << n + m << '\n';
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