#include<bits/stdc++.h>
using namespace std;
typedef pair<int, double> PID;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int n;
	cin >> n;
	vector<array<int, 2>> p(n);
	for(int i = 0; i < n; i ++)
	{
		int x, y;
		cin >> x >> y;
		x, y;
		p[i] = {x, y};
	}

	string g[n];
	for(int i = 0; i < n; i ++) cin >> g[i];

	vector<vector<double>> dist(n, vector<double>(n, 1e9));
	for(int i = 0; i < n; i ++) dist[i][i] = 0;
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < n; j ++)
		{
			if(g[i][j] == '1')
			{
				int x = p[i][0] - p[j][0], y = p[i][1] - p[j][1];
				double w = sqrtl(x * x + y * y);
				dist[i][j] = w;
			}
		}

	for(int k = 0; k < n; k ++)
		for(int i = 0; i < n; i ++)
			for(int j = 0; j < n; j ++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	vector<double> maxd(n);
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < n; j ++)
		{
			if(dist[i][j] == 1e9) continue;
			maxd[i] = max(maxd[i], dist[i][j]);
		}

	double res = 0;
	for(int i = 0; i < n; i ++) res = max(res, maxd[i]);

	double ans = 1e9;
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < n; j ++)
		{
			if(dist[i][j] == 1e9)
			{
				int x = p[i][0] - p[j][0], y = p[i][1] - p[j][1];
				double w = sqrtl(x * x + y * y);
				ans = min(ans, maxd[i] + maxd[j] + w);
			}
		}

	printf("%.6lf", max(res, ans));
	return 0;
}