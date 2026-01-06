#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;
const int mod = 998244353;

void solve()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector g(n + 1, vector(m + 1, '0'));
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			cin >> g[i][j];

	vector f(n + 1, vector(m + 1, 0));
	for(int i = 1; i <= m; i ++)
		if(g[1][i] == 'X')
			f[1][i] = 1;

	for(int i = 1; i <= n; i ++)
	{
		if(i != 1)
		{
			vector<int> pre1(m + 1);
			for(int p = 1; p <= m; p ++)
				pre1[p] = (pre1[p - 1] + f[i - 1][p]) % mod;
			for(int j = 1; j <= m; j ++)
			{
				if(g[i][j] == '#') continue;
				int len = k - 1;

				int l = max(1, j - len) - 1, r = min(m, j + len);
				f[i][j] = (f[i][j] + (pre1[r] - pre1[l])) % mod;
			}
		}

		vector<int> pre(m + 1);
		for(int p = 1; p <= m; p ++)
			pre[p] = (pre[p - 1] + f[i][p]) % mod;
		for(int j = 1; j <= m; j ++)
		{
			if(g[i][j] == '#') continue;
			int l = max(1, j - k) - 1, r = min(m, j + k);
			f[i][j] = (pre[r] - pre[l]) % mod;
		}
	}

	int ans = 0;
	for(int i = 1; i <= m; i ++)
	{
		ans = (ans + f[n][i]) % mod;
	}
	cout << (ans % mod + mod) % mod << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    // t = 1;
    while(t --)
    {
        solve();
    }
    return 0;
}

