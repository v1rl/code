#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 998244853;

// https://www.luogu.com.cn/problem/P11998

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		a[i] %= m;
	}
	vector<int> p(n + 1);
	for(int i = 1; i <= n; i ++)
		cin >> p[i];

	vector<array<int, 2>> f(m + 1);
	f[0][0] = 1;
	for(int i = 1; i <= n; i ++)
	{
		int t = (i & 1);
		for(int j = m - 1; j >= 0; j --)
		{
			f[j][t] = 1ll * f[j][t ^ 1] * (1 - p[i]) % mod;
			f[j][t] %= mod;
			f[j][t] += 1ll * f[((j - a[i]) % m + m) % m][t ^ 1] * p[i] % mod;
			f[j][t] %= mod;
		}
	}

	cout << (f[0][n & 1] % mod + mod) % mod << '\n';
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int t;
	// cin >> t;
	t = 1;
	while(t --)
	{
		solve();
	}
	return 0;
}