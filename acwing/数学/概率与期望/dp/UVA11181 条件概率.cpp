#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int n, r;
	int T = 0;
	while(cin >> n >> r, n)
	{
		T ++;
		vector<double> a(n + 1);
		for(int i = 1; i <= n; i ++)
			cin >> a[i];

		auto dp = [&](int ban)->double
		{
			// vector f(n + 1, vector(r + 1, 0.0));
			vector<vector<double>> f(n + 1, vector<double>(r + 1, 0.0));
			f[0][0] = 1.0;
			for(int i = 1; i <= n; i ++)
			{
				if(i == ban)
				{
					for(int j = 0; j <= min(r, i); j ++)
						f[i][j] = f[i - 1][j];
					continue;
				}
				for(int j = 0; j <= min(r, i); j ++)
				{
					f[i][j] = f[i - 1][j] * (1 - a[i]);
					if(j > 0) f[i][j] += f[i - 1][j - 1] * a[i];
				}
			}
			return f[n][ban == 0 ? r : r - 1];
		};

		printf("Case %d:\n", T);
		double s = dp(0);
		for(int i = 1; i <= n; i ++)
		{
			printf("%.6lf\n", dp(i) * a[i] / s);
		}
	}
}