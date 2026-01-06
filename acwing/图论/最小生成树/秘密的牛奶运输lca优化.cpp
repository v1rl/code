#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 2010;
typedef pair<int, int> PII;
vector<vector<PII>> adj;
int p[N];
int f[N][17];
int dep[N];
int g[N][17];
int len;
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

void bfs(int root)
{
	dep[root] = 1;
	queue<int> q;
	q.push(root);
	while(q.size())
	{
		int x = q.front();
		q.pop();
		for(auto [y, w] : adj[x])
		{
			if(dep[y]) continue;
			dep[y] = dep[x] + 1;
			f[y][0] = x;
			g[y][0] = w;
			for(int i = 1; i < len; i ++) 
			{
				int mid = f[y][i - 1];
				f[y][i] = f[mid][i - 1];
				g[y][i] = max(g[y][i - 1], g[mid][i - 1]);
			}
			q.push(y);
		}
	}
}

int lca(int x, int y)
{
	if(dep[x] > dep[y]) swap(x, y);
	int res = 0;
	for(int i = len - 1; i >= 0; i --)
	{
		if(dep[f[y][i]] >= dep[x])
		{
			res = max(res, g[y][i]);
			y = f[y][i];
		}
	}
	if(x == y) return res;
	for(int i = len - 1; i >= 0; i --)
	{
		if(f[y][i] != f[x][i])
		{
			res = max(res, max(g[x][i], g[y][i]));
			x = f[x][i], y = f[y][i];
		}
	}
	res = max(res, max(g[x][0], g[y][0]));
	return res;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int n, m;
	cin >> n >> m;
	len = log2(n) + 1;
	for(int i = 1; i <= n; i ++) p[i] = i;
	vector<Node> edges(m);
	for(int i = 0; i < m; i ++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		edges[i] = {w, x, y};
	}
	
	sort(edges.begin(), edges.end());
	adj.assign(n + 1, vector<PII>());
	i64 res = 0;
	for(auto &[w, x, y, f] : edges)
	{
		int px = find(x), py = find(y);
		if(px == py) continue;
		adj[x].emplace_back(y, w);
		adj[y].emplace_back(x, w);
		res += w;
		p[px] = py;
		f = true;
	}

	bfs(1);

	i64 ans = 1e18;
	for(auto [w, x, y, f] : edges)
	{
		if(f) continue;
		ans = min(ans, res + w - lca(x, y));
	}

	cout << ans << '\n';
	return 0;
}