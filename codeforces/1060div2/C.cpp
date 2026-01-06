#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9, mod = 998244353;

/*
只能变大
两个偶数一定可以
判断当前是否已经存在gcd大于1

质因数分解
*/

int st[200010];

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	
	int p = 0;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		if(a[i] % 2 == 0) {
			p ++;
		}
	}
	vector<int> b(n + 1);
	for(int i = 1; i <= n; i ++) {
		cin >> b[i];
	}

	unordered_map<int, int> mp;
	unordered_map<int, int> mp2;
	for(int i = 1; i <= n; i ++) {
		int x = a[i];
		for(int j = 2; j * j <= x; j ++) {
			if(x % j == 0) {
				while(x % j == 0) {
					x /= j;
				}
				mp[j] ++;
			}
		}
		if(x > 1) {
			mp[x] ++;
		}

		x = a[i] + 1;
		for(int j = 2; j * j <= x; j ++) {
			if(x % j == 0) {
				while(x % j == 0) {
					x /= j;
				}
				mp2[j] ++;
			}
		}
		if(x > 1) {
			mp2[x] ++;
		}
	}

	int ans = max(0, 2 - p);
	for(auto [x, num] : mp) {
		if(num > 1) {
			cout << 0 << '\n';
			return;
		} else if(num == 1 && mp2[x] > 0) {
			ans = min(ans, 1);
		}
	}
	cout << ans << '\n';
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