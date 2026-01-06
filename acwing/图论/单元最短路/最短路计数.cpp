#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int mod = 100003;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int n, m;
	cin >> n >> m;

	// 边权都为 1，bfs
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < m; i ++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].emplace_back(y);
		adj[y].emplace_back(x);
	}

	vector<int> dist(n + 1, 1e9);
	vector<int> f(n + 1);
	f[1] = 1;
	queue<int> q;
	dist[1] = 0;
	q.push(1);
	while(q.size())
	{
		int x = q.front();
		q.pop();
		for(auto y : adj[x])
		{
			if(dist[y] > dist[x] + 1)
			{
				dist[y] = dist[x] + 1;
				f[y] = f[x];
				q.push(y);
			}
			else if(dist[y] == dist[x] + 1) f[y] = (f[x] + f[y]) % mod;
		}
	}


/*
	// 边权可以为任意值，spfa
	vector<vector<PII>> adj(n + 1);
	for(int i = 0; i < m; i ++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].emplace_back(y, w);
		adj[y].emplace_back(x, w);
	}

	vector<int> dist(n + 1, 1e9);
	vector<bool> st(n + 1);
	vector<int> f(n + 1);
	f[1] = 1;
	queue<int> q;
	dist[1] = 0;
	q.push(1);
	st[1] = true;
	while(q.size())
	{
		int x = q.front();
		q.pop();
		st[x] = false;
		for(auto [y, w] : adj[x])
		{
			if(dist[y] > dist[x] + w)
			{
				dist[y] = dist[x] + w;
				f[y] = f[x];
				if(!st[y]) q.push(y), st[y] = true;
			}
			else if(dist[y] == dist[x] + w) f[y] = (f[x] + f[y]) % mod;
		}
	}
*/

	for(int i = 1; i <= n; i ++) cout << f[i] << '\n';
	return 0;	

}