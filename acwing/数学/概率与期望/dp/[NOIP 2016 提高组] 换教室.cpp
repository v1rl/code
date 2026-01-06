#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;
const double inf = 1e17;
const int iinf = 1e9;

void solve()
{
	int n, m, v, e;
	cin >> n >> m >> v >> e;
	vector<int> c(n + 1), d(n + 1);
	for(int i = 1; i <= n; i ++)
		cin >> c[i];
	for(int i = 1; i <= n; i ++)
		cin >> d[i];
	vector<double> k(n + 1);
	for(int i = 1; i <= n; i ++)
		cin >> k[i];

	vector dist(v + 1, vector(v + 1, iinf));
	for(int i = 1; i <= v; i ++) dist[i][i] = 0;

	for(int i = 1; i <= e; i ++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		dist[x][y] = dist[y][x] = min(dist[x][y], w);
	}

	for(int k = 1; k <= v; k ++)
		for(int i = 1; i <= v; i ++)
			for(int j = 1; j <= v; j ++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	vector f(n + 1, vector(m + 2, vector(2, inf)));
	f[1][0][0] = f[1][1][1] = 0;				//单独的初始化有可能越界
	for(int i = 2; i <= n; i ++)
	{
		int pos1 = c[i - 1], pos2 = d[i - 1], pos3 = c[i], pos4 = d[i]; 
		// f[i][0][0] = f[i - 1][0][0] + dist[pos1][pos3];
		for(int j = 1; j <= min(i, m); j ++)
		{
			f[i][j][0] = min({	
				f[i][j][0],
				f[i - 1][j][0] + dist[pos1][pos3], 
				f[i - 1][j][1] + k[i - 1] * dist[pos2][pos3] + (1 - k[i - 1]) * dist[pos1][pos3]
			});
			if(j > 0) f[i][j][1] = min({
				f[i][j][1], 
				f[i - 1][j - 1][0] + k[i] * dist[pos1][pos4] + (1 - k[i]) * dist[pos1][pos3], 
				f[i - 1][j - 1][1] + k[i] * k[i - 1] * dist[pos2][pos4] + k[i] * (1 - k[i - 1]) * dist[pos1][pos4]
				+ (1 - k[i]) * k[i - 1] * dist[pos2][pos3] + (1 - k[i]) * (1 - k[i - 1]) * dist[pos1][pos3]
			});
		}
	}

	double ans = inf;
	for(int j = 0; j <= m; j ++)
	{
		ans = min({ans, f[n][j][0], f[n][j][1]});
	}
	printf("%.2lf", ans);
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
}