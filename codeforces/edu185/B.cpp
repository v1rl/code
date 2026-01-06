#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9, mod = 998244353;

/*

*/

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	int sum = 0, bg = 0;
	for(int i = 0; i < n; i ++) {
		cin >> a[i];
		if(a[i]) {
			sum ++;
		}
		bg += max(a[i] - 1, 0);
	}
	cout << sum - max(n - 1 - bg, 0) << '\n';
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