#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int n, m1, m2, stt;
	cin >> n >> m1 >> m2 >> stt;
	vector<vector<PII>> adj(n + 1);
	vector<int> din(n + 1);
	vector<int> id(n + 1);
	vector<vector<int>> block(n + 1);
	for(int i = 0; i < m1; i ++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].emplace_back(y, w);
		adj[y].emplace_back(x, w);
	}

	auto dfs = [&](auto &&self, int x, int u)->void
	{
		id[x] = u;
		block[u].emplace_back(x);
		for(auto [y, w] : adj[x])
		{
			if(!id[y]) self(self, y, u);
		}
	};

	int cnt = 0;
	for(int i = 1; i <= n; i ++)
	{
		if(!id[i])
		{
			dfs(dfs, i, ++ cnt);
		}
	}

	for(int i = 0; i < m2; i ++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].emplace_back(y, w);
		din[id[y]] ++;
	}

	queue<int> q;
	for(int i = 1; i <= cnt; i ++) 
		if(din[i] == 0) 
			q.push(i);

	vector<int> dist(n + 1, 1e9);
	vector<bool> st(n + 1);
	dist[stt] = 0;
	while(q.size())
	{
		int t = q.front();
		q.pop();
		priority_queue<PII, vector<PII>, greater<PII>> heap;
		for(auto y : block[t]) heap.push({dist[y], y});
		while(heap.size())
		{
			auto [_, x] = heap.top();
			heap.pop();
			if(st[x]) continue;
			st[x] = true;
			for(auto [y, w] : adj[x])
			{
				if(id[y] == t)
				{
					if(dist[y] > dist[x] + w)
					{
						dist[y] = dist[x] + w;
						heap.push({dist[y], y});
					}	
				}
				else
				{
					dist[y] = min(dist[y], dist[x] + w);
					if(-- din[id[y]] == 0) q.push(id[y]);
				}
			}
		}
	}

	for(int i = 1; i <= n; i ++)
	{
		if(dist[i] < 1e9 / 2) cout << dist[i] << '\n';
		else cout << "NO PATH" << '\n';
	}
	return 0;

}