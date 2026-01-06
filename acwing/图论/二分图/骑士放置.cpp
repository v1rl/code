#include<bits/stdc++.h>
using namespace std;
const int N = 110;
typedef pair<int, int> PII;
bool g[N][N];
bool st[N][N];
PII match[N][N];
int n, m, t;

int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

bool dfs(int x, int y)
{
	for(int i = 0; i < 8; i ++)
	{
		int wx = x + dx[i], wy = y + dy[i];
		if(wx < 1 || wx > n || wy < 1 || wy > m) continue;
		if(st[wx][wy] || g[wx][wy]) continue;
		st[wx][wy] = true;
		if(match[wx][wy] == (PII){0, 0} || dfs(match[wx][wy].first, match[wx][wy].second))
		{
			match[wx][wy] = {x, y};
			return true;
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);

	cin >> n >> m >> t;
	for(int i = 0; i < t; i ++)
	{
		int x, y;
		cin >> x >> y;
		g[x][y] = true;
	}

	int res = 0;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
		{
			if(!g[i][j] && i + j & 1)
			{
				memset(st, false, sizeof st);
				if(dfs(i, j)) res ++;
			}
		}

	cout << n * m - res << '\n';
	return 0;
}