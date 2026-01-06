#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1010;
int w[N];
vector<vector<int>> adj(N);
bool vis[N][N];
bool f[N];

// https://www.luogu.com.cn/problem/P12136

void dfs(int x, int p)
{
	bool flag = false;
	int s = 0;
	vector<vector<int>> v;
	for(auto y : adj[x])
	{
		if(y == p) continue;

		flag = true;
		dfs(y, x);

		v.push_back({});
		for(int i = 1; i <= w[x]; i ++)
			if(vis[y][i])
				v[s].emplace_back(i);

		s ++;
	}

	for(int i = 0; i <= w[x]; i ++) f[i] = false;
	f[0] = true;
	if(!flag) v.push_back({w[x]});

	for(int i = 0; i < v.size(); i ++)
		for(int j = w[x]; j >= 0; j --)
			for(int k = 0; k < v[i].size(); k ++)
				if(j >= v[i][k]) f[j] |= f[j - v[i][k]];
			
	for(int i = 0; i <= w[x]; i ++)
		vis[x][i] |= f[i];
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> w[i];
	for(int i = 1; i < n; i ++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].emplace_back(y);
		adj[y].emplace_back(x);
	}

	dfs(1, -1);
	for(int i = w[1]; i >= 0; i --)
	{
		if(vis[1][i])
		{
			cout << i << '\n';
			break;
		}
	}
	return 0;
}