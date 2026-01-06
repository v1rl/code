#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

void solve()
{
	vector<vector<pair<int, int>>> s = 
	{
		{
			{0, 0}, {0, 1}, {0, 2},
			{1, 0}, 		{1, 2},
			{2, 0}, {2, 1}, {2, 2},
			{3, 0},
			{4, 0}
		},
		{
			{0, 0}, {0, 1}, {0, 2},
					 		{1, 2},
					{2, 1}, {2, 2},
							{3, 2},
							{4, 2}			
		},
		{
			{0, 0}, {0, 1}, {0, 2},
			{1, 0}, 		{1, 2},
			{2, 0}, {2, 1}, {2, 2},
			{3, 0},			{3, 2},
			{4, 0},	{4, 1},	{4, 2}					
		}
	};

	int n, m;
	cin >> n >> m;
	vector g(n + 2, vector(m + 2, '0'));
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			cin >> g[i][j];

	vector<int> ans(3);
	auto work = [&](int x, int y, int op)->void
	{
		for(auto [dx, dy] : s[op])
		{
			int nx = dx + x, ny = dy + y;
			g[nx][ny] = '.';
		}
		ans[op] ++;
	};

	for(int j = 1; j <= m; j ++)
		for(int i = 1; i <= n; i ++)
		{
			// cerr << 'h';
			if(g[i][j] == '.') continue;
			// cout << i << ' ' << j << ' ' << g[i][j] << '\n';

			if(g[i + 1][j] != '#')
			{
				work(i, j, 1);
				continue;
			}

			bool f = true;
			for(auto [dx, dy] : s[2])
			{
				int x = dx + i, y = dy + j;
				if(g[x][y] != '#') f = false;
			}
				
			if(f) work(i, j, 2);
			else work(i, j, 0);
		}

	for(int i = 0; i < 3; i ++) 
		cout << ans[i] << ' ';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    // cin >> t;
    t = 1;
    while(t --)
    {
        solve();
    }
    return 0;
}

