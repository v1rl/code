#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int  n, m, k;
	cin >> n >> m >> k;
	vector<vector<PII>> adj(n + 1);
	for(int i = 0; i < m; i ++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].emplace_back(y, w);
		adj[y].emplace_back(x, w);
	}

	vector<vector<int>> dist(n + 1, vector<int>(k + 1, 1e9));
	dist[1][0] = 0;
	queue<PII> q;
	vector<vector<bool>> st(n + 1, vector<bool>(k + 1));
	q.push({1, 0});
	st[1][0] = true;
	while(q.size())
	{
		auto [x, id] = q.front();
		q.pop();
		st[x][id] = false;
		for(auto [y, w] : adj[x])
		{
			if(dist[y][id] > max(dist[x][id], w))
			{
				dist[y][id] = max(dist[x][id], w);
				if(!st[y][id]) q.push({y, id}), st[y][id] = true;
			}
			if(id < k && dist[y][id + 1] > dist[x][id])
			{
				dist[y][id + 1] = dist[x][id];
				if(!st[y][id + 1]) q.push({y, id + 1}), st[y][id + 1] = true;
			}
		}
	}

	int ans = 1e9;
	for(int i = 0; i <= k; i ++) ans = min(ans, dist[n][i]);
	if(ans == 1e9) cout << -1 << '\n';
	else cout << ans << '\n';
	return 0;

}