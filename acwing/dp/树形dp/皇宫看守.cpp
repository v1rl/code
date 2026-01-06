#include<bits/stdc++.h>
using namespace std;
const int N = 1510;
int f[N][3];

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> adj(n + 1);
	vector<int> st(n + 1);
	vector<int> w(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		int x, m;
		cin >> x >> w[x] >> m;
		for(int i = 0; i < m; i ++)
		{
			int y;
			cin >> y;
			adj[x].emplace_back(y);
			st[y] = true;
		}
	}

	auto dfs = [&](auto &&self, int x)->void
	{
		f[x][0] = 0, f[x][1] = 1e9, f[x][2] = w[x];
		for(auto y : adj[x])
		{
			self(self, y);
			f[x][0] += min(f[y][1], f[y][2]);
			f[x][2] += min(f[y][0], min(f[y][1], f[y][2]));
		}
		
		for(auto y : adj[x])
			f[x][1] = min(f[x][1], f[x][0] - min(f[y][1], f[y][2]) + f[y][2]);
	};

	int root = 0;
	for(int i = 1; i <= n; i ++)
		if(!st[i])
		{
			root = i;
			dfs(dfs, i);
		}

	cout << min(f[root][1], f[root][2]);
	return 0;
}
