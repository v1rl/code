#include<bits/stdc++.h>
using namespace std;
const int N = 110;
int f[N][N];
typedef pair<int, int> PII;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<PII>> adj(n + 1);
	for(int i = 1; i < n; i ++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].emplace_back(y, w);
		adj[y].emplace_back(x, w);
	}

	auto dfs = [&](auto &&self, int x, int p)->void
	{
		for(auto [y, w] : adj[x])
		{
			if(y == p) continue;

			self(self, y, x);
			for(int i = m; i >= 0; i --)
				for(int j = 1; j <= i; j ++)
					f[x][i] = max(f[x][i], f[x][i - j] + f[y][j - 1] + w);
		}
	};

	dfs(dfs, 1, -1);
	cout << f[1][m] << '\n';
}
