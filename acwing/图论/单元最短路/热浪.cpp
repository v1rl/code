#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int n, m, stt, edd;
	cin >> n >> m >> stt >> edd;
	stt --, edd --;
	vector<vector<PII>> adj(n);
	for(int i = 0; i < m; i ++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		x --, y --;
		adj[x].emplace_back(y, w);
		adj[y].emplace_back(x, w);
	}

	vector<int> dist(n, 1e9);
	vector<bool> st(n);
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	dist[stt] = 0;
	heap.push({0, stt});
	while(!heap.empty())
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
	cout << dist[edd] << '\n';
}
