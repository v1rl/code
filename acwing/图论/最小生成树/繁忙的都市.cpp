#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
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
	for(int i = 0; i < m; i ++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		edges[i] = {w, x, y};
	}

	sort(edges.begin(), edges.end());
	int res = 0;
	for(auto [w, x, y] : edges)
	{
		x = find(x), y = find(y);
		if(x == y) continue;
		res = max(res, w);
		p[x] = y;
	}

	cout << n - 1 << ' ' << res << '\n';
	return 0;
}