#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9, mod = 998244353;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}

	sort(a.begin() + 1, a.end());
	vector<i64> pre(n + 1);
	for(int i = 1; i <= n; i ++) {
		pre[i] = pre[i - 1] + a[i];
	}

	int k = n, r = n;
	vector<i64> ans(n + 1);
	while(k > 2) {
		while(r - k < 0) {
			k --;
		}
		if(pre[r - 1] - pre[r - k] > a[r]) {
			ans[k] = pre[r] - pre[r - k];
			k --;
		} else {
			r --;
		}
	}

	for(int i = 1; i <= n; i ++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
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