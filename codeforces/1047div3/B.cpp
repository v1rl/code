#include<bits/stdc++.h>
using namespace std;
#define int long long
using i64 = long long;
const int N = 2e5+10, inf = 1e18;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	int cnt = 1;
	for(int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	for(int i = 0; i < n; i ++) {
		cout << n - a[i] + 1 << ' ';
	}
	cout << '\n';
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