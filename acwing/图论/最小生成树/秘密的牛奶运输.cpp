#include<bits/stdc++.h>
using namespace std;
const int N = 2010;
int p[N];
typedef pair<int, int> PII;
using i64 = long long;

struct Node
{
	int w, x, y;
	bool f = false;
	bool operator < (const Node &W) const
	{
		return w < W.w;
	}
};

int find(int x)
{
	if(x != p[x]) p[x] = find(p[x]);
	return p[x];
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<Node> edges(m);
	for(int i = 1; i <= n; i ++) p[i] = i;
	for(int i = 0; i < m; i ++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		edges[i] = {w, x, y};
	}

	sort(edges.begin(), edges.end());
	vector<vector<PII>> adj(n + 1);
	i64 res = 0;
	for(auto &[w, x, y, f] : edges)
	{
		int px = find(x), py = find(y);
		if(px == py) continue;
		adj[x].emplace_back(y, w);
		adj[y].emplace_back(x, w);
		p[px] = py;
		res += w;
		f = true;
	}


	vector<vector<int>> dist(n + 1, vector<int>(n + 1));
	auto dfs = [&](auto &&self, int x, int pa, vector<int> &dist)->void
	{
		for(auto [y, w] : adj[x])
		{
			if(y == pa) continue;
			dist[y] = max(dist[x], w);
			self(self, y, x, dist);
		}
	};
	for(int i = 1; i <= n; i ++)
	{
		dfs(dfs, i, -1, dist[i]);
	}

	i64 ans = 1e18;
	for(auto [w, x, y, f] : edges)
	{
		if(f) continue;
		ans = min(ans, res + w - dist[x][y]);
	}

	cout << ans << '\n';
	return 0;
}