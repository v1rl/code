#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 1e9 + 7;

/*
LDS(连续下降子序列)的个数最多为2
dp[i][j][k]，表示当前遍历到以i，以j为子序列中最大值，以k为序列中最大值右侧的次大值
在转移时，先考虑当前i是否纳入序列
然后遍历O(n2)遍历j和k做转移即可
*/

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}

	vector f(2, vector(n + 1, vector(n + 1, 0)));
	f[0][0][0] = 1;

	auto add = [&](int &x, int y) {
		x += y;
		if(x >= mod) {
			x -= mod;
		}
	};

	int cur = 0;
	for(int i = 1; i <= n; i ++) {
		cur ^= 1;
		for(int j = 0; j <= n; j ++) {
			for(int k = 0; k <= n; k ++) {
				f[cur][j][k] = f[cur ^ 1][j][k];
			}
		}
		for(int j = 0; j <= n; j ++) {
			for(int k = 0; k <= n; k ++) {
				if(f[cur ^ 1][j][k] == 0) {
					continue;
				}
				if(a[i] >= j) {
					add(f[cur][a[i]][k], f[cur ^ 1][j][k]);
				} else if(a[i] < j && a[i] >= k) {
					add(f[cur][j][a[i]], f[cur ^ 1][j][k]); 
				}
			}
		}
	}

	int ans = 0;
	for(int j = 0; j <= n; j ++) {
		for(int k = 0; k <= n; k ++) {
			add(ans, f[n & 1][j][k]);
		}
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