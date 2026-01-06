#include<bits/stdc++.h>
using namespace std;
const int N = 2010;
int p[N];

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
	for(int i = 1; i <= n; i ++) p[i] = i;

	vector<array<int, 3>> edges(m);
	int res = 0;
	for(int i = 0; i < m; i ++)
	{
		int op, x, y, w;
		cin >> op >> x >> y >> w;
		if(op == 1)
		{
			res += w;
			x = find(x), y = find(y);
			p[x] = y;
		}
		else edges.push_back({w, x, y});
	}

	sort(edges.begin(), edges.end());
	for(auto [w, x, y] : edges)
	{
		x = find(x), y = find(y);
		if(x == y) continue;
		res += w;
		p[x] = y;
	}

	cout << res << '\n';
	return 0;
}