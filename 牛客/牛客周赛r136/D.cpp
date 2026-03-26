#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const int mod = 998244353;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	int mid = a[(n - 1) / 2];

	int l = -1, r = n;
	for(int i = (n - 1) / 2 + 1; i < n; i ++) {
		if(a[i] != mid) {
			r = i;
			break;
		}
	}
	for(int i = (n - 1) / 2 - 1; i >= 0; i --) {
		if(a[i] != mid) {
			l = i;
			break;
		}
	}
	
	if(l == -1 && r == n) {
		cout << -1 << '\n';
		return;
	}
	int ans = inf;
	if(r != n) {
		ans = min(ans, 2 * r - n + 1);
	} 
	if(l != -1) {
		ans = min(ans, n - 2 * l - 2);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	i64 t = 1;
	// cin >> t;
	while(t --) {
		solve();
	}
}