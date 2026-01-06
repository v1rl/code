#include<bits/stdc++.h>
using namespace std;
const int N = 1510;
int f[N][2];

int main()
{
	int n;
	while(cin >> n)
	{
		vector<vector<int>> adj(n + 1);
		vector<int> st(n + 1);
		for(int i = 0; i < n; i ++)
		{
			int x, m;
			scanf("%d:(%d)", &x, &m);
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
			f[x][1] = 1, f[x][0] = 0;
			for(auto y : adj[x])
			{
				self(self, y);
				f[x][1] += min(f[y][1], f[y][0]);
				f[x][0] += f[y][1];
			}
		};

		int root;
		for(int i = 0; i < n; i ++)
			if(!st[i]) 
			{
				root = i;
				dfs(dfs, i);
			}

		cout << min(f[root][0], f[root][1]) << '\n';
	}
}
