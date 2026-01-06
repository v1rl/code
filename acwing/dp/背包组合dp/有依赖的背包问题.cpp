#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int f[N][N];

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> v(n + 1);
	vector<int> w(n + 1);
	vector<vector<int>> adj(n + 1);
	int root;
	for(int i = 1; i <= n; i ++)
	{
		int op;
		cin >> v[i] >> w[i] >> op;
		if(op == -1) root = i;
		else adj[op].emplace_back(i);
	}

	auto dfs = [&](auto && self, int x)->void
	{
		for(int j = v[x]; j <= m; j ++) f[x][j] = w[x];
		for(auto y : adj[x])
		{
			self(self, y);
			for(int j = m; j >= v[x]; j --)
			{
				for(int k = 0; k <= j - v[x]; k ++)
				{
					f[x][j] = max(f[x][j], f[x][j - k] + f[y][k]);
				}
			}
		}
	};

	dfs(dfs, root);
	cout << f[root][m] << '\n';
	return 0;
}