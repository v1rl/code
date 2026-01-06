#include<bits/stdc++.h>
using namespace std;
const int N = 6010;
int p[N];

int find(int x)
{
	if(x != p[x]) p[x] = find(p[x]);
	return p[x];
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int t;
	cin >> t;
	while(t --)
	{
		int n;
		cin >> n;
		for(int i = 1; i <= n; i ++) p[i] = i;
		vector<array<int, 3>> edges(n - 1);

		for(int i = 0; i < n - 1; i ++)
		{
			int x, y, w;
			cin >> x >> y >> w;
			edges[i] = {w, x, y};
		}
		sort(edges.begin(), edges.end());


		int res = 0;
		vector<int> siz(n + 1, 1);
		for(auto [w, x, y] : edges)
		{
			x = find(x), y = find(y);
			if(x == y) continue;
			res += (siz[x] * siz[y] - 1) * (w + 1);
			p[x] = y;
			siz[y] += siz[x];
		}

		cout << res << '\n';
	}
	return 0;
}