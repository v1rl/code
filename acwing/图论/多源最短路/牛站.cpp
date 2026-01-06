#include<bits/stdc++.h>
using namespace std;
int k, m, stt, edd;
int n = 0;
const int N = 210;
int g[N][N];
int res[N][N];

void mul(int c[][N], int a[][N], int b[][N])
{
	static int temp[N][N];
	memset(temp, 0x3f, sizeof temp);
	for(int k = 0; k < n; k ++)
		for(int i = 0; i < n; i ++)
			for(int j = 0; j < n; j ++)
				temp[i][j] = min(temp[i][j], a[i][k] + b[k][j]);

	memcpy(c, temp, sizeof temp);
}

void qmi(int k)
{
	memset(res, 0x3f, sizeof res);				//按只经过0条边初始化res
	for(int i = 0; i < n; i ++) res[i][i] = 0;
	while(k)
	{
		if(k & 1) mul(res, res, g);
		mul(g, g, g);
		k >>= 1;
	}
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	unordered_map<int, int> mp;
	cin >> k >> m >> stt >> edd;

	memset(g, 0x3f, sizeof g);				//按只经过1条边初始化g
	for(int i = 0; i < m; i ++)
	{
		int x, y, w;
		cin >> w >> x >> y;
		if(!mp.count(x)) mp[x] = n ++;
		if(!mp.count(y)) mp[y] = n ++;
		x = mp[x], y = mp[y];
		g[x][y] = g[y][x] = min(g[x][y], w);
	}

	qmi(k);

	stt = mp[stt], edd = mp[edd];
	cout << res[stt][edd] << '\n';
}