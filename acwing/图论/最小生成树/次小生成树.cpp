#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1e5 + 10, inf = 0x3f3f3f3f;
typedef pair<int, int> PII;
int p[N];
int dep[N];
int f[N][17];
int g1[N][17];
int g2[N][17];
int len;
vector<vector<PII>> adj;

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
			g1[y][0] = w;
			g2[y][0] = -inf;
			for(int i = 1; i < len; i ++)
			{	
				int mid = f[y][i - 1];
				f[y][i] = f[mid][i - 1];
				int sel[4] = {g1[y][i - 1], g2[y][i - 1], g1[mid][i - 1], g2[mid][i - 1]};
				for(int j = 0; j < 4; j ++)
				{
					if(sel[j] > g1[y][i]) g2[y][i] = g1[y][i], g1[y][i] = sel[j];
					else if(sel[j] < g1[y][i] && sel[j] > g2[y][i]) g2[y][i] = sel[j];
				}
			}
			q.push(y);
		}
	}
}

int lca(int w, int x, int y)
{
	if(dep[x] > dep[y]) swap(x, y);
	int sel[N];
	int cnt = 0;
	for(int i = len - 1; i >= 0; i --)
	{
		if(dep[f[y][i]] >= dep[x])
		{
			sel[++ cnt] = g1[y][i];
			sel[++ cnt] = g2[y][i];
			y = f[y][i];
		}
	}
	if(x != y)
	{
		for(int i = len - 1; i >= 0; i --)
		{
			if(f[x][i] != f[y][i])
			{
				sel[++ cnt] = g1[x][i];
				sel[++ cnt] = g2[x][i];
				sel[++ cnt] = g1[y][i];
				sel[++ cnt] = g2[y][i];
				x = f[x][i], y = f[y][i];
			}
		}
		sel[++ cnt] = g1[x][0];
		sel[++ cnt] = g1[y][0];
	}
	int max1 = -inf, max2 = -inf;
	for(int i = 1; i <= cnt; i ++)
	{
		if(sel[i] > max1) max2 = max1, max1 = sel[i];
		else if(sel[i] < max1 && sel[i] > max2) max2 = sel[i];
	}

	if(max1 < w) return w - max1;
	if(max2 < w) return w - max2;
	return inf;
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

	i64 res = 0;
	adj.assign(n + 1, vector<PII>());
	sort(edges.begin(), edges.end());
	for(auto &[w, x, y, f] : edges)
	{
		int px = find(x), py = find(y);
		if(px == py) continue;
		p[px] = py;
		res += w;
		adj[x].emplace_back(y, w);
		adj[y].emplace_back(x, w);
		f = true;
	}

	bfs(1);

	i64 ans = 1e18;
	for(auto [w, x, y, f] : edges)
	{
		if(f) continue;
		ans = min(ans, res + lca(w, x, y));
	}

	cout << ans << '\n';
	return 0;
}