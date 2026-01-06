#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int n;
	cin >> n;
	vector<int> s(n + 1);
	vector<vector<int>> adj(n + 1);
	for(int i = 1; i <= n; i ++)
		for(int j = 2; j <= n / i; j ++)
			s[i * j] += i;

	for(int i = 1; i <= n; i ++)
		if(s[i] < i)
			adj[s[i]].emplace_back(i);

	vector<int> st(n + 1);
	int ans = 0;
	auto dfs = [&](auto && self, int x, int p)->int
	{
		st[x] = true;
		int d1 = 0, d2 = 0;
		for(auto y : adj[x])
		{
			if(y == p) continue;

			int d = self(self, y, x) + 1;
			if(d > d1) d2 = d1, d1 = d;
			else if(d > d2) d2 = d;

			ans = max(ans, d1 + d2);
		}
		return d1;
	};

	for(int i = 1; i <= n; i ++)
		if(!st[i]) 
			dfs(dfs, i, -1);

	cout << ans << '\n';
	return 0;
}
