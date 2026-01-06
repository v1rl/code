#include<bits/stdc++.h>
using namespace std;
const int N = 110;
typedef pair<int, int> PII;
bool g[N][N];
bool st[N][N];
PII match[N][N];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
int n, t;

bool find(int x, int y)
{
	for(int i = 0; i < 4; i ++)
	{
		int wx = x + dx[i], wy = y + dy[i];
		if(wx < 1 || wx > n || wy < 1 || wy > n) continue;
		if(st[wx][wy] || g[wx][wy]) continue;
		st[wx][wy] = true;
		if(match[wx][wy] == (PII){0, 0} || find(match[wx][wy].first, match[wx][wy].second))
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
	cin >> n >> t;
	for(int i = 0; i < t; i ++) 
	{
		int x, y;
		cin >> x >> y;
		g[x][y] = true;
	}

	int res = 0;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
		{
			if(i + j & 1 && !g[i][j])
			{
				memset(st, false, sizeof st);
				if(find(i, j)) res ++;
			}
		}

	cout << res << '\n';
	return 0;
}