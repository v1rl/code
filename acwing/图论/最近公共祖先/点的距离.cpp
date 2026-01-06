#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef pair<int, int> PII;
vector<vector<int>> adj;
vector<vector<PII>> query;
int ans[N];
int dep[N];
int st[N];
int p[N];
int n;

int find(int x)
{
	if(x != p[x]) p[x] = find(p[x]);
	return p[x];
}

void tarjan(int x, int pa)
{
	for(auto y : adj[x])
	{
		if(y == pa) continue;
		dep[y] = dep[x] + 1;
		tarjan(y, x);
		p[y] = x;
	}
 
	st[x] = true;
	for(auto [y, id] : query[x])
	{
		if(st[y])
		{
			int anc = find(y);
			ans[id] = dep[x] + dep[y] - 2 * dep[anc];
		}
	}
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) p[i] = i;
	adj.assign(n + 1, vector<int>());
	for(int i = 0; i < n - 1; i ++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].emplace_back(y);
		adj[y].emplace_back(x);
	}

	int m;
	cin >> m;
	query.assign(n + 1, vector<PII>());
	for(int i = 0; i < m; i ++)
	{
		int x, y;
		cin >> x >> y;
		query[x].emplace_back(y, i), query[y].emplace_back(x, i);
	}
	dep[1] = 0;
	tarjan(1, -1);
	for(int i = 0; i < m; i ++) cout << ans[i] << '\n';
	return 0;
}