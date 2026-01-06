#include<bits/stdc++.h>
using namespace std;
int n, m;
const int N = 110;
int res[N], cnt = 0;
int path[N][N];

void get_path(int x, int y)
{
	if(!path[x][y]) return;
	int k = path[x][y];
	get_path(x, k);
	res[cnt ++] = k;
	get_path(k, y);
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	vector<vector<int>> w(n + 1, vector<int>(n + 1, 1e8));
	for(int i = 1; i <= n; i ++) w[i][i] = 0;
	for(int i = 0; i < m; i ++)
	{
		int x, y, ww;
		cin >> x >> y >> ww;
		w[x][y] = w[y][x] = min(w[x][y], ww);
	}

	vector<vector<int>> dist = w;
	int ans = 1e8;
	for(int k = 1; k <= n; k ++)		//防止重复选取，同时保证k是最大值
	{
		for(int i = 1; i < k; i ++)
			for(int j = i + 1; j < k; j ++)
			{
				if(w[i][k] + w[k][j] + dist[i][j] < ans)
				{
					ans = w[i][k] + w[k][j] + dist[i][j];
					cnt = 0;
					res[cnt ++] = i;
					get_path(i, j);
					res[cnt ++] = j;
					res[cnt ++] = k;
				}
			}

		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++)
			{
				if(dist[i][j] > dist[i][k] + dist[k][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j] = k;
				}
			}
	}

	if(ans == 1e8) cout << "No solution.";
	else for(int i = 0; i < cnt; i ++) cout << res[i] << ' ';
	return 0;
}