#include<bits/stdc++.h>
using namespace std;
const int N = 210;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> adj(n + 1);
	for(int i = 1; i < n ;i ++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].emplace_back(y);
		adj[y].emplace_back(x);
	}

	int ans = 0;
	auto dfs = [&](auto &&self, int x, int p)->int
	{
		int d1 = 0, d2 = 0;
		for(auto y : adj[x])
		{
			if(y == p) continue;
			int d = self(self, y, x) + 1;

			if(d > d1) d2 = d1, d1 = d;
			else if(d > d2) d2 = d;
		}
		ans = max(ans, d1 + d2);
		return d1;
	};

	dfs(dfs, 1, -1);
	cout << ans << '\n';
}
