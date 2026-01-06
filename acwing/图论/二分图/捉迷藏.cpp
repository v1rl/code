#include<bits/stdc++.h>
using namespace std;
const int N = 210;
bool dist[N][N];

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < m; i ++)
	{
		int x, y;
		cin >> x >> y;
		dist[x][y] = true;
	}

	for(int k = 1; k <= n; k ++)
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++)
				dist[i][j] |= dist[i][k] & dist[k][j];

	vector<int> match(n + 1);
	vector<bool> st(n + 1);
	auto dfs = [&](auto &&self, int x)->bool
	{
		for(int y = 1; y <= n; y ++)
		{
			if(!dist[x][y] || st[y]) continue;
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
	for(int i = 1; i <= n; i ++)
	{
		st.assign(n + 1, false);
		if(dfs(dfs, i)) res ++;
	}

	cout << n - res << '\n';
	return 0;
}