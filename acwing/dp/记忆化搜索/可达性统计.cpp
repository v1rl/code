#include<bits/stdc++.h>
using namespace std;
const int N = 3e4 + 10;
vector<vector<int>> adj;
vector<bitset<N>> f(N);
bitset<N> dp(int x)
{
	if(f[x].count()) return f[x];
	f[x][x] = 1;
	for(auto y : adj[x]) 
		f[x] |= dp(y);
	return f[x];
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int n, m;
	cin >> n >> m;
	adj.assign(n + 1, vector<int>());
	for(int i = 0; i < m; i ++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].emplace_back(y);
	}

	for(int i = 1; i <= n; i ++)
	{
		cout << dp(i).count() << '\n';
	}
}