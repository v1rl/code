#include <bits/stdc++.h>
using namespace std;
const int N = 100, M = 100;
int v[N][M];
int w[N][M];
int f[N][M];

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= m; j ++)
		{
			v[i][j] = j;
			cin >> w[i][j];
		}
	}

	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= m; j ++)
		{
			for(int k = 0; k <= m; k ++)
			{
				if(j >= v[i][k]) f[i][j] = max(f[i][j], f[i - 1][j - v[i][k]] + w[i][k]);
			}
		}
	}

	int i = n, j = m;
	vector<int> ans(n + 1);
	while(i > 0)
	{
		for(int k = 0; k <= m; k ++)
		{
			if(f[i][j] == f[i - 1][j - v[i][k]] + w[i][k])
			{
				ans[i] = k;
				i --, j -= v[i][k];
				break;
			}
		}
	}

	cout << f[n][m] << '\n';
	for(int i = 1; i <= n; i ++) cout << i << ' ' << ans[i] << '\n';
	return 0;
}