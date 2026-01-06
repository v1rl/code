#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 510, M = 3000;
int g[N][N];
int d[N];
int ans[M], cnt;

void dfs(int x)
{
	for(int i = 1; i <= 500; i ++)
	{
		if(g[x][i])
		{
			g[x][i] --, g[i][x] --;
			dfs(i);
		}
	}
	ans[++ cnt] = x;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int m;
	cin >> m;
	for(int i = 0; i < m; i ++)
	{
		int x, y;
		cin >> x >> y;
		g[x][y] ++, g[y][x] ++;
		d[y] ++, d[x] ++;
	}

	int start = 1;
	while(!d[start]) start ++;
	for(int i = 1; i <= 500; i ++)
	{
		if(d[i] & 1) 
		{
			start = i;
			break;
		}
	}

	dfs(start);
	for(int i = cnt; i; i --) cout << ans[i] << '\n';
	return 0;
}