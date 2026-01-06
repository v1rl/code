#include <bits/stdc++.h>
using namespace std;
//https://www.luogu.com.cn/problem/P3379
const int N = 5e5 + 10;
int n, m, root;
vector<vector<int>> adj(N);
int dep[N];
int f[N][25];
int len;

void bfs()
{
	queue<int> q;
	dep[root] = 1;
	q.push(root);

	while(q.size())
	{
		int x = q.front();
		q.pop();

		for(auto y : adj[x])
		{
			if(dep[y]) continue;
			dep[y] = dep[x] + 1;
			f[y][0] = x;
			for(int i = 1; i <= len; i ++)
			{
				f[y][i] = f[f[y][i - 1]][i - 1];
			}
			q.push(y);
		}
	}
}

int lca(int x, int y)
{
	if(dep[x] > dep[y]) swap(x, y);
	for(int i = len; i >= 0; i --)
	{
		if(dep[f[y][i]] >= dep[x]) y = f[y][i];
	}
	if(x == y) return x;
	for(int i = len; i >= 0; i --)
	{
		if(f[y][i] != f[x][i]) y = f[y][i], x = f[x][i];
	}
	return f[x][0];
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n >> m >> root;
	len = log(n) / log(2);
	for(int i = 1; i < n; i ++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].emplace_back(y);
		adj[y].emplace_back(x);
	}

	bfs();

	while(m --)
	{
		int x, y;
		cin >> x >> y;
		cout << lca(x, y) << "\n";
	}
}