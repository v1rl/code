#include<bits/stdc++.h>
using namespace std;
const int N = 3e4 + 10;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	vector<int> din(n + 1);
	for(int i = 0; i < m; i ++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].emplace_back(y);
		din[y] ++;
	}

	queue<int> q;
	for(int i = 1; i <= n; i ++)
		if(din[i] == 0)
			q.push(i);

	vector<int> res;
	res.reserve(n);
	while(q.size())
	{
		int x = q.front();
		q.pop();
		res.emplace_back(x);
		for(auto y : adj[x])
			if(-- din[y] == 0)
				q.push(y);
	}

	vector<bitset<N>> f(n + 1);
	reverse(res.begin(), res.end());
	for(auto x : res)
	{
		f[x][x] = 1;
		for(auto y : adj[x])
			f[x] |= f[y];
	}

	for(int i = 1; i <= n; i ++) cout << f[i].count() << '\n';
}