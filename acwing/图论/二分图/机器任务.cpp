#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int n1, n2, m;
	while(cin >> n1 >> n2 >> m, n1)
	vector<vector<int>> adj(n1);
	for(int i = 0; i < m; i ++)
	{
		int id, x, y;
		cin >> id >> x >> y;
		if(x && y) adj[x].emplace_back(y);
	}

	vector<int> match(n2);
	vector<bool> st(n2);
	auto dfs = [&](auto && self, int x)->bool
	{
		for(auto y : adj[x])
		{
			if(st[y]) continue;
			st[y] = true;
			if(!match[y] || self(self, match[y]))
			{
				match[y] = x;
				return true;
			}
		}
		return false;
	};

	int res = 0;
	for(int i = 1; i < n1; i ++)
	{
		st.assign(n2, 0);
		if(dfs(dfs, i)) res ++;
	}

	cout << res << '\n';
	return 0;
}