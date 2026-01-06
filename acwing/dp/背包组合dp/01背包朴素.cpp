#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> v(n + 1);
	vector<int> w(n + 1);
	for(int i = 1; i <= n; i ++) cin >> v[i] >> w[i];

	vector<vector<int>> f(n + 1, vector<int>(m + 1));
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= m; j ++)
		{
			f[i][j] = f[i - 1][j];
			if(j >= v[i]) f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
		}
	}

	cout << f[n][m] << '\n';
}