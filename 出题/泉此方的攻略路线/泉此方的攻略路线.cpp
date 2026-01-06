#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int n, m, l;
	cin >> n >> m >> l;
	vector<int> v(n + 1);
	for(int i = 1; i <= n; i ++) cin >> v[i];

	
	// 前i个关卡，当前魔力至少为j的最大攻略数
	vector<vector<int>> f(n + 1, vector<int>(1001, -1e9));
	for(int i = 0; i <= m; i ++) f[0][i] = 0;
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 0; j <= l; j ++)
		{
			f[i][j] = max(f[i - 1][j], f[i - 1][max(0, j - v[i])] + 1);
		}
	}
	cout << f[n][0] << '\n';

	vector<int> ans(f[n][0]);
	int cnt = 0;
	int i = n, j = 0;
	while(f[i][j])
	{
		if(f[i][j] == f[i - 1][j])
		{
			i --;
		}
		else if(f[i][j] == f[i - 1][max(0, min(l, j - v[i]))] + 1)
		{
			ans[cnt ++] = i;
			j = max(0, j - v[i]);
			i --;
		}
	}
	for(int i = ans.size() - 1; i >= 0; i --) cout << ans[i] << ' ';


/*	
	// 前i个关卡，当前魔力恰好为j的最大功略数
	vector<vector<int>> f(n + 1, vector<int>(1001, -1e9));
	f[0][m] = 0;
	for(int i = 1; i <= n ;i ++)
	{
		for(int j = 0; j <= l; j ++)
		{
			f[i][j] = f[i - 1][j];
			if(j >= v[i]) f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + 1);
		}
	}
	int res = 0;
	for(int i = 0; i <= l; i ++) res = max(res, f[n][i]);
	cout << res << '\n';
*/
	return 0;
}