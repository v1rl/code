#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 998244353;

/*
价格从大到小
数量从小到大
*/

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	vector<int> dis(k);
	for(int i = 0; i < k; i ++) {
		cin >> dis[i];
	}
	sort(dis.begin(), dis.end());
	sort(a.begin() + 1, a.end(), greater());

	i64 ans = accumulate(a.begin() + 1, a.end(), 0ll);
	int cur = 0;
	for(auto x : dis) {
		if(cur + x > n) {
			break;
		}
		ans -= a[cur + x];
		cur += x;
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	cin >> t;
	while(t --) {
		solve();
	}
}