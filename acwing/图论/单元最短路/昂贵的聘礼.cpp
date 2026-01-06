#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> PII;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int gap, n;
	cin >> gap >> n;
	vector<vector<PII>> adj(100000);
	vector<int> level(n + 1);
	vector<vector<PII>> dat(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		int w0, num;
		cin >> w0 >> level[i] >> num;
		adj[0].emplace_back(i, w0);
		for(int j = 0; j < num; j ++)
		{
			int id, w1;
			cin >> id >> w1;
			dat[i].emplace_back(id, w1);
		}
	}
	for(int i = 1; i <= n; i ++)
	{
		for(auto [id, w] : dat[i])
		{
			if(abs(level[id] - level[i]) <= gap) adj[id].emplace_back(i, w);
		}
	}

	vector<int> dist(n + 1, 1e9);
	vector<int> st(n + 1);
	dist[0] = 0;
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({0, 0});
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
	cout << dist[1] << '\n';
	return 0;
}