#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> v(n + 1);
	vector<int> w(n + 1);
	for(int i = 1; i <= n; i ++) cin >> v[i] >> w[i];

/*	// 前i个物品，体积恰好为j的最大收益和最优方案数
	vector<int> f(m + 1, -1e9);
	vector<int> g(m + 1);
	f[0] = 0;
	g[0] = 1;
	for(int i = 1; i <= n; i ++)
	{
		for(int j = m; j >= v[i]; j --)
		{
			if(f[j - v[i]] + w[i] == f[j]) g[j] = (g[j] + g[j - v[i]]) % mod;
			if(f[j - v[i]] + w[i] > f[j])
			{ 
				f[j] = f[j - v[i]] + w[i];
				g[j] = g[j - v[i]];
			}
		}
	}
	int res = 0;
	for(int i = 0; i <= m; i ++) res = max(res, f[i]);
	int ans = 0;
	for(int i = 0; i <= m; i ++)
		if(f[i] == res) ans = (ans + g[i]) % mod;
	cout << ans << '\n';
*/

	// 前i个物品，体积不超过j的最大收益和最优方案数
	vector<int> f(m + 1);
	vector<int> g(m + 1);
	for(int i = 0; i <= m; i ++) g[i] = 1;
	for(int i = 1; i <= n; i ++)
	{
		for(int j = m; j >= v[i]; j --)
		{
			if(f[j] == f[j - v[i]] + w[i]) g[j] = (g[j] + g[j - v[i]]) % mod;
			else if(f[j - v[i]] + w[i] > f[j])
			{
				f[j] = f[j - v[i]] + w[i];
				g[j] = g[j - v[i]];
			}
		}
	}

	cout << g[m] << '\n';
	return 0;
}