#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 1e9 + 7;

void solve()
{
	int n, r;
	cin >> n >> r;
	vector<double> p(n + 1);
	vector<int> d(n + 1);
	for(int i = 1; i <= n; i ++)
		cin >> p[i] >> d[i];

	vector f(n + 1, vector(r + 1, 0.0));
	f[0][0] = 1.0;
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 0; j <= min(i, r); j ++)
		{
			f[i][j] += f[i - 1][j] * (1 - (1 - pow(1 - p[i], r - j)));
			if(j > 0) f[i][j] += f[i - 1][j - 1] * (1 - pow(1 - p[i], r - j + 1));
		}
	}

	vector<double> g(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 0; j <= min(r, i - 1); j ++)
		{
			g[i] += f[i - 1][j] * (1 - pow(1 - p[i], r - j));
		}
	}

	double ans = 0;
	for(int i = 1; i <= n; i ++)
	{
		ans += g[i] * d[i];
	}
	printf("%.8lf\n", ans);
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
}