#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef pair<int, int> PII;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int n;
	cin >> n;
	vector<vector<PII>> adj(n + 1);
	vector<int> d1(n + 1);
	vector<int> d2(n + 1);
	vector<int> s1(n + 1);
	vector<int> up(n + 1);
	for(int i = 1; i < n; i ++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].emplace_back(y, w);
		adj[y].emplace_back(x, w);
	}

	int ans = 1e9, id = 0;
	auto dfs1 = [&](auto &&self, int x, int p)->void
	{
		for(auto [y, w] : adj[x])
		{
			if(y == p) continue;
			self(self, y, x);
			int d = d1[y] + w;

			if(d > d1[x]) d2[x] = d1[x], d1[x] = d, s1[x] = y;
			else if(d > d2[x]) d2[x] = d;
		}
	};

	auto dfs2 = [&](auto &&self, int x, int p)->void
	{
		for(auto [y, w] : adj[x])
		{
			if(y == p) continue;

			if(s1[x] == y) up[y] = max(up[x], d2[x]) + w;
			else up[y] = max(up[x], d1[x]) + w;

			self(self, y, x);
		}
	};

	dfs1(dfs1, 1, -1);
	dfs2(dfs2, 1, -1);

	int res = 1e9;
	for(int i = 1; i <= n; i ++)
	{
		res = min(res, max(d1[i], up[i]));
	}

	cout << res << '\n';
	return 0;
}
