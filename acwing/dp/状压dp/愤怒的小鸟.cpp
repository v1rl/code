#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int M = (1 << 18) + 10;
int f[M];
int n, m;

int cmp(double x, double y)
{
	if(fabs(x - y) < eps) return 0;
	if(x < y) return -1;
	return 1;
}

void solve()
{
	cin >> n >> m;
	vector<array<double, 2>> p(n);
	for(int i = 0; i < n; i ++) cin >> p[i][0] >> p[i][1];
	vector<vector<int>> path(n, vector<int>(n));

	for(int i = 0; i < n; i ++)
	{
		double x1 = p[i][0], y1 = p[i][1];
		for(int j = i; j < n; j ++)
		{
			double x2 = p[j][0], y2 = p[j][1];
			if(i == j)
			{
				path[i][j] = 1 << j;
				continue;
			}
			if(!cmp(x1, x2)) continue;
			double a = (y1 / x1 - y2 / x2) / (x1 - x2);
			double b = y1 / x1 - a * x1;
			if(cmp(a, 0) >= 0) continue;
			int state = 0;
			for(int k = 0; k < n; k ++)
			{
				double x = p[k][0], y = p[k][1];
				if(!cmp(a * x * x + b * x, y)) state += 1 << k;
			}
			path[i][j] = path[j][i] = state;
		}
	}

	// 记忆化搜索
	memset(f, 0, sizeof f);
	auto dfs = [&](auto && self, int state)->int
	{
		if(state == (1 << n) - 1) return 0;
		if(f[state]) return f[state];

		int x = 0;
		for(int i = 0; i < n; i ++)
		{
			if(!(state >> i & 1))
			{
				x = i;
				break;
			}
		}

		int res = 1e9;
		for(int i = 0; i < n; i ++)
		{
			if(!path[x][i]) continue;
			res = min(res, self(self, state | path[x][i]) + 1);
		}
		return f[state] = res;
	};

	cout << dfs(dfs, 0) << '\n';
/*
	// 递推
	memset(f, 0x3f, sizeof f);
	f[0] = 0;
	for(int i = 0; i < 1 << n; i ++)
	{
		int x = 0;
		for(int j = 0; j < n; j ++)
		{
			if(!(i >> j & 1))
			{
				x = j;
				break;
			}
		}
		for(int j = x; j < n; j ++)
		{
			f[i | path[x][j]] = min(f[i | path[x][j]], f[i] + 1);
		}
	}
	cout << f[(1 << n) - 1] << '\n';
*/
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int T;
	cin >> T;
	while(T -- )
	{
		solve();
	}
	return 0;
}