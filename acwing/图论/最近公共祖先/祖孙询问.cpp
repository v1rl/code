#include<bits/stdc++.h>
using namespace std;
const int N = 4e4 + 10;
int dep[N];
int f[N][16];
int len;
vector<vector<int>> adj;

void bfs(int root)
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
			for(int i = 1; i <= len; i ++) f[y][i] = f[f[y][i - 1]][i - 1];
			q.push(y);
		}
	}
}

int lca(int x, int y)
{
	bool flag = 0;
	if(dep[x] > dep[y]) 
	{
		flag = 1;
		swap(x, y);
	}
	for(int i = len; i >= 0; i --)
	{
		if(dep[f[y][i]] >= dep[x]) 
			y = f[y][i];
	}
	if(x == y) return x;
	for(int i = len; i >= 0; i --)
	{
		if(f[y][i] != f[x][i])
			y = f[y][i], x= f[x][i];
	}
	return f[y][0];
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int n;
	cin >> n;
	len = log2(n);
	adj.assign(N, vector<int>());
	int root;
	
	for(int i = 0; i < n; i ++)
	{
		int x, y;
		cin >> x >> y;
		if(y == -1) 
		{
			root = x;
			continue;
		}
		adj[x].emplace_back(y);
		adj[y].emplace_back(x);
	}

	bfs(root);

	int m;
	cin >> m;
	for(int i = 0; i < m; i ++)
	{
		int x, y;
		cin >> x >> y;
		int p = lca(x, y);
		if(p == x) cout << '1' << '\n';
		else if(p == y) cout << '2' << '\n';
		else cout << '0' << '\n';
	}
	return 0;
}