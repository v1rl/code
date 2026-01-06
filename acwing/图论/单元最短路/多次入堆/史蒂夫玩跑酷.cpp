#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;

// https://ac.nowcoder.com/acm/contest/104870/F

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
//	vector<vector<int>> g(n + 1, vector<int>(m + 1));
	vector g(n + 1, vector(m + 1, '0'));
	array<int, 2> stt, edd;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
		{
			cin >> g[i][j];
			if(g[i][j] == 's') stt = {i, j};
			else if(g[i][j] == 't') edd = {i, j};
		}
		
	auto get = [&](int x, int y)
	{
		return m * (x - 1) + y;
	};
	
	vector<vector<PII>> adj(n * m + 1);
	
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= m; j ++)
		{
			for(int x = max(1, i - k); x <= min(n, i + k); x ++)
			{
				for(int y = max(1, j - k); y <= min(m, j + k); y ++)
				{
					if(1ll * (x - i) * (x - i) + 1ll * (y - j) * (y - j) > k * k) continue;
					int u = get(i, j), v = get(x, y);
					if(g[x][y] == '0') 
						adj[u].push_back({v, 1});
					else adj[u].push_back({v, 0});
				}
			}
		}
	}
	
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	vector<int> dist(n * m + 1, 1e9);
	vector<int> st(n * m + 1);
	vector<int> f(n * m + 1, 1e9);
	int s = get(stt[0], stt[1]);
	dist[s] = 0;
	f[s] = 0;
	heap.push({0, s});
	while(heap.size())
	{
		auto [d, x] = heap.top();
		heap.pop();
		if(st[x]) continue;
		st[x] = true;
		for(auto [y, w] : adj[x])
		{
			if(dist[y] > dist[x] + w)
			{
				dist[y] = dist[x] + w;
				heap.push({dist[y], y});
				f[y] = f[x] + 1;
			}
			else if(dist[y] == dist[x] + w)
			{
				if(f[y] > f[x] + 1)
				{
					f[y] = f[x] + 1;
					heap.push({dist[y], y});
					st[y] = false;

				}
			}
		}
	}
	
	int t = get(edd[0], edd[1]);
	cout << dist[t] << ' ' << f[t] << '\n';
}