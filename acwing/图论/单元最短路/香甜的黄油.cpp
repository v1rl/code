#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int p, n, m;
	cin >> p >> n >> m;
	vector<int> cow(p);
	for(int i = 0; i < p; i ++) cin >> cow[i], cow[i] --;

	vector<vector<PII>> adj(n);
	for(int i = 0; i < m; i ++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		x --, y --;
		adj[x].emplace_back(y, w);
		adj[y].emplace_back(x, w);
	}

	int ans = 1e9;
	for(int i = 0; i < n; i ++)
	{
		vector<int> dist(n, 1e9);
		vector<bool> st(n);
		priority_queue<PII, vector<PII>, greater<PII>> heap;
		dist[i] = 0;
		heap.push({0, i});
		while(heap.size())
		{
			auto [_, x] = heap.top();
			heap.pop();
			if(st[x]) continue;
			st[x] = true;
			for(auto [y, w] : adj[x])
			{
				if(dist[y] > dist[x] + w)
				{
					dist[y] = dist[x] + w;
					heap.push({dist[y], y});
				}
			}
		}
		int sum = 0;
		for(auto t : cow)
		{
			if(dist[t] == 1e9)
			{
				sum = 1e9;
				break;
			}
			sum += dist[t];
		}
		ans = min(sum, ans);
	}
	cout << ans << '\n';
	return 0;
}
