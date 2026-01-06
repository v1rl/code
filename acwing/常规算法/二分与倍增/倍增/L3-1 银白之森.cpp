#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
	int n, q;
	cin >> n >> q;
	vector f(n + 1, vector(55, array<i64, 2>{0, 0}));
	for(int i = 1; i <= n; i ++)
	{
		int x;
		cin >> x;
		f[i][0] = {x, x};
	}
	for(int j = 1; j <= 50; j ++)
	{
		for(int i = 1; i <= n; i ++)
		{
			f[i][j][0] = f[f[i][j - 1][0]][j - 1][0];
			f[i][j][1] = f[i][j - 1][1] + f[f[i][j - 1][0]][j - 1][1];
		}
	}

	while(q --)
	{
		i64 x, k;
		cin >> x >> k;
		i64 res = 0;
		for(int j = 0; j <= 50; j ++)
		{
			if(k >> j & 1)
			{
				res += f[x][j][1];
				x = f[x][j][0];
			}
		}
		cout << res << '\n';
	}
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
}