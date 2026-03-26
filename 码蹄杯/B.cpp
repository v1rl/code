#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> pre(n + 1, 1e9 + 10);
	for(int i = 1; i <= n; i ++) {
		cin >> pre[i];
		pre[i] = min(pre[i], pre[i - 1]);
	}
	for(int i = 1; i <= n; i ++) {
		cout << pre[i] << ' ';
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	// cin >> t;
	while(t --) {
		solve();
	}
}