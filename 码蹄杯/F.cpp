#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int mod = 1e9 + 7;
const int N = 5010;
int C[N][N];

void solve() {
	int n;
	cin >> n;

	for(int i = 0; i <= n; i ++) {
		C[i][0] = 1;
		for(int j = 1; j <= i; j ++) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
		}
	}

	string s;
	cin >> s;

	vector<int> pre(n + 1);
	for(int i = 1; i <= n; i ++) {
		pre[i] = pre[i - 1] + (s[i - 1] == '1');
	}
	int m = pre[n];

	i64 ans = 0;
	for(int i = 0; i < n; i ++) {
		if(s[i] != '1') {
			continue;
		}
		for(int j = 1; j < n; j ++) {
			i64 len = 0;
			if(i - j >= 0 && i + j < n) {
				// len = n - 2 * j;
				// cout << len << '\n';
				// ans += 1ll * C[len][m - 1] * j * 2 - 1ll * C[len - 1][m - 2] * j;
				// ans %= mod;
			} else if(i - j >= 0) {
				// int len = n - (i - j) - 1;
				// int n1 = m - pre[i - j + 1] - 1;
				// cout << len << ' ' << n1 << '\n';
				ans += 1ll * C[n - (i - j) - 1][m - pre[i - j + 1] - 1] * C[i - j][pre[i - j + 1]] * j;
				ans %= mod;
			} else if(i + j < n) {
				int len = i + j;
				int n1 = pre[i + j] - 1;

				cout << len << ' ' << n1 << ' ' << ' ' << n - len - 1 << ' ' << m - n1 - 1 << '\n';
				ans += 1ll * C[i + j][pre[i + j] - 1] * C[n - i - j - 1][m - pre[i + j]] * j;
				ans %= mod;
			} else {
				break;
			}
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	// cin >> t;
	while(t --) {
		solve();
	}
}