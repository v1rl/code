#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9, mod = 998244353;

/*
正向寻找
*/

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	bool f = true;
	for(int i = 1; i <= n; i ++) {
		char x;
		cin >> x;
		a[i] = x - 'A';
		if(a[i] == 1) {
			f = false;
		}
	}
	while(m --) {
		int x;
		cin >> x;
		if(f) {
			cout << x << '\n';
		} else {
			int cnt = 1;
			int ans = 0;
			while(x) {
				if(a[cnt] == 0) {
					x --;
				} else {
					x /= 2;
				}
				cnt ++;
				ans ++;
				if(cnt == n + 1) {
					cnt -= n;
				}
			}
			cout << ans << '\n';
		}
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