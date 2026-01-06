#include<bits/stdc++.h> 
using namespace std;
using i64 = long long;
const int mod = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);

	vector<int> A(n + 1);
	A[0] = A[1] = 1;
	for(int i = 2; i <= n; i ++) {
		A[i] = 1ll * A[i - 1] * i % mod;
	}


	// cerr << 'h';
	vector C(n + 1, vector(n + 1, 0));
	C[0][0] = 1;
	for(int i = 1; i <= n; i ++) {
		for(int j = 0; j <= i; j ++) {
			if(j == 0) {
				C[i][j] = 1;
				continue;
			}
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
			C[i][j] %= mod;
		}
	}
	// cout << C[7][2] << '\n';


	int sum = 0;
	vector<int> bk(101);
	for(int i = 0; i < n; i ++) {
		cin >> a[i];
	}				
	for(int i = 0; i < n; i ++) {
		cin >> b[i];
		bk[b[i]] ++;
		sum += b[i];
	}
	vector dp(sum + 1, vector(101, 0));
	vector<int> f(sum + 1);
	f[0] = true;
	for(int i = 0; i < n; i ++) {
		for(int j = sum - b[i]; j >= 0; j --) {
			if(f[j]) {
				f[j + b[i]] = true;
				dp[j + b[i]][b[i]] = true;
			}
		}
	}

	int ans = 0;
	for(int i = 0; i < n; i ++) {
		if(a[i] >= sum) {
			continue;
		}

		bk[b[i]] --;
		vector sel = bk;
		if(f[a[i]]) {
			vector<int> res(101);
			int num = 0;
			auto dfs = [&](auto &&self, int s) -> void {
				if(s == 0) {
					i64 cur = 1;
					for(int j = 1; j <= 100; j ++) {
						if(res[j]) {
							cur *= C[bk[j]][res[j]];
							cur %= mod;
						}
					}
					// cout << cur << '\n';
					cur *= 1ll * A[n - num - 1] * A[num] % mod;
					cur %= mod;

					ans += cur;
					ans %= mod;
					return;
				}
				for(int i = 1; i <= 100; i ++) {
					if(dp[s][i] && sel[i]) {
						res[i] ++;
						num ++;
						sel[i] --;
						self(self, s - i);
						res[i] --;
						num --;
						sel[i] ++;
					}
				}
			};
			dfs(dfs, a[i]);
		}
		bk[b[i]] ++;
	}

	cout << ans << '\n';
}

int main() {
	int t = 1;
	// cin >> t;
	while(t --) {
		solve();
	}
    return 0;
}