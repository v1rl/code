#include<bits/stdc++.h>
using namespace std;
#define int long long
using i64 = long long;
const int N = 2e5+10, inf = 1e18;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> st(n + 1);
	for(int i = 0; i < n; i ++) {
		cin >> a[i];
		st[a[i]] ++;
	}
	for(int i = 1; i <= n; i ++) {
		if(st[i] % i != 0) {
			cout << -1 << '\n';
			return;
		}
	}

	int cnt = 1;
	vector<array<int, 2>> num(n + 1, {0, 0});
	for(int i = 0; i < n; i ++) {
		if(num[a[i]][1] == 0) {
			num[a[i]][0] = cnt ++;
			num[a[i]][1] = a[i];
		}
		num[a[i]][1] --;
		cout << num[a[i]][0] << ' ';
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