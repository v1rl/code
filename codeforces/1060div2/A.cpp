#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9, mod = 998244353;

/*

*/


void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) {
		char x;
		cin >> x;
		a[i] = x - '0';
	}	
	vector<int> sum(n + 1);
	for(int i = 1; i <= n; i ++) {
		sum[i] = sum[i - 1] + a[i];
	}
	int res = 0;
	for(int i = 1; i <= n; i ++) {
		if(a[i] == 1) {
			if(sum[i - 1] - sum[max(0, i - k)] == 0) {
				res ++;
			}
		}
	}
	cout << res << '\n';
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