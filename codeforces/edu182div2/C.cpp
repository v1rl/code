#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 998244353;

/*
dp[i][op]第i个位置，交换与不交换
dp[1][0] = dp[1][1] = 1;
*/

void solve() {
	int n;
	cin >> n;
	vector<array<int, 2>> dp(n + 1);
	vector<array<int, 2>> a(n + 1);
	for(int i = 1; i <= n; i ++) {
		cin >> a[i][0];
	}
	for(int i = 1; i <= n; i ++) {
		cin >> a[i][1];
	}

	dp[1][0] = dp[1][1] = 1;
	for(int i = 2; i <= n; i ++) {
		if(a[i - 1][0] <= a[i][0] && a[i - 1][1] <= a[i][1]) {
			dp[i][0] += dp[i - 1][0];
			dp[i][1] += dp[i - 1][1];
			dp[i][1] %= mod;
			dp[i][0] %= mod;
		}
		if(a[i - 1][1] <= a[i][0] && a[i - 1][0] <= a[i][1]) {
			dp[i][0] += dp[i - 1][1];
			dp[i][1] += dp[i - 1][0];
			dp[i][0] %= mod;
			dp[i][1] %= mod;
		}
	}

	cout << (dp[n][0] + dp[n][1]) % mod << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	cin >> t;
	while(t --) {
		solve();
	}
}